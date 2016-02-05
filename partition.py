t='aab'
r=[]

def partition(i, f):
  if i == len(t):
    r.append(f[:])
    return 

  for j in range(i, len(t)):
    f.append(t[i:j+1])  
    partition(j+1, f)
    f.pop()

partition(0, [])
print r
