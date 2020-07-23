PROGRAM = main
OBJS = func_matrix.o
CC = gcc

$(PROGRAM): $(PROGRAM).o $(OBJS)
	$(CC) -o $(PROGRAM).o $(OBJS)
$(OBJS) $(PROGRAM).o: func_matrix.h

clean:
	rm -f *.o
