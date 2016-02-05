a=[1,3,1,4,2,5]
x=7
d=3
m=[0]
for i in range(0, x-1):
  m.append(99)

m.append(0)
print m

for i in range(0, len(a)):
  if m[a[i]] == 99:
    m[a[i]]=i

print m

