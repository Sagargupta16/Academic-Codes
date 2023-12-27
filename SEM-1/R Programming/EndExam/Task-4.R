# Task-4
install.packages("moments")
any(grepl("moments",installed.packages()))
library("moments")

x<-c(8,9,56,12,3,33,23,20,19,30,44,19,90,3,55,67)


cat("Kurtosis of data is : ",kurtosis(x))
mean_data <- sum(x)/length(x)
skewness1<-sum((x-mean_data)^3)/length(x)/sqrt((sum((x-mean_data)^2)/length(x))^3)

cat("Skewness of data is :",skewness1)

png(file="histTask4.png")
hist(x)
dev.off()