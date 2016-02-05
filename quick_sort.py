def swap(a, i, j):
  t = a[i]
  a[i]=a[j]
  a[j]=t

def partition(a, b, l, h):
  x = a[h-1]
  i = l-1
  for j in range(l, h-1):
    if (a[j] < x):
      i += 1
      swap(a, i, j)
      swap(b, i, j)
  swap(a, i+1, h-1)
  swap(b, i+1, h-1)
  return i+1
 
def quicksort(a, b, l, h):
  if (l<h):
    p = partition(a, b, l, h)
    quicksort(a, b, l, p)
    quicksort(a, b, p+1, h)
  

a = [20,3,3,7,5,3,11,1]
print a
b=range(0,len(a))
quicksort(a, b, 0, len(a))
print a
print b

j=0
c=0
for i in range(0, len(a)-1):
  j=i+1
  while j < len(a)-1 and a[j]==a[j+1]:
    j+=1
  
  if a[i]==a[j]:
    j+=1
  
for k in range(i, j):
  if b[i] < b[k+1]:   
    print a[i], a[k+1] 
    c+=j-i

print c


    
