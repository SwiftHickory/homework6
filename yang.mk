# Makefile for yang.cpp

CC = g++

# Flags to the compiler

CFLAGS = 

all: yang

yang: yang.o myFunction.o earthquake.o station.o
	${CC} -o yang yang.o myFunction.o earthquake.o station.o

yang.o: yang.cpp
	${CC} -c yang.cpp

myFunction.o: myFunction.cpp
	${CC} -c myFunction.cpp

earthquake.o: earthquake.cpp
	${CC} -c earthquake.cpp

station.o: station.cpp
	${CC} -c station.cpp 

clean:
	rm -rf *.o
