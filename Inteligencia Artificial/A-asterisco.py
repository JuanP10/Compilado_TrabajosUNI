
# Busqueda Sin Información (A-asterisco)

import heapq

class Cell(object):
    def __init__(self, x, y, reachable):
        self.reachable = reachable  # Indica si la celda es alcanzable
        self.x = x
        self.y = y
        self.parent = None          # Padre de la celda
        self.g = 0                  # Costo de llegar a la celda
        self.h = 0                  # Heurística de la celda
        self.f = 0                  # Costo total de la celda

class AStar(object):
    def __init__(self):
        self.opened = []
        heapq.heapify(self.opened)
        self.closed = set()
        self.cells = []
        
        self.grid_height = 6   # Altura del laberinto
        self.grid_width = 6    # Ancho del laberinto

    def init_grid(self):
        walls = ((0, 3), (0, 4), (1, 5), (2, 0), (2, 2), 
                 (2, 3), (2, 4), (3, 0), (3, 2), (3, 3), (4, 0), (5,0), (5,1), (5,2), (5,4))  # Paredes del laberinto
        for x in range(self.grid_width):
            for y in range(self.grid_height):
                if (x, y) in walls:
                    reachable = False
                else:
                    reachable = True
                self.cells.append(Cell(x, y, reachable))
        self.start = self.get_cell(0, 0)   # Coordenada Inicio 
        self.end = self.get_cell(5, 5)     # Coordenada Objetivo

    def get_heuristic(self, cell):
        return 10 * (abs(cell.x - self.end.x) + abs(cell.y - self.end.y))  # Heurística de Manhattan

    def get_cell(self, x, y): 
        return self.cells[x * self.grid_height + y]  # Obtener celda por coordenadas

    def get_adjacent_cells(self, cell):  # Obtener celdas vecinas
        cells = []
        if cell.x < self.grid_width-1:                          # Derecha 
            cells.append(self.get_cell(cell.x+1, cell.y))       
        if cell.y > 0:                                          # Arriba
            cells.append(self.get_cell(cell.x, cell.y-1))
        if cell.x > 0:                                         # Izquierda
            cells.append(self.get_cell(cell.x-1, cell.y))
        if cell.y < self.grid_height-1:                          # Abajo
            cells.append(self.get_cell(cell.x, cell.y+1))

        return cells

    def print_grid_with_path(self, path):
        # Imprimir el laberinto con el camino marcado
        grid = [['0'] * self.grid_height for _ in range(self.grid_width)]
        for x in range(self.grid_width):
            for y in range(self.grid_height):
                if (x, y) in path:
                    grid[x][y] = '*'
                elif not self.get_cell(x, y).reachable:  
                    grid[x][y] = '1'

        for row in grid:
            print(' '.join(row))
        print()  # Línea en blanco para separar los pasos

    def display_path(self):
        cell = self.end
        cell_path = []
        cell_path.append((cell.x, cell.y))
        while cell.parent is not self.start:
            cell = cell.parent
            cell_path.append((cell.x, cell.y))
        cell_path.append((self.start.x, self.start.y))
        cell_path.reverse()

        # Mostrar el camino
        print("Camino encontrado:")
        self.print_grid_with_path(cell_path)
        print("Coordenadas del camino:")
        for coord in cell_path:
            print(f"({coord[0]}, {coord[1]}) con costo g: {self.get_cell(coord[0], coord[1]).g}")
        print()  # Línea en blanco para separar la salida

    def compare(self, cell1, cell2):  # Comparar costos de celdas
        if cell1.f < cell2.f:     
            return -1
        elif cell1.f > cell2.f:
            return 1
        return 0
    
    def update_cell(self, adj, cell):   # Actualizar celda
        adj.g = cell.g + 10
        adj.h = self.get_heuristic(adj)
        adj.parent = cell
        adj.f = adj.h + adj.g
 
    def process(self):  
        count = 0
        heapq.heappush(self.opened, (self.start.f, count, self.start))
        path_coords = []

        while len(self.opened):
            f, c, cell = heapq.heappop(self.opened)
            self.closed.add(cell)
            path_coords.append((cell.x, cell.y))
            print ("Paso numero:"   + str(c))
            self.print_grid_with_path(path_coords)

            if cell is self.end:
                self.display_path()
                break
            adj_cells = self.get_adjacent_cells(cell)
            for adj_cell in adj_cells:
                if adj_cell.reachable and adj_cell not in self.closed:
                    if (adj_cell.f, adj_cell) in self.opened:
                        if adj_cell.g > cell.g + 10:
                            self.update_cell(adj_cell, cell)
                    else:
                        self.update_cell(adj_cell, cell)
                        count = count + 1
                        heapq.heappush(self.opened, (adj_cell.f, count, adj_cell))

a = AStar()
a.init_grid()
a.process()
