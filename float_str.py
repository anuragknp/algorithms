def convert_to_binary(n):
  bin = ''
  while n > 1:
    bin = str(n%2) + bin
    n = n/2
  bin = str(n) + bin
  return bin

def convert_float_to_binary(n):
  bin = ''
  while n != 0:
    n = n*2
    bin += str(int(n))
    n -= int(n)
  return bin

print convert_float_to_binary(0.625)
