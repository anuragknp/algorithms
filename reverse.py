def swap(a, i, j):
  temp = a[j]
  a[j] = a[i]
  a[i] = temp

def str_reverse(str):
  a = list(str)
  j = len(a) - 1
  i = 0
  while(i < len(a)/2):
    swap(a, i, j)
    j -= 1
    i += 1
  return ''.join(a)

print str_reverse('1234567')
