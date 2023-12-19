class Node:
    def __init__(self, name):
        "Defines a class Node to represent nodes in the graph."
        self.name = name
        self.g = float('inf')
        self.h = 0 
        self.f = 0
        self.parent = None

def heuristic(node, goal):
    '''
    Defines the heuristic function (heuristic) to estimate the cost from a given node to the goal node. 
    It calculates the Manhattan distance between two points in a grid-like environment.'''
    return abs(node[0] - goal[0]) + abs(node[1] - goal[1])

def reconstructPath(node):
    '''
    Constructs the path by tracing backward from the goal node to the start node based on the parent attribute of each node.'''
    path = []
    while node is not None:
        path.append(node)
        node = node.parent
    path.reverse()
    return path

def A_star(graph, start_name, goal_name):
    nodes = {name: Node(name) for name in graph}

    start = nodes[start_name]
    goal = nodes[goal_name]

    start.g = 0
    start.h = heuristic((0, 0), (2, 2))
    start.f = start.g + start.h

    open_set = [start]

    while open_set:
        open_set.sort(key=lambda x: x.f)
        current = open_set.pop(0)

        if current == goal:
            return reconstructPath(current)

        for neighbor_name, cost in graph[current.name].items():
            neighbor = nodes[neighbor_name]
            tentative_g = current.g + cost

            if tentative_g < neighbor.g:
                neighbor.parent = current
                neighbor.g = tentative_g
                neighbor.h = heuristic((0, 0), (2, 2))
                neighbor.f = neighbor.g + neighbor.h

                if neighbor not in open_set:
                    open_set.append(neighbor)

    return None 

graph = {
    'A': {'B': 1, 'C': 2},
    'B': {'D': 1, 'E': 3},
    'C': {},
    'D': {'A':2},
    'E': {'F': 2},
    'F': {'B':3}
}

start_node = 'A'
goal_node = 'F'

path = A_star(graph, start_node, goal_node)
print([node.name for node in path]) if path else print("No path found.")
