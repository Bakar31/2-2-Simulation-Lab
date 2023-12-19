from flask import Flask, render_template, Response
from flask_socketio import SocketIO
import cv2
import torch
from numpy import random

from models.experimental import attempt_load
from utils.general import non_max_suppression,scale_coords, xyxy2xywh
from utils.plots import plot_one_box

app = Flask(__name__)
app.config['SECRET_KEY'] = 'secret!'
socketio = SocketIO(app)

def detect_objects():
    weights = './yolov7.pt'
    device = 'cpu'
    source = 0
    conf_thres = 0.5
    iou_thres = 0.45

    video_capture = cv2.VideoCapture(source)
    model = attempt_load(weights, map_location=device)

    names = model.module.names if hasattr(model, 'module') else model.names
    colors = [[random.randint(0, 255) for _ in range(3)] for _ in names]

    while True:
        ret, frame = video_capture.read()
        if not ret or frame is None:
            break

        # frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
        resized_frame = cv2.resize(frame, (640, 480))

        if frame.shape[2] != 3:
            continue 

        img = torch.from_numpy(frame).float() / 255.0  # Normalize image
        img = img.permute(2, 0, 1).unsqueeze(0)  # Channels-first format for PyTorch

        with torch.no_grad():
            pred = model(img)[0]

        pred = non_max_suppression(pred, conf_thres, iou_thres)

        s = ''
        for i, det in enumerate(pred):
            gn = torch.tensor(frame.shape)[[1, 0, 1, 0]]  # normalization gain whwh
            if len(det):
                det[:, :4] = scale_coords(img.shape[2:], det[:, :4], frame.shape).round()

                # Print results
                for c in det[:, -1].unique():
                    n = (det[:, -1] == c).sum()  # detections per class
                    s += f"{n} {names[int(c)]}{'s' * (n > 1)}, "  # add to string

                for *xyxy, conf, cls in reversed(det):
                    xywh = (xyxy2xywh(torch.tensor(xyxy).view(1, 4)) / gn).view(-1).tolist()
                    label = f'{names[int(cls)]} {conf:.2f}'
                    plot_one_box(xyxy, frame, label=label, color=colors[int(cls)], line_thickness=1)

        text_output = s 
        socketio.emit('text_output', {'text': text_output}, namespace='/')
        
        ret, jpeg = cv2.imencode('.jpg', frame)
        yield (b'--frame\r\n'
               b'Content-Type: image/jpeg\r\n\r\n' + jpeg.tobytes() + b'\r\n')


@app.route('/')
def index():
    return render_template('index.html') 

@app.route('/detect_objects')
def detect_objects_route():
    detect_objects()  # Perform object detection
    return render_template('detect_objects.html')  # Render your object detection page here

@app.route('/video_feed')
def video_feed():
    return Response(detect_objects(), mimetype='multipart/x-mixed-replace; boundary=frame')

@socketio.on('connect', namespace='/')
def test_connect():
    print('Client connected') 

@socketio.on('disconnect', namespace='/')
def test_disconnect():
    print('Client disconnected') 

if __name__ == '__main__':
    socketio.run(app, debug=True)
