import heapq

class Cell:
    def __init__(self, x, y, reachable):
        self.x = x
        self.y = y
        self.reachable = reachable  # Si la celda es accesible
        self.h = 0  # Valor heurístico
        self.parent = None  # Para rastrear el camino

    def __lt__(self, other):
        return self.h < other.h

    def __eq__(self, other):
        return self.x == other.x and self.y == other.y

class BestFirstSearch:
    def __init__(self):
        self.opened = []
        heapq.heapify(self.opened)  # Inicializamos la lista de celdas abiertas como un heap (cola de prioridad)
        self.closed = set()  # Celdas ya visitadas
        self.cells = []
        self.grid_height = 6
        self.grid_width = 6

    def init_grid(self):
        walls = ((0, 3), (0, 4), (1, 5), (2, 0), (2, 2), 
                 (2, 3), (2, 4), (3, 0), (3, 2), (3, 3), (4, 0), (5,0), (5,1), (5,2), (5,4))
        for x in range(self.grid_width):
            for y in range(self.grid_height):
                reachable = not (x, y) in walls
                self.cells.append(Cell(x, y, reachable))
        self.start = self.get_cell(0, 0)
        self.end = self.get_cell(5, 5)

    def get_heuristic(self, cell):
        # Usamos la distancia de Manhattan como heurística
        return abs(cell.x - self.end.x) + abs(cell.y - self.end.y)

    def get_cell(self, x, y):
        return self.cells[x * self.grid_height + y]

    def get_adjacent_cells(self, cell):
        cells = []
        if cell.x < self.grid_width - 1:
            cells.append(self.get_cell(cell.x + 1, cell.y))
        if cell.y > 0:
            cells.append(self.get_cell(cell.x, cell.y - 1))
        if cell.x > 0:
            cells.append(self.get_cell(cell.x - 1, cell.y))
        if cell.y < self.grid_height - 1:
            cells.append(self.get_cell(cell.x, cell.y + 1))
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
        path = []
        while cell is not None:
            path.append((cell.x, cell.y))
            cell = cell.parent
        path.reverse()
        
        # Mostrar el camino
        print("Camino encontrado:")
        self.print_grid_with_path(path)
        print("Coordenadas del camino:")
        for coord in path:
            print(f"({coord[0]}, {coord[1]})")
        print()  # Línea en blanco para separar la salida

    def search(self):
        # Añadimos la celda inicial a la lista de abiertas
        heapq.heappush(self.opened, (self.get_heuristic(self.start), self.start))
        
        while self.opened:
            # Tomamos la celda con la menor heurística (más prometedora)
            _, cell = heapq.heappop(self.opened)
            
            # Si hemos llegado al objetivo, mostramos el camino
            if cell == self.end:
                self.display_path()
                return True

            # Añadimos la celda a la lista de cerradas
            self.closed.add(cell)
            
            # Expandimos las celdas adyacentes
            for adj_cell in self.get_adjacent_cells(cell):
                if adj_cell.reachable and adj_cell not in self.closed:
                    adj_cell.parent = cell
                    heapq.heappush(self.opened, (self.get_heuristic(adj_cell), adj_cell))
        
        print("No se encontró camino")
        return False

# Inicializamos la búsqueda
bfs = BestFirstSearch()
bfs.init_grid()
bfs.search()

