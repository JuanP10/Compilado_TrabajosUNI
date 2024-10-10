from ACO import AntColony
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
    num_ants = 100              # tamaño de la colonia
    num_generations = 20        # num de generaciones
    alpha = 0.5                 # influencia de feromonas
    beta = 0.5                  # influencia de heuristica
    evaporation_rate = 0.6      # tasa de evaporacion de la feromona

    valores, pesos, cap_max = read_data("data.csv")

    end_times = []
    best_solutions = []
    nIters = []
    nEjecuciones = 5
    
    for i in range(nEjecuciones):
        print('Ejecución No. ', (i + 1))
        start_time = timeit.default_timer()

        ant_colony = AntColony(valores, pesos, cap_max, num_ants, num_generations, alpha, beta, evaporation_rate)
        solucion, nIter, total_iterations = ant_colony.run()

        stop_time = timeit.default_timer()
        end_time = stop_time - start_time
        print("running_time: ",format(end_time, '.8f'))
        end_times.append(end_time)
        best_solutions.append(solucion)
        nIters.append(nIter)
        print('Encontró la solución en la iteración: %d' % nIter)
        print("Num total de iteraciones: ", total_iterations)
        print("         Datos....")
        valor, peso = ant_colony.evaluate(solucion)
        print("         Valor: ", valor)
        print("         Peso: ", peso)
        print("         Knapsack: ", solucion)
        ant_colony.visualize()