from SA import SimAnneal
import timeit
import csv
import matplotlib.pyplot as plt

# esta funcion procesa el modelo estatico del CSV que se compone de
# capacidad, valor, peso
# omitimos la primera iteracion porque solo son los nombres

def read_data(path):
    with open(path, newline='') as csvfile:
        valores = []
        pesos = []
        spamreader = list(csv.reader(csvfile, delimiter=';'))
        # aca extraemos ese dato "aislado" que es la cap maxima de la mochila
        cap_max = int(spamreader[1][0])
        # luego añadimos a lista los otros dos valores de valor/peso
        valores.append(int(spamreader[1][1]))
        pesos.append(int(spamreader[1][2]))
        # y aca empezamos a recorrer todo excluyendo las 2 primeras iteraciones
        for row in spamreader[2:]:
            valores.append(int(row[1]))
            pesos.append(int(row[2]))
        return (valores, pesos, cap_max)


if __name__ == "__main__":
    # PARAMETROS PRINCIPALES
    # TEMPERATURA INICIAL = T
    # TASA DE ENFRIAMIENTO = alpha
    # TEMPERATURA DE PARADA = stopping_T
    temperatura = 2000
    alpha = 0.97
    temperatura_limite = 0.001
    valores, pesos, cap_max = read_data("data.csv")

    end_times = []
    best_solutions = []
    nIters = []
    nEjecuciones = 1
    
    for i in range(nEjecuciones):
        print('Ejecución No. ', (i + 1))
        start_time = timeit.default_timer()
        sa = SimAnneal(cap_max, valores, pesos, temperatura, alpha, temperatura_limite, stopping_iter=500)
        best_solution, nIter, solucion, total_iterations = sa.anneal()
        stop_time = timeit.default_timer()
        end_time = stop_time - start_time
        print("running_time: ",format(end_time, '.8f'))
        end_times.append(end_time)
        best_solutions.append(best_solution)
        nIters.append(nIter)
        print('Encontró la solución en la iteración: %d' % nIter)
        print("Num total de iteraciones: ", total_iterations)
        print("         Datos....")
        valor, peso = sa.dame_datos(solucion)
        print("         Valor: ", valor)
        print("         Peso: ", peso)
        print("         Knapsack: ", solucion)
        sa.visualize()