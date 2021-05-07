import random

def random_number():
    return random.sample(range(1, 100), 1)[0]

print(random_number())
