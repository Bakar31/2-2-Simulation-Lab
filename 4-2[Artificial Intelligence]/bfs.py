def BFS(graph, start):
    visited = set()
    queue = [start]

    while queue:
        node = queue.pop(0)

        if node in visited:
            continue

        visited.add(node)
        print(node)

        for neighbor in graph[node]:
            queue.append(neighbor)

graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': [],
    'D': ['G', 'F'],
    'E': ['F', 'G'],
    'F': [],
    'G': ['A', 'B']
}

BFS(graph, 'A')
