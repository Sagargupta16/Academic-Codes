#3) Find Kurtosis and draw the histogram 
#   on the following data using inbuilt kurtosis method :-
#   12, 89, 67, 54, 60, 34, 43, 56, 5, 7, 45, 93, 9

library(moments)

data<-c(12, 89, 67, 54, 60, 34, 43, 56, 5, 7, 45, 93, 9)

png(file="histQues3.png")
print(kurtosis(data))
hist(data)
dev.off()