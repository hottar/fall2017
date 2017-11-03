#edited from laptop
GCC = g++ -std=c++11
LDFLAGS = -g -I. -Wall
EXEC = PA6
SRCS = Filter.cpp IDF.cpp main.cpp Organizer.cpp SuFFix.cpp TFIDF.cpp
HEADER = ExceptionKey.h ExceptionLibrary.h Filter.h IDF.h Key.h KeyGen.h Organizer.h Reader.h Storage.h SuFFix.h TFIDF.h
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

TPATH = /s/bach/c/under/hottar/cs253/test-cases/PA5_TestCase
T6PATH = /s/bach/c/under/hottar/cs253/test-cases
COMPATH = /s/bach/c/under/hottar/cs253/to-compare

test1:
	./$(EXEC) $(TPATH)/valid_exceptions.txt $(TPATH)/valid_in

test2:
	./$(EXEC) $(TPATH)/valid_exceptions.txt $(T6PATH)/valid4.txt

compare1:
	diff -c $(COMPATH)/user_out.txt $(TPATH)/valid_out
	
compare2: 
	diff -c $(COMPATH)/user4_out.txt $(T6PATH)/valid4_out.txt

testa:
	./$(EXEC) $(TPATH)/valid_exceptions.txt $(T6PATH)/bou.txt $(T6PATH)/pub.txt $(T6PATH)/gjt.txt

testb:
	./$(EXEC) $(TPATH)/valid_exceptions.txt $(T6PATH)/one.txt $(T6PATH)/two.txt $(T6PATH)/three.txt

testc:
	./$(EXEC) $(TPATH)/valid_exceptions.txt $(T6PATH)/test1 $(T6PATH)/test2 $(T6PATH)/test3

