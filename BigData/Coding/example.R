library(rpart)
library(rpart.plot)
s<-sample(150,100)
iris_train<-iris[s,]
iris_test<-iris[-s,]
dtm<-rpart(Species~., iris_train, method="class")

rpart.plot(dtm,type=4, extra=101)