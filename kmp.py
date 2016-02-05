import sys

def calculate_least_prefix(pattern):
  j = 0
  lp = [0]
  for i in range(1, len(pattern)):
    if pattern[i] == pattern[j]:
      j+=1
    else:
      j=0
    lp.append(j)
  return lp


def kmp_search(text, pattern):
  least_prefix = calculate_least_prefix(pattern)
  j = 0
  i = 0
  while i < len(text):
    if text[i] == pattern[j]:
      j += 1  
      i += 1
    
      if j == len(pattern):
        print "found at: ", (i-j)
        j = least_prefix[j-1]
    else:
      if j == 0:
        i += 1
      else:
        j = least_prefix[j-1]
      
kmp_search("ABABDABACDABABCABABABABCABAB", "ABABCABAB")
