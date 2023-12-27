# TASK-1 Write a R script to find total number of unique 
#        even numbers in a given vector of integers.

print("Enter a vector")
x<-as.integer(scan())
y<-c()
for(i in x)
{
  if(!(i %in% y))
  {
    if(i%%2==0)
    {
      y<-append(y,i)
    }
  }
}
cat("Total number of unique even number in vector are : ",length(y))
cat("Unique Even Numbers are : ",y)