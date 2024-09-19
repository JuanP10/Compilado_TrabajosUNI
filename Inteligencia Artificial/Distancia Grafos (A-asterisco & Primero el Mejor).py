import heapq
import time

# Definición del grafo con las distancias correctas
grafo = {
    'Monteria': {'Sincelejo': 70, 'Cartagena': 90},
    'Sincelejo': {'El Banco': 75, 'Monteria': 70, 'Cartagena': 80},
    'Cartagena': {'Sincelejo': 80, 'Monteria': 90, 'Barranquilla': 90},
    'El Banco': {'Aguachica': 25, 'Plato': 25, 'Sincelejo': 75, 'Santa Marta': 70},
    'Aguachica': {'San Juan del Cesar': 75, 'El Banco': 25},
    'Plato': {'Santa Marta': 60, 'Barranquilla': 70, 'El Banco': 25},
    'Barranquilla': {'Cartagena': 90, 'Plato': 70, 'Santa Marta': 80},
    'Santa Marta': {'Riohacha': 70, 'Plato': 60, 'Barranquilla': 80, 'El Banco': 70},
    'Riohacha': {'Uribia': 50, 'Santa Marta': 70, 'San Juan del Cesar': 30},
    'San Juan del Cesar': {'Riohacha': 30, 'Aguachica': 75, 'Uribia': 35},
    'Uribia': {}
}

# Heurísticas (h(n)) para A*
heuristicas = {
    'Monteria': 450,
    'Sincelejo': 350,
    'Cartagena': 355,
    'El Banco': 120,
    'Aguachica': 210,
    'Plato': 280,
    'Barranquilla': 100,
    'Santa Marta': 50,
    'Riohacha': 10,
    'San Juan del Cesar': 18,
    'Uribia': 0
}

# Algoritmo A* (A-asterisco)
def busqueda_a_estrella(inicio, objetivo):
    lista_abierta = []
    heapq.heappush(lista_abierta, (heuristicas[inicio], 0, inicio, []))  # (f(n), g(n), nodo, camino)
    lista_cerrada = set()
    nodos_visitados = 0  # Para contar los nodos que se visitan

    while lista_abierta:
        _, costo_acumulado, nodo_actual, camino = heapq.heappop(lista_abierta)
        nodos_visitados += 1
        
        if nodo_actual in lista_cerrada:
            continue
        
        camino = camino + [nodo_actual]

        # Si encontramos el nodo objetivo
        if nodo_actual == objetivo:
            return camino, costo_acumulado, nodos_visitados

        lista_cerrada.add(nodo_actual)

        for vecino, costo in grafo[nodo_actual].items():
            if vecino not in lista_cerrada:
                nuevo_costo_acumulado = costo_acumulado + costo
                costo_total = nuevo_costo_acumulado + heuristicas[vecino]
                heapq.heappush(lista_abierta, (costo_total, nuevo_costo_acumulado, vecino, camino))
    
    return None, float('inf'), nodos_visitados

# Algoritmo Primero el Mejor
def busqueda_primero_mejor(inicio, objetivo):
    lista_abierta = []
    heapq.heappush(lista_abierta, (heuristicas[inicio], inicio, 0, []))  # (h(n), nodo, costo_acumulado, camino)
    lista_cerrada = set()
    nodos_visitados = 0  # Para contar los nodos que se visitan

    while lista_abierta:
        _, nodo_actual, costo_acumulado, camino = heapq.heappop(lista_abierta)
        nodos_visitados += 1

        if nodo_actual in lista_cerrada:
            continue

        camino = camino + [nodo_actual]

        # Si encontramos el nodo objetivo
        if nodo_actual == objetivo:
            return camino, costo_acumulado, nodos_visitados

        lista_cerrada.add(nodo_actual)

        for vecino, costo in grafo[nodo_actual].items():
            if vecino not in lista_cerrada:
                nuevo_costo_acumulado = costo_acumulado + costo
                heapq.heappush(lista_abierta, (heuristicas[vecino], vecino, nuevo_costo_acumulado, camino))
    
    return None, float('inf'), nodos_visitados

# Ejecutar A* y Primero el Mejor
ciudad_inicio = 'Monteria'
ciudad_objetivo = 'Uribia'

# Ejecutar A*
start_time_a_star = time.time()
camino_a_estrella, costo_a_estrella, nodos_a_estrella = busqueda_a_estrella(ciudad_inicio, ciudad_objetivo)
time_a_star = time.time() - start_time_a_star

# Ejecutar Primero el Mejor
start_time_pm = time.time()
camino_primero_mejor, costo_primero_mejor, nodos_primero_mejor = busqueda_primero_mejor(ciudad_inicio, ciudad_objetivo)
time_pm = time.time() - start_time_pm

# Imprimir los resultados
print("=== Resultados A* ===")
print("Ruta: ", camino_a_estrella)
print("Costo (distancia acumulada): ", costo_a_estrella)
print("Nodos visitados: ", nodos_a_estrella)
print("Tiempo de ejecución: {:.6f} segundos".format(time_a_star))

print("\n=== Resultados Primero el Mejor ===")
print("Ruta: ", camino_primero_mejor)
print("Costo (distancia acumulada): ", costo_primero_mejor)
print("Nodos visitados: ", nodos_primero_mejor)
print("Tiempo de ejecución: {:.6f} segundos".format(time_pm))

# Comparación
if costo_a_estrella < costo_primero_mejor:
    print("\nA* encontró una ruta más corta.")
elif costo_a_estrella > costo_primero_mejor:
    print("\nPrimero el Mejor encontró una ruta más corta.")
else:
    print("\nAmbos algoritmos encontraron rutas con el mismo costo.")

if nodos_a_estrella < nodos_primero_mejor:
    print("A* fue más eficiente (menos nodos visitados).")
elif nodos_a_estrella > nodos_primero_mejor:
    print("Primero el Mejor fue más eficiente (menos nodos visitados).")
else:
    print("Ambos algoritmos visitaron el mismo número de nodos.")