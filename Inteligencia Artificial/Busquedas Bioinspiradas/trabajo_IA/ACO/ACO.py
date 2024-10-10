import random
import time
import csv
import matplotlib.pyplot as plt

class AntColony:
    def __init__(self, values, weights, max_cap, num_ants, num_generations, alpha, beta, evaporation_rate):
        self.max_capacity = max_cap
        self.values = values
        self.weights = weights
        self.iteration = 1
        self.convergence = []
        self.num_ants = num_ants
        self.num_generations = num_generations
        self.alpha = alpha
        self.beta = beta
        self.evaporation_rate = evaporation_rate
        self.pheromone_trails = [1.0 for _ in range(len(self.values))]

    def select_item(self, available_items):
        probabilities = []
        total = sum(self.pheromone_trails[i] ** self.alpha * (self.values[i] / self.weights[i]) ** self.beta for i in available_items)

        for i in available_items:
            prob = (self.pheromone_trails[i] ** self.alpha * (self.values[i] / self.weights[i]) ** self.beta) / total
            probabilities.append(prob)

        return random.choices(available_items, probabilities)[0]

    def construct_solution(self):
        solution = [0] * len(self.values)
        available_items = list(range(len(self.values)))
        weight = 0

        while available_items:
            item = self.select_item(available_items)
            if weight + self.weights[item] <= self.max_capacity:
                solution[item] = 1
                weight += self.weights[item]
            available_items.remove(item)

        return solution

    def update_pheromones(self, best_solution):
        for i in range(len(self.pheromone_trails)):
            self.pheromone_trails[i] = (1 - self.evaporation_rate) * self.pheromone_trails[i]

        for i in range(len(best_solution)):
            if best_solution[i]:
                valor, temp = self.evaluate(best_solution)
                self.pheromone_trails[i] += valor

    def evaluate(self, packing):
        # packing is the possible solution
        # total value and size of a specified packing
        value = 0.0     # total value of packing
        weight = 0.0    # total weight of packing
        n = len(packing)
        for i in range(n):
            if packing[i] == 1:
                value += self.values[i]
                weight += self.weights[i]
        if weight > self.max_capacity:  # too big to fit in knapsack
            value = 0.0
        return (value, weight)

    def visualize(self):
        plt.plot(self.convergence)
        plt.ylabel("Value")
        plt.xlabel("Generation")
        plt.show()

    def run(self):
        best_solution = None
        best_value = 0

        for generation in range(self.num_generations):
            solutions = [self.construct_solution() for _ in range(self.num_ants)]

            for solution in solutions:
                value, temp = self.evaluate(solution)
                if value > best_value:
                    best_solution = solution
                    best_value = value
                    best_iteration = self.num_ants * generation

            self.update_pheromones(best_solution)
            self.convergence.append(best_value)

        total_iterations = self.num_ants * self.num_generations
        return best_solution, best_iteration, total_iterations