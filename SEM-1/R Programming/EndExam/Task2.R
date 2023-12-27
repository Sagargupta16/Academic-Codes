# Task -2
sink("my_result.txt")


# relational operators
# for integer type
a<- as.integer(readline())
b<- as.integer(readline())
print(a>b)
print(a<b)
print(a<=b)
print(a>=b)
print(a==b)
print(a!=b)

#for numeric type
a<- as.numeric(readline())
b<- as.numeric(readline())
print(a>b)
print(a<b)
print(a<=b)
print(a>=b)
print(a==b)
print(a!=b)

#for character type
a<- as.character(readline())
b<- as.character(readline())
print(a>b)
print(a<b)
print(a<=b)
print(a>=b)
print(a==b)
print(a!=b)

#for logical type
a<- as.logical(readline())
b<- as.logical(readline())
print(a>b)
print(a<b)
print(a<=b)
print(a>=b)
print(a==b)
print(a!=b)

# for complex type
a<- as.complex(readline())
b<- as.complex(readline())
#print(a>b)
#print(a<b)
#print(a<=b)
#print(a>=b)
print(a==b)
print(a!=b)

#for raw type
a<- as.raw(readline())
b<- as.raw(readline())
print(a>b)
print(a<b)
print(a<=b)
print(a>=b)
print(a==b)
print(a!=b)

#for vectors
a<- scan()
b<- scan()
print(a>b)
print(a<b)
print(a==b)
print(a<=b)
print(a>=b)
print(a!=b)


# Miscellaneous operators

# " <- " operator
a<-16L
b<-1.5
c<-"Sagar"
d<-TRUE
e<-5-2i
f<-scan()
g<-charToRaw("String")
print(a)
print(b)
print(c)
print(d)
print(e)
print(f)
print(g)


# " -> " operator
12L->a
1.5->b
"Sagar"->c
TRUE->d
5-12i->e
scan()->f
charToRaw("String")->g
print(a)
print(b)
print(c)
print(d)
print(e)
print(f)
print(g)

# colon operator
a<- 1:10
print(i)

# %in% operator
x<- scan()
a<- 1
b<- 2
print(a %in% x)
print(b %in% x)

# %*% operator
m<- matrix(scan(),nrow=2,ncol=2,byrow=TRUE)
print(m)
n<- m%*%t(m)
print(n)


sink()
