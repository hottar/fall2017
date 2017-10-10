GCC = g++ -std=c++11 -Wall
COMPILE = g++ -std=c++11 -Wall -c
INC = -I.
DEBUG = -g
EXEC = PA4
OBJ = main.cpp Key.h KeyGen.h Organizer.o Reader.h Storage.h SuFFix.o Filter.o

all: $(OBJ)
	$(GCC) $(OBJ) -o $(EXEC) $(DEBUG)

stem:
	./$(EXEC) stem_in.txt

clean:
	rm *.o $(EXEC)

Organizer.o: Key.h KeyGen.h Organizer.h Organizer.cpp Reader.h Storage.h SuFFix.h Filter.h
	$(COMPILE) Key.h KeyGen.h Organizer.h Organizer.cpp Reader.h Storage.h SuFFix.h Filter.h

Filter.o: Filter.h Filter.cpp
	$(COMPILE) Filter.h Filter.cpp

key.o: Key.h
		$(COMPILE) Key.h

SuFFix.o: SuFFix.h SuFFix.cpp
	$(COMPILE) SuFFix.h SuFFix.cpp

gen.o: KeyGen.h SuFFix.h Key.h
	$(COMPILE) KeyGen.h SuFFix.h Key.h

store.o: Storage.h Key.h
	$(COMPILE) Storage.h Key.h

reader.o: Reader.h
	$(COMPILE) Reader.h
