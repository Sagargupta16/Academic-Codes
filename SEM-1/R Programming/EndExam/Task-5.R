# Task-5

# set your folder as set working directory
# setwd("D:/R codes Academic/MC21107_Sagar_EndExam")

# a)
credit <- read.csv("Credit.csv")
print(credit)

# b)
# install.packages("sqldf") # installation of sqldf package required 
library(sqldf)
sqldf("select * from credit where Age between 25 and 35 group by Region")
