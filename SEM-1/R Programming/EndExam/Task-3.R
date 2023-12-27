# Task-3

fibo <-function(n) {
  n1 = 0
  n2 = 1
  
  if(n == 1)
  {
    print(n1)
  } 
  else 
  {
    print(n1)
    print(n2)
    while(n1+n2<n) 
    {
      nth = n1 + n2
      print(nth)
      n1 = n2
      n2 = nth
    }
  }
}


print("Enter n Value ")
n <- scan()
cat("fibonacci series below ",n)
fibo(n)






