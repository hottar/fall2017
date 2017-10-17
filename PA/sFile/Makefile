GCC = g++ -std=c++14 -Wall
COMPILE = $(GCC) -c
INC = -I.
DEBUG = -g
OUT = PA3
EXEC = main.o sModerator.o sScaler.o sDivider.o
OBJ = main.cpp sModerator.h sScaler.h sReader.h sDivider.h sKey.h

all: $(EXEC)
	$(GCC) $(EXEC) -o $(OUT)
	$(GCC) $(EXEC) -o debugs -g

main.o: $(OBJ)
	$(COMPILE) $(OBJ)

sScaler.o: sScaler.cpp sScaler.h sKey.h
	$(COMPILE) sScaler.cpp sScaler.h sKey.h

sModerator.o: sModerator.cpp sModerator.h sScaler.h sReader.h sDivider.h
	$(COMPILE) sModerator.cpp sModerator.h sScaler.h sReader.h sDivider.h

sDivider.o: sDivider.cpp sDivider.h
	$(COMPILE) sDivider.cpp sDivider.h

clean:
	-rm *.o $(OUT)

# test:
# 	./$(OUT) test1.txt
