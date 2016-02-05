M = [[21,22,23,24],[25,26,27,28],[11,12,13,14],[15,16,17,18]]

def print_matrix():
  for i in xrange(len(M)):
    for j in xrange(len(M[i])):
      print (M[i][j]),
    print "\n"

def rotate():
  layer_size = len(M)
  for layer in xrange(len(M)/2):
    for i in xrange(layer_size-1):
      temp = M[layer][layer + i]
      M[layer][layer + i] = M[layer_size + layer -i - 1][layer]
      M[layer_size + layer -i - 1][layer] = M[layer_size + layer - 1][layer_size + layer -i - 1]
      M[layer_size + layer - 1][layer_size + layer -i - 1] = M[layer + i][layer_size + layer - 1]
      M[layer+i][layer_size + layer - 1] = temp
    layer_size -= 2

print_matrix()
rotate()
print "=========================="
print_matrix()
