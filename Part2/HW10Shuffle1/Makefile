# ***
# *** DO NOT modify this file
# ***

WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

TESTFALGS =-DTEST_DIVIDE -DTEST_INTERLEAVE -DTEST_SHUFFLE

SRCS = main.c shuffle.c
OBJS = $(SRCS:%.c=%.o)

hw10: $(OBJS)
	$(GCC) $(TESTFALGS) $(OBJS) -o hw10 

.c.o:
	$(GCC) $(TESTFALGS) -c $*.c

testmemory: hw10 
	$(VAL) ./hw10 4
#testing only input3 and output3

testall: test1 test2 test3 test4

test1: hw10 
	./hw10 4 

test2: hw10 
	./hw10 4|sort > output4 
	diff -w output4 expected/expected4

test3: hw10
	./hw10 11|sort > output11
	diff -w output11 expected/expected11

test4: hw10
	./hw10 8|sort > output8
	diff -w output8 expected/expected8

clean: # remove all machine generated files
	rm -f hw10 *.o output?
