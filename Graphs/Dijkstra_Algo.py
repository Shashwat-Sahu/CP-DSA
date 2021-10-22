graph = {
    'a': {'b': 3, 'c': 4, 'd': 7},
    'b': {'c': 1, 'f': 5},
    'c': {'f': 6, 'd': 2},
    'd': {'e': 3, 'g': 6},
    'e': {'g': 3, 'h': 4},
    'f': {'e': 1, 'h': 8},
    'g': {'h': 2},
    'h': {'g': 2}
}


def dijkstra(graph, start, end):
    minDistance = {}
    predecessor = {}
    unseenNodes = graph
    infinity = 999999999
    path = []

    for node in unseenNodes:
        minDistance[node] = infinity
    minDistance[start] = 0

    while unseenNodes:
        shortestNode = None

        for node in unseenNodes:
            if shortestNode is None or minDistance[node] < minDistance[shortestNode]:
                shortestNode = node

        path_option = graph[shortestNode].items()

        for childNode, weight in path_option:
            if weight + minDistance[shortestNode] < minDistance[childNode]:
                minDistance[childNode] = weight + minDistance[shortestNode]
                predecessor[childNode] = shortestNode
        unseenNodes.pop(shortestNode)

    currentNode = end

    while currentNode != start:
        try:
            path.insert(0, currentNode)
            currentNode = predecessor[currentNode]
        except KeyError:
            print("Not Reachable!")
            break

    path.insert(0, start)

    if minDistance[end] != infinity:
        print("Shortest Path:", minDistance[end])
        print("Path is", path)


dijkstra(graph, 'a', 'h')
