class Node:
  def __init__(self, val):
    self.val = val
    self.next = None


class LinkedList:
  def __init__(self):
    self._head = None

  def insert(self, val):
    node = Node(val)
    node.next = self._head
    self._head = node
  
  def reverse(self):
    ptr = self._head
    prev = None
    while ptr != None:
      next = ptr.next
      ptr.next = prev
      prev = ptr
      ptr = next    
    self._head = prev

  def print_list(self):
    ptr = self._head
    while ptr != None:
      print ptr.val
      ptr = ptr.next

if __name__ == '__main__':
  list = LinkedList()
  list.insert(10)
  list.insert(20)
  list.insert(30)
  list.insert(40)
  list.insert(50)
  list.insert(60)
  list.insert(70)
  list.insert(80)
  list.print_list()
  list.reverse()
  list.print_list()
