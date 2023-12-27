#4) Find the Standard Deviation of the 
#   following data without using inbuilt method :-
#   8, 9, 56, 12, 3, 33, 23, 20, 19, 30, 44, 19, 90

data<-c(8, 9, 56, 12, 3, 33, 23, 20, 19, 30, 44, 19, 90)

mean_data <- sum(data)/length(data)
s_d <- sqrt(sum((data-mean_data)^2)/(length(data)-1))
print(s_d)