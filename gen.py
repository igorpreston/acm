from random import randint

for i in range(0, 100):
  n = randint(1, 101)
  a = [str(randint(-10000, 10000)) for _ in range(0, n)]
  print n, ' '.join(a)
print 0

