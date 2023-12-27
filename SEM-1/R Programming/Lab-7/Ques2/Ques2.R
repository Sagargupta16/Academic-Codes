# 2) Find skewness and draw the histogram without using 
#    inbuilt skewness method on the following data :-
#    5, 6, 10, 15, 18, 89, 35, 89, 76, 67, 54, 4, 12, 9

data <-c(5,6,10,15,18,89,35,89,76,67,54,4,12,9)

mean_data <- sum(data)/length(data)

skewness1<-sum((data-mean_data)^3)/length(data)/sqrt((sum((data-mean_data)^2)/length(data))^3)

png(file="histQues2.png")
print(skewness1)
hist(data)
dev.off()