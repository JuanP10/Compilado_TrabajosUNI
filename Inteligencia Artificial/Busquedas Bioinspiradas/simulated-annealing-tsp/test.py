from anneal import SimAnneal
import matplotlib.pyplot as plt
import random
import time
import timeit
import statistics
import numpy as np, pandas as pd



def read_coords(path):
    coords = []
    with open(path, "r") as f:
        for line in f.readlines():
            line = [float(x.replace("\n", "")) for x in line.split(" ")]
            coords.append(line)
    return coords


def generate_random_coords(num_nodes):
    return [[random.uniform(-1000, 1000), random.uniform(-1000, 1000)] for i in range(num_nodes)]


if __name__ == "__main__":
    coords = read_coords("coord.txt")  # generate_random_coords(100)
    
    
    
    end_times = []
    best_solutions = []
    nIters = []
    nejecuciones = 1
    
    for i in range(nejecuciones):
        print('Ejecución No. ', i)
        start_time = timeit.default_timer() 
        sa = SimAnneal(coords, T = 20, stopping_iter=6000, alpha=0.9992) #0.9992
        print(sa.T)
        best_solution, nIter = sa.anneal()
        stop_time = timeit.default_timer()
        end_time = stop_time - start_time
        print("running_time: ",format(end_time, '.8f'))
        end_times.append(end_time)
        best_solutions.append(best_solution)
        nIters.append(nIter)
        print('Encontró la solución en la iteración: %d' % nIter)
        
        
    print("Costo total promedio =", round(statistics.mean(best_solutions), 2))
    varianza = statistics.variance(best_solutions)
    print("Varianza: ", round(varianza,2))
    print("Mejor solución encontrada en %d iteraciones: %f" % (nejecuciones, round(min(best_solutions), 2)))

    df = pd.DataFrame(best_solutions, columns =['Distancia_total'], dtype = float)
    df['Time'] = end_times
    df['Iteracion'] = nIters
    print(df.head())
    df.to_excel('resultado2.xlsx')
        
    sa.visualize_routes()
    sa.plot_learning()
