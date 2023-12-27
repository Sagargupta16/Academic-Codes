#Task 6

# Maths Function

v = readline(prompt = "Factorial of :")
v = as.integer(v)
print(factorial(v))#1

v = readline(prompt = "Square Root of :")
v = as.integer(v)
print(sqrt(v))#2

v = readline(prompt = "Exponantial of :")
v = as.integer(v)
print(exp(v))#3

v = readline(prompt = "log of :")
v = as.integer(v)
u = readline(prompt = "to base :")
u = as.integer(u)
print(log(v,base = u))#4

v = readline(prompt = "Cosine of angle :")
v = as.integer(v)
print(cos(v*pi/180))#5

#String Function
v = readline(prompt = "Enter String :")
print(nchar(v))#1
print(substr(v,3,5))#2
print(toupper(v))#3
print(tolower(v))#4
print(strsplit(v," "))#5

#Statistical Function
v = c(1,2,3,4,5,4,5,3,6,5,4,7,6,5,8,7,9)
print(mean(v))#1
print(sort(v))#2
print(median(v))#3
print(sd(v))#4
print(var(v))#5

