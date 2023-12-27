#5) Find the variance, SD, Mean Deviation about Mean, 
#   Mean Deviation about Median on the following data :-
#   5, 6, 5, 8, 23, 12, 96, 90, 56, 78, 34, 56, 1, 4, 5, 67, 99

data<-c(5, 6, 5, 8, 23, 12, 96, 90, 56, 78, 34, 56, 1, 4, 5, 67, 99)

print(var(data))#variance

print(sd(data))#standard deviation

md_mean = sum(abs(data-mean(data))) /length(data)
print(md_mean)#mean Deviation about mean

md_median = sum(abs(data-median(data))) /length(data)
print(md_median)#mean Deviation about Median