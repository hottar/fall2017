
CC = gcc
OBJS = timer.o
FLAGS = -fopenmp
SEQFLAGS = -O3
DEBUG = -g

EXEC = knapSeq knap1 debug1

all: $(EXEC)

knapSeq: knap.c timer.o
	$(CC)  $(SEQFLAGS) -o knapSeq knap.c $(OBJS)

knap1: knap1.c timer.o
	$(CC)	$(SEQFLAGS) -o knap1 knap.c $(OBJS)

debug1: knap1.c timer.o
	$(CC) $(SEQFLAGS) -o debug1 knap.c $(OBJS) -g
	
timer.o: timer.c
	$(CC) -o $@ -c timer.c

clean:
	rm -f $(EXEC) $(OBJS)
