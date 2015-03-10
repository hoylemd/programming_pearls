import random
import sys

def gen_random(count, maximum):
  return random.sample(range(maximum), count)

if len(sys.argv) < 3:
  print "Usage: python rand_sample.py $count $maximum"
else:
  count=int(sys.argv[1])
  maximum=int(sys.argv[2])

  for num in gen_random(count, maximum):
    print num
