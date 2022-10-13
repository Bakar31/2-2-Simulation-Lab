// include the library code:
#define USE_ARDUINO_INTERRUPTS true 
#include <LiquidCrystal.h>   // Set-up low-level interrupts for most acurate BPM math.
#include <PulseSensorPlayground.h> 
#include "SoftwareSerial.h"
#define LM35 A0

float lm_value;
float tempc;
float tempf;
int PulseWire = A1;  
int Signal;                // holds the incoming raw data. Signal value can range from 0-1024
int Threshold = 545;  // Determine which Signal to "count as a beat", and which to ingore.
const int rs = 12, en = 11, d4 = 9, d5 = 8, d6 = 7, d7 = 6;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
String cmd = "";
int row_excel = 0;
PulseSensorPlayground pulseSensor;

SoftwareSerial mySerial(2, 3);

void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);
  Serial.println("Initializing...");
  delay(1000);
  Serial.println("CLEARDATA");
  Serial.println("LABEL, Date, Time, Temparature , Heart Rate");
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

  mySerial.println("AT");                 // Sends an ATTENTION command, reply should be OK
  updateSerial();
  mySerial.println("AT+CMGF=1");          // Configuration for sending SMS
  updateSerial();
  mySerial.println("AT+CNMI=1,2,0,0,0");  // Configuration for receiving SMS
  updateSerial();

  pulseSensor.analogInput(PulseWire); 
  pulseSensor.setThreshold(Threshold);  
   // Double-check the "pulseSensor" object was created and "began" seeing a signal. 
   if (pulseSensor.begin()) {
    Serial.println("We created a pulseSensor Object !");  //This prints one time at Arduino power-up,  or on Arduino reset.  
  }
  
}

void loop() {
  updateSerial();
  row_excel++;
  lm_value = analogRead(LM35);
  tempc = (lm_value * 500) / 1023;
  tempf = (tempc*1.8)+32;

  Serial.print("DATA, DATE, TIME, ");
  Serial.print(tempf);
  Serial.print(" ,");

  int BPM = pulseSensor.getBeatsPerMinute();
  if (pulseSensor.sawStartOfBeat()) {                          // Print phrase "BPM: " 
  Serial.print(BPM); 
  Serial.print(" ,");                       // Print the value inside of myBPM. 
  }

  else{
    BPM = 0;
  }

  if ((tempf > 150) || (BPM > 150))
  {
    sendSMS();
  }

  
  Serial.println(" ");

  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);
  lcd.print("Temp:"); 
  lcd.print(tempf);
  lcd.setCursor(10, 0); 
  lcd.print("F"); 

  lcd.setCursor(0, 1);
  lcd.print("BPM:"); 
  lcd.setCursor(4, 1);
  lcd.print(BPM);
  delay(1000);
}


void updateSerial()
{
  delay(500);
  while (Serial.available()) 
  {

    cmd+=(char)Serial.read();
 
    if(cmd!=""){
      cmd.trim();  // Remove added LF in transmit
      if (cmd.equals("S")) {
        sendSMS();
      } else {
        mySerial.print(cmd);
        mySerial.println("");
      }
    }
  }
  
  while(mySerial.available()) 
  {
    Serial.write(mySerial.read());//Forward what Software Serial received to Serial Port
  }
}

void sendSMS(){
  mySerial.println("AT+CMGF=1");
  delay(500);
  mySerial.println("AT+CMGS=\"+8801941729495\"\r");
  delay(500);
  mySerial.print("The patient is in critical condition. Check Now!");
  delay(500);
  mySerial.write(26);
}
