a=[3,6,9,12,15,18]
x=21
d=3
m=[0]
for i in range(0, x-1):
  m.append(99)

m.append(0)

for i in range(0, len(a)):
  if m[a[i]] == 99:
    m[a[i]]=i
    
print m

def get_value(i, j):
  if i>=0:
    return max(m[i], m[j])
  else:
    return 99

for i in range(1, len(m)):
  m[i] = min(get_value(i-1, i), get_value(i-2, i), get_value(i-3, i))
  print i, m[i]

print m

