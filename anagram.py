import sys

def permut(s):
  perms = []
  if len(s) == 1:
    return s
  
  for i in range(0, len(s)):
    res= permut(s[:i] + s[i+1:])
    for t in res:
      perms.append(s[i] + t)

  return perms

if __name__ == '__main__':
  s = sys.argv[1]
  s = sorted(s)
  print permut(s)
