import random
import sys

def gen_random(count, maximum):
  return random.sample(range(maximum), count)

invalid_params_string="  passed: count=%s, maximum=%s";

if len(sys.argv) < 3:
  print "Usage: python rand_sample.py $count $maximum"
else:
  count=sys.argv[1]
  maximum=sys.argv[2]
  ok=False
  try:
    count=int(count)
    maximum=int(maximum)
    ok=True
  except ValueError:
    print "Please pass numbers for count and maximum"
    print invalid_params_string % (count, maximum)

  if ok:
    try:
      for num in gen_random(count, maximum):
        print num
    except ValueError:
      print "Maximum must be greater than count"
      print invalid_params_string % (count, maximum)
