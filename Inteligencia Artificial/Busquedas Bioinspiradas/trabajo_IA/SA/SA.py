import math
import random
import matplotlib.pyplot as plt
import numpy as np

class SimAnneal(object):
    def __init__(self, max_cap, values, weights, T=-1, alpha=-1, stopping_T=-1, stopping_iter=-1):
        self.max_capacity = max_cap
        self.values = values
        self.weights = weights

        self.N = len(values)
        self.T = math.sqrt(self.N) if T == -1 else T
        self.T_save = self.T  # save inital T to reset if batch annealing is used
        self.alpha = 0.995 if alpha == -1 else alpha
        self.stopping_temperature = 1e-8 if stopping_T == -1 else stopping_T
        self.stopping_iter = 10000 if stopping_iter == -1 else stopping_iter
        self.iteration = 1

        self.best_solution = None
        self.best_fitness = float("Inf")
        self.cur_fitness = 0
        self.fitness_list = []

    def evaluate(self, packing):
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
        return value

    def dame_datos(self, packing):
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
        return value, weight

    def initial_solution(self):
        """
        Greedy algorithm to get an initial solution (closest-neighbour).
        THIS IS AN EMPTY BAG, ALL IN 0
        """
        current = [0 for x in range(self.N)]
        cur_fit = self.evaluate(current)
        self.best_fitness = cur_fit
        self.best_solution = current
        self.fitness_list.append(cur_fit)
        return current, cur_fit

    def One_Flip_Neighbourhood(self, packing):
        neighbourhood = []
        for i in range(0, self.N):
            temp = list(packing)
            neighbourhood.append(temp)
            if neighbourhood[i][i] == 1:
                neighbourhood[i][i] = 0
            else:
                neighbourhood[i][i] = 1
        return neighbourhood

    def p_accept(self, candidate_fitness):
        """
        Probability of accepting if the candidate is worse than current.
        Depends on the current temperature and difference between candidate and current.
        """
        return math.exp(-abs(candidate_fitness - self.cur_fitness) / self.T)

    def accept(self, candidate):
        """
        Accept with probability 1 if candidate is better than current.
        Accept with probabilty p_accept(..) if candidate is worse.
        """
        candidate_fitness = self.evaluate(candidate)
        if candidate_fitness > self.cur_fitness:
            self.cur_fitness, self.cur_solution = candidate_fitness, candidate
            if candidate_fitness > self.best_fitness:
                self.best_fitness, self.best_solution = candidate_fitness, candidate
                
        else:
            if self.p_accept(candidate_fitness) >= random.random():
                self.cur_fitness, self.cur_solution = candidate_fitness, candidate

    def visualize(self):
        plt.plot(self.fitness_list)
        plt.ylabel("Value")
        plt.xlabel("Iteration")
        plt.show()

    def anneal(self):
        """
        Execute simulated annealing algorithm.
        """
        # Initialize with the greedy solution.
        self.cur_solution, self.cur_fitness = self.initial_solution()

        sol_iter = 0
        print("Starting annealing.")
        while self.T >= self.stopping_temperature and self.iteration < self.stopping_iter:

            vecinos = self.One_Flip_Neighbourhood(self.cur_solution)

            next_solution = random.choice(vecinos)
  
            best = self.best_fitness
            
            self.accept(next_solution)
            
            if (self.best_fitness > best):
                sol_iter = self.iteration

            self.T *= self.alpha
            self.iteration += 1
            self.fitness_list.append(self.cur_fitness)
            
        return self.best_fitness, sol_iter, self.cur_solution, self.iteration

    