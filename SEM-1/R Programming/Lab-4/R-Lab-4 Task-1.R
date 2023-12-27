#Task 1

a = readline()
a <- as.integer(a)
cnt=1
z=0
while(cnt<=a)
{
  if(a%%cnt==0)
  {
    print(cnt)
    z=z+1
  }
  cnt = cnt +1
}
if(z%%2==0)
{
  print('Trendy Number')
}else
{
  print('Not a Trendy Number')
}