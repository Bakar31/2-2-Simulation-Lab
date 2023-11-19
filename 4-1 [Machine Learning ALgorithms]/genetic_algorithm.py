import random

def evaluate_fitness(individual):
    return individual**2

def create_individual():
    return random.randint(0, 31)

def crossover(parent1, parent2):
    crossover_point = random.randint(1, 4)
    child = (parent1 >> crossover_point) << crossover_point
    child |= (parent2 & (2 ** crossover_point - 1))
    return child

def mutate(individual):
    mutation_point = random.randint(0, 4)
    mask = 1 << mutation_point
    return individual ^ mask

def initialize_population(population_size):
    return [create_individual() for _ in range(population_size)]

def roulette_wheel_selection(population, fitness_values):
    total_fitness = sum(fitness_values)
    probabilities = [fitness / total_fitness for fitness in fitness_values]
    
    cumulative_probabilities = [sum(probabilities[:i+1]) for i in range(len(probabilities))]
    selection_point = random.uniform(0, 1)
    
    for i in range(len(cumulative_probabilities)):
        if selection_point <= cumulative_probabilities[i]:
            return population[i]

def genetic_algorithm(population_size, generations):
    population = initialize_population(population_size)

    for _ in range(generations):
        fitness_values = [evaluate_fitness(individual) for individual in population]
        population = [roulette_wheel_selection(population, fitness_values) for _ in range(population_size)]
        parent1 = population[random.randint(0, population_size - 1)]
        parent2 = population[random.randint(0, population_size - 1)]
        child = crossover(parent1, parent2)
        population.append(mutate(child))

    best_individual = max(population, key=evaluate_fitness)
    return best_individual

population_size = 4
generations = 10
best_individual = genetic_algorithm(population_size, generations)
print("Best individual:", best_individual)
print("Best fitness:", evaluate_fitness(best_individual))
