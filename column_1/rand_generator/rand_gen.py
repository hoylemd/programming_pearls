import random

def gen_random(count, maximum):
  return random.sample(range(maximum), count)

for num in gen_random(5, 100):
  print num
