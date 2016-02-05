arr=[1,2,3,4,5,6]

class Node:
  def __init__(self, val):
    self.val = val
    self.left = None
    self.right = None

def create_bst(arr, i, j):
  if i > j:
    return None
  
  mid = (i+j)/2
  node = Node(arr[mid])  
  node.left = create_bst(arr, i, mid-1)
  node.right = create_bst(arr, mid+1, j)

  return node

def print_bst(node):
  if not node:
    return

  print_bst(node.left)
  print node.val
  print_bst(node.right)

root = create_bst(arr, 0, len(arr)-1)
print_bst(root)
