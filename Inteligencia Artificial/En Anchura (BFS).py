
#Busqueda con Información BFS en anchura

from collections import namedtuple 

Coord = namedtuple('Coord', ['x', 'y'])

Nfilas = 5
Ncolumnas = 5

# los 0 son caminos y los 1 son paredes

laberinto = [[0,0,0,1,1],
             [0,1,0,0,1],
             [0,1,0,1,1],
             [1,0,0,0,0],
             [1,0,1,1,0]
             ] 

def imprime_laberinto(laberinto, path):
    lab_copy = [row[:] for row in laberinto]
    for p in path:
        lab_copy[p.x][p.y] = '*'
    for row in lab_copy:
        print(' '.join(str(cell) for cell in row))
    print()  # línea en blanco para separar pasos

def devuelve_vecinos(pos):
    vecinos = []
    if pos.x > 0:
        vecinos.append(Coord(pos.x-1, pos.y))
    if pos.x < Nfilas-1:
        vecinos.append(Coord(pos.x+1, pos.y))
    if pos.y > 0:
        vecinos.append(Coord(pos.x, pos.y-1))
    if pos.y < Ncolumnas-1:
        vecinos.append(Coord(pos.x, pos.y+1))
    
    true_vecinos = []
    for p in vecinos : 
        if laberinto[p.x][p.y] == 0 :
           true_vecinos.append(p)

    return true_vecinos

def bfs_paths(pos_ini, goal):
    count = -1
    queue = [(pos_ini, [pos_ini])]
    while queue:
        (vertex, path) = queue.pop(0)
        count += 1
        print("Paso: ", count)
        imprime_laberinto(laberinto, path)  # imprime todos los caminos
          
        l = list(set(devuelve_vecinos(vertex)) - set(path))
        for next in l:
            if next.x == goal.x and next.y == goal.y:
                print("Camino encontrado: ")
                imprime_laberinto(laberinto, path + [next])  # imprime el camino final
                print(path + [next])
                return 1
            else:
                queue.append((next, path + [next]))
        
    return 0

pos_ini = Coord(x=0, y=0)
pos_meta = Coord(x=4, y=4)
print("En Anchura (BFS) solución: ")
if not (bfs_paths(pos_ini, pos_meta)):
   print('No encontró solución para el laberinto')
 
