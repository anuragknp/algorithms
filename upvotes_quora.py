line1 = raw_input()
window_size = int(line1.split()[1])
line2 = raw_input()
upvotes = [int(n) for n in line2.split()]

def check_range(start, end):
  '''
    Inputs: start, end -> index to check 
    Output: 0-1 for non_decreasing, non_increasing
  '''
  inc = dec = 0
  for k in range(start+1, end):
    if upvotes[k-1] == upvotes[k]:
      inc += 1
      dec += 1
    elif upvotes[k-1] < upvotes[k]: 
      inc += 1
    else:
      dec += 1

  if inc == end-start-1:
    inc = 1
  else:
    inc  = 0
  if dec == end-start-1:
    dec = 1
  else:
    dec = 0

  return inc ,dec

#for each window
for i in range(0, len(upvotes) - window_size + 1):
  non_decreasing = 0
  non_increasing = 0
  #for each sub range of size = 2...window_size
  for m in range(2, window_size+1):
    #check for each sub range
    for j in range(i, i + window_size - m + 1):
      nd, ni = check_range(j, j+m)
      non_decreasing += nd
      non_increasing += ni
  
  print non_decreasing - non_increasing
  
