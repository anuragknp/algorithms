class Node:
  def __init__(self, value):
    self.left = None
    self.right = None
    self.parent = None
    self.value = value

class BST:
  def __init__(self):
    self._root = None

  def _insert(self, ptr, node):
    if ptr.value > node.value:
      if ptr.left:
        self._insert(ptr.left, node)
      else:
        node.parent = ptr
        ptr.left = node
    elif ptr.value < node.value:
      if ptr.right:
        self._insert(ptr.right, node)
      else:
        node.parent = ptr
        ptr.right = node
    else: #duplicate
      raise Exception("duplicate key")

 
  def insert(self, value):
    node = Node(value)

    if self._root == None:
      self._root = node
      return
    
    self._insert(self._root, node)
  
  def _printtree(self, node):
    if not node:
      return
 
    self._printtree(node.left)
    print node.value
    self._printtree(node.right)

  def printtree(self):
    self._printtree(self._root)

  def get_smallest(self, node):
    if node.left:
      return self.get_smallest(node.left)

    return node.value	

  def _delete(self, node, value):
    print node.value, value
    if node.value > value and node.left:
      self._delete(node.left, value)
    elif node.value < value and node.right:
      self._delete(node.right, value)
    elif node.value == value:
      if node.left == None and node.right == None:
        if node.parent.left == node:
          node.parent.left = None
        else:
          node.parent.right == None
      elif node.left == None and node.right:
        if node.parent.left == node: 
          node.parent.left = node.right
        else:
          node.parent.right == node.right
      elif node.right == None and node.left:
        if node.parent.right == node:
          node.parent.right = node.left
        else:
          node.parent.left == node.left
      else:
        min = self._getsmallest(node.right)
        node.value = min
        self._delete(node.right, node.right.value)
     

  def delete(self, value):
    self._delete(self._root, value)

  def is_balance(node):
    if not node:
      return 0
    
    lh = isbalance(node.left)
    if lh == -1:
      return -1
    
    rh = isbalance(node.right)
    if rh == -1:
      return -1
      
    if rh - lh  not in [-1, 1, 0]:
      return -1
    
    return max(lh, rh)


if __name__ == "__main__":
  tree = BST()
  tree.insert(5)
  tree.insert(2)
  tree.insert(3)
  tree.insert(6)
  tree.insert(9)
  tree.insert(12)
  tree.insert(4)
  #tree.printtree()
  tree.delete(2)
  tree.printtree()
