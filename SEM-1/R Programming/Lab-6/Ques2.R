#Q2) Draw the Linear regression curve for the above table between Year and Amount.

year = c(2001,2002,2003,2004,2005,2006,2007,2008,2009,2010,2011,2012,2013,2014)
amount = c(40,39,41,29,32,30,33,15,10,11,20,24,10,15)

png(file="Regression.png")
plot(year,amount, col="blue", main = "Regression", abline(lm(amount~year)), 
     cex=1.3, pch=16, xlab = "YEAR", ylab= "Amount")
dev.off()