def lambda_as_function():
  print "lambda_as_function"
  x = lambda x: x*2
  print x(2)
  print x(3)

def lambda_asmapreduce():
  foo = [2, 18, 9, 22, 17, 24, 8, 12, 27]
  print "lambda_asmapreduce"
  print "foo", foo
  print "filter(lambda x: x%2 == 0, foo)"
  print filter(lambda x: x%2 == 0, foo)
  print "map(lambda x: x*2, foo)"  
  print map(lambda x: x*2, foo)
  print "reduce(lambda x, y: x+y, foo)"
  print reduce(lambda x, y: x+y, foo)
  
lambda_as_function()
lambda_asmapreduce()
