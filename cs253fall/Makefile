GCC = g++ -std=c++14 -Wall
COMPILE = $(GCC) -c
INC = -I.
OUT = PA1

all: main.o measure.o
	$(GCC) main.o Measure.o -o $(OUT)

main.o: main.cpp Measure.h
	$(COMPILE) main.cpp Measure.h

measure.o: Measure.cpp Measure.h
	$(COMPILE) Measure.cpp Measure.h

clean:
	-rm *.o $(OUT)

test:
	./$(OUT) test1.txt
