#Task 2

a = c(6,8,10,3,2,43,523,235,5,4,5,4,5,46,65,6,7,67,6,8,0,-100)
x = -100000000
y = 100000000
for(i in a)
{
  if(i>x)
  {
    x = i
  }
  if(i<y)
  {
    y = i
  }
}
print(x)#max
print(y)#min

print(max(a))
print(min(a))
