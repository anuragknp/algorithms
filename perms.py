def perms(word):
  if len(word) == 1:
    return [word]
  
  first = word[0]
  perm = perms(word[1:])
  
  r = []
  for p in perm:
    for i in range(len(p)+1):
      r.append(p[:i]+first+p[i:])

  return r

print perms('abc')
