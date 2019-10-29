# ***
# *** DO NOT modify this file
# ***

WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

TESTFALGS = -DTEST_READLIST -DTEST_DELETELIST -DTEST_ADDNODE -DTEST_DELETENODE 

SRCS = main.c list.c calculate.c
OBJS = $(SRCS:%.c=%.o)

hw13: $(OBJS)
	$(GCC) $(TESTFALGS) $(OBJS) -o hw13 

.c.o:
	$(GCC) $(TESTFALGS) -c $*.c

testmemory: hw13  
	$(VAL) ./hw13 inputs/test1 
#testing only input3 and output3

testall: test1 test2 test3 

test1: hw13 		
	./hw13 inputs/test1 
#	diff output1 expected/expected1 

test2: hw13 
	./hw12 6 4 > output2
	diff output2 expected/expected2

test3: hw12 
	./hw12 25 7 > output3
	diff output3 expected/expected3 

clean: # remove all machine generated files
	rm -f hw13 *.o output?
