GCC = g++ -std=c++11
LDFLAGS = -g -I. -Wall

EXEC = PA8
SRCS = Filter.cpp IDF.cpp main.cpp Organizer.cpp SuFFix.cpp TFIDF.cpp
HEADER = ExceptionKey.h ExceptionLibrary.h Filter.h IDF.h Key.h KeyGen.h Organizer.h Reader.h Storage.h SuFFix.h TFIDF.h Level.h LvList.h
OBJS = $(subst .cpp,.o,$(SRCS))

all: main

main: $(OBJS)
	$(GCC) $(LDFLAGS) -o $(EXEC) $(OBJS)

%.o: %.c
	$(GCC) -M $(LDFLAGS) -c $<

clean:
	rm -f $(OBJS) $(EXEC) *.tar *.gch

tar:
	tar -cvf $(EXEC).tar $(SRCS) $(HEADER) Makefile

P  = /s/bach/c/under/hottar/cs253/test-cases
TPATH = $(P)/Test_Cases/valid1
OPATH = $(P)/Test_Cases/out
COMPATH = /s/bach/c/under/hottar/cs253/to-compare
FILE = altona
FILE1 = beach
FILE2 = gastropod
FILE3 = names
FILE4 = random1
FILE5 = random2
FILE6 = rock
FILE7 = seashell
FILE8 = unique
FILEA = Alice
FILEB = teeth
FILEC = fox
FILED = a7
ALL = $(TPATH)/$(FILE) $(TPATH)/$(FILE1) $(TPATH)/$(FILE2) $(TPATH)/$(FILE3) $(TPATH)/$(FILE4) $(TPATH)/$(FILE5) $(TPATH)/$(FILE6) $(TPATH)/$(FILE7) $(TPATH)/$(FILE8)

testa:
	./$(EXEC) $(P)/$(FILEA)
testb:
	./$(EXEC) $(P)/$(FILEB)
testc:
	./$(EXEC) $(P)/$(FILEC)
testd:
	./$(EXEC) $(P)/$(FILED)
compared:
	diff -c $(COMPATH)/$(FILED)-out $(P)/$(FILED)-out
testall:
	./$(EXEC) $(TPATH)/Exceptions.txt $(ALL)
	
compareall:
	diff -c $(COMPATH)/valid1 $(OPATH)/valid1

test1:
	./$(EXEC) $(TPATH)/Exceptions.txt $(TPATH)/$(FILE)

compare1:
	diff -c $(COMPATH)/$(FILE)-out $(OPATH)/$(FILE)-out

test2:
	./$(EXEC) $(TPATH)/Exceptions.txt $(TPATH)/$(FILE1)

compare2:
	diff -c $(COMPATH)/$(FILE1)-out $(OPATH)/$(FILE1)-out

test3:
	./$(EXEC) $(TPATH)/Exceptions.txt $(TPATH)/$(FILE2)

compare3:
	diff -c $(COMPATH)/$(FILE2)-out $(OPATH)/$(FILE2)-out

test4:
	./$(EXEC) $(TPATH)/Exceptions.txt $(TPATH)/$(FILE3)

compare4:
	diff -c $(COMPATH)/$(FILE3)-out $(OPATH)/$(FILE3)-out

test5:
	./$(EXEC) $(TPATH)/Exceptions.txt $(TPATH)/$(FILE4)

compare5:
	diff -c $(COMPATH)/$(FILE4)-out $(OPATH)/$(FILE4)-out

test6:
	./$(EXEC) $(TPATH)/Exceptions.txt $(TPATH)/$(FILE5)

compare6:
	diff -c $(COMPATH)/$(FILE5)-out $(OPATH)/$(FILE5)-out

test7:
	./$(EXEC) $(TPATH)/Exceptions.txt $(TPATH)/$(FILE6)

compare7:
	diff -c $(COMPATH)/$(FILE6)-out $(OPATH)/$(FILE6)-out

test8:
	./$(EXEC) $(TPATH)/Exceptions.txt $(TPATH)/$(FILE7)

compare8:
	diff -c $(COMPATH)/$(FILE7)-out $(OPATH)/$(FILE7)-out

test9:
	./$(EXEC) $(TPATH)/Exceptions.txt $(TPATH)/$(FILE8)

compare9:
	diff -c $(COMPATH)/$(FILE8)-out $(OPATH)/$(FILE8)-out
