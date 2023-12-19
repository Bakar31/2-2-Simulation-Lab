def DFS(graph, start):
    visited = set()
    stack = [start]

    while stack:
        node = stack.pop()

        if node in visited:
            continue

        visited.add(node)
        print(node)

        for neighbor in graph[node]:
            stack.append(neighbor)

graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': [],
    'D': ['G', 'F'],
    'E': ['F', 'G'],
    'F': [],
    'G': ['A', 'B']
}

DFS(graph, 'A')