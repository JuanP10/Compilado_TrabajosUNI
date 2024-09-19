import heapq

estado_objetivo = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 0]  # El 0 representa el espacio vacío
]

movimientos = [(0, 1), (0, -1), (1, 0), (-1, 0)]  # derecha, izquierda, abajo, arriba

def distancia_manhattan(estado, estado_objetivo):
    distancia = 0
    for i in range(3):
        for j in range(3):
            valor = estado[i][j]
            if valor != 0:
                for x in range(3):
                    for y in range(3):
                        if estado_objetivo[x][y] == valor:
                            distancia += abs(i - x) + abs(j - y)
    return distancia

def fichas_mal_colocadas(estado, estado_objetivo):
    mal_colocadas = 0
    for i in range(3):
        for j in range(3):
            if estado[i][j] != 0 and estado[i][j] != estado_objetivo[i][j]:
                mal_colocadas += 1
    return mal_colocadas

def encontrar_cero(estado):
    for i in range(3):
        for j in range(3):
            if estado[i][j] == 0:
                return i, j
    return -1

def generar_vecinos(estado):
    vecinos = []
    cero_x, cero_y = encontrar_cero(estado)
    for mov_x, mov_y in movimientos:
        nuevo_x, nuevo_y = cero_x + mov_x, cero_y + mov_y
        if 0 <= nuevo_x < 3 and 0 <= nuevo_y < 3:
            nuevo_estado = [fila[:] for fila in estado]
            nuevo_estado[cero_x][cero_y], nuevo_estado[nuevo_x][nuevo_y] = nuevo_estado[nuevo_x][nuevo_y], nuevo_estado[cero_x][cero_y]
            vecinos.append(nuevo_estado)
    return vecinos

def Asterisco(estado_inicial, estado_objetivo, heuristica):
    lista_abierta = []
    heapq.heappush(lista_abierta, (0, estado_inicial, 0, None))  # (f, estado actual, g, camino anterior)
    conjunto_cerrado = set()

    while lista_abierta:
        f, estado_actual, g, camino = heapq.heappop(lista_abierta)

        if estado_actual == estado_objetivo:
            return g, reconstruir_camino(camino)  # Se ha alcanzado el estado objetivo

        # Convertir el estado actual en una tupla para poder usarlo en el set
        tupla_estado = tuple(tuple(fila) for fila in estado_actual)
        if tupla_estado in conjunto_cerrado:
            continue

        conjunto_cerrado.add(tupla_estado)

        # Generar todos los estados vecinos
        for vecino in generar_vecinos(estado_actual):
            nuevo_g = g + 1  # El costo del nuevo estado es g + 1
            h = heuristica(vecino, estado_objetivo)  # Usar la heurística seleccionada
            nuevo_f = nuevo_g + h  # f = g + h
            heapq.heappush(lista_abierta, (nuevo_f, vecino, nuevo_g, (camino, vecino)))

    return None  # No se encontró solución

def primero_el_mejor(estado_inicial, estado_objetivo, heuristica):
    lista_abierta = []
    heapq.heappush(lista_abierta, (heuristica(estado_inicial, estado_objetivo), estado_inicial, 0, None))
    conjunto_cerrado = set()
    nodos_explorados = 0

    while lista_abierta:
        h, estado_actual, g, camino = heapq.heappop(lista_abierta)
        nodos_explorados += 1

        if estado_actual == estado_objetivo:
            return g, reconstruir_camino(camino), nodos_explorados

        tupla_estado = tuple(tuple(fila) for fila in estado_actual)
        if tupla_estado in conjunto_cerrado:
            continue

        conjunto_cerrado.add(tupla_estado)

        for vecino in generar_vecinos(estado_actual):
            nuevo_g = g + 1
            h = heuristica(vecino, estado_objetivo)
            heapq.heappush(lista_abierta, (h, vecino, nuevo_g, (camino, vecino)))

    return None, None, nodos_explorados

def reconstruir_camino(camino):
    if camino is None:
        return []
    camino_actual = []
    while camino:
        camino_actual.append(camino[1])  # Añadir el estado al camino
        camino = camino[0]  # Retroceder al estado anterior
    return camino_actual[::-1]  # Invertir el camino para mostrar del inicial al final


def imprimir_camino(camino):
    if not camino:
        print("No se encontró solución.")
        return

    for estado in camino:
        for fila in estado:
            print(fila)
        print("------")


# Estado inicial
estado_inicial = [
    [2, 4, 3],
    [1, 6, 8],
    [7, 5, 0]
]

# Ejecutar A* con distancia Manhattan
g_asterisco, camino_final_asterisco = Asterisco(estado_inicial, estado_objetivo, distancia_manhattan)
print(f"A* con distancia Manhattan: {g_asterisco} movimientos.")
imprimir_camino(camino_final_asterisco)

# Ejecutar Primero el Mejor con distancia Manhattan
g_primero_mejor, camino_final_primero_mejor, nodos_explorados = primero_el_mejor(estado_inicial, estado_objetivo, distancia_manhattan)
print(f"Primero el Mejor con distancia Manhattan: {g_primero_mejor} movimientos.")
imprimir_camino(camino_final_primero_mejor)

# Ejecutar A* con fichas mal colocadas
g_asterisco, camino_final_asterisco = Asterisco(estado_inicial, estado_objetivo, fichas_mal_colocadas)
print(f"A* con fichas mal colocadas: {g_asterisco} movimientos.")
imprimir_camino(camino_final_asterisco)

# Ejecutar Primero el Mejor con fichas mal colocadas
g_primero_mejor, camino_final_primero_mejor, nodos_explorados = primero_el_mejor(estado_inicial, estado_objetivo, fichas_mal_colocadas)
print(f"Primero el Mejor con fichas mal colocadas: {g_primero_mejor} movimientos.")
imprimir_camino(camino_final_primero_mejor)
