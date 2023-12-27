# Task 5

a = 0
b = 1
x = 1
print(a)
print(b)
while(x<10)
{
  print(a+b)
  y = b
  b = a+b
  a = y
  x=x+1
}

fibonacci <- function(n) {
  if(n<2) 
  {
    return(n)
  } else 
    {
    return(fibonacci(n-1) + fibonacci(n-2))
  }
}

  for(i in 0:10) 
  {
    print(fibonacci(i))
  }