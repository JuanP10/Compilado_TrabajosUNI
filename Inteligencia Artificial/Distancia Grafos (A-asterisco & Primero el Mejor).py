import heapq

# Definición del grafo con distancias entre nodos
graph = {
    'Monteria': {'Sincelejo': 70},
    'Sincelejo': {'Monteria': 70, 'Plato': 25},
    'Plato': {'Sincelejo': 25, 'Barranquilla': 80},
    'Barranquilla': {'Plato': 80, 'Santa Marta': 80, 'Cartagena': 90},
    'Santa Marta': {'Barranquilla': 80, 'Riohacha': 70},
    'Riohacha': {'Santa Marta': 70, 'Uribia': 50, 'San Juan del Cesar': 30},
    'San Juan del Cesar': {'Riohacha': 30, 'Aguachica': 75},
    'Aguachica': {'San Juan del Cesar': 75, 'El Banco': 25},
    'El Banco': {'Aguachica': 25, 'Plato': 60},
    'Uribia': {}
}

# Heurísticas (h(n))
heuristics = {
    'Uribia': 0,
    'Riohacha': 10,
    'San Juan del Cesar': 18,
    'Santa Marta': 50,
    'El Banco': 120,
    'Barranquilla': 100,
    'Aguachica': 210,
    'Plato': 280,
    'Sincelejo': 350,
    'Cartagena': 355,
    'Monteria': 450
}

# Algoritmo A*
def astar_search(start, goal):
    open_list = []
    heapq.heappush(open_list, (heuristics[start], 0, start, []))  # (f(n), g(n), node, path)
    closed_list = set()

    while open_list:
        _, g, current_node, path = heapq.heappop(open_list)
        
        if current_node in closed_list:
            continue
        
        path = path + [current_node]

        # Si encontramos el nodo objetivo
        if current_node == goal:
            return path, g

        closed_list.add(current_node)

        for neighbor, cost in graph[current_node].items():
            if neighbor not in closed_list:
                new_g = g + cost
                f = new_g + heuristics[neighbor]
                heapq.heappush(open_list, (f, new_g, neighbor, path))
    
    return None, float('inf')

# Algoritmo Primero el Mejor
def best_first_search(start, goal):
    open_list = []
    heapq.heappush(open_list, (heuristics[start], start, []))  # (h(n), node, path)
    closed_list = set()

    while open_list:
        _, current_node, path = heapq.heappop(open_list)

        if current_node in closed_list:
            continue

        path = path + [current_node]

        # Si encontramos el nodo objetivo
        if current_node == goal:
            return path

        closed_list.add(current_node)

        for neighbor in graph[current_node]:
            if neighbor not in closed_list:
                heapq.heappush(open_list, (heuristics[neighbor], neighbor, path))
    
    return None

# Ejecutar A* y Primero el Mejor
start_city = 'Monteria'
goal_city = 'Uribia'

# Algoritmo A*
astar_path, astar_cost = astar_search(start_city, goal_city)
print("Ruta A*: ", astar_path)
print("Costo A*: ", astar_cost)

# Algoritmo Primero el Mejor
best_first_path = best_first_search(start_city, goal_city)
print("Ruta Primero el Mejor: ", best_first_path)
print("Costo Primero el Mejor: ", )