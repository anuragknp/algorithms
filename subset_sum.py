
def cnt(v):
  if (v<=0):
    return v
  
  o1 = cnt(v-5)
  o2 = cnt(v-12)
  o3 = cnt(v-16)
  
  max = o1
  n = 5
  if max < o2:
    max = o2
    n = 12
  if max < o3:
    max = o3
    n = 16
  
  return max

def backtrack(v):
  if (v<=0):
    return v

  o1 = backtrack(v-5)
  if o1 == 0:
    print '5'
    return 0
  o2 = backtrack(v-12)
  if o2 == 0:
    print '12'
    return 0
  o3 = backtrack(v-16)
  if o3 == 0:
    print '16'
    return 0

  return -1

diff = cnt(13)
t = 13
if diff < 0:
  t = 13 + -1*diff

backtrack(t)



