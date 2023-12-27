#Task 4

v = 1:100
for(i in v)
{
  if(i%%3==0)
  {
    if(i%%4==0)
    {
      print('Lucky and Favourite')
    }else
    {
      print('Lucky')
    }
  }else if(i%%4==0)
  {
    print('Favourite')
  }else
  {
    print(i)
  }
}