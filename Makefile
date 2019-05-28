OBJS	= number.o check.o process.o
SOURCE	= number.cpp check.cpp process.cpp
HEADER	= check.hpp process.hpp
OUT	= a.out
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 =

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

number.o: number.cpp
	$(CC) $(FLAGS) number.cpp

check.o: check.cpp
	$(CC) $(FLAGS) check.cpp

process.o: process.cpp
	$(CC) $(FLAGS) process.cpp


clean:
	rm -f $(OBJS) $(OUT)
