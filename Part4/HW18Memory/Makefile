# ***
# *** DO NOT modify this file 
# ***

WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR) 
VAL = valgrind --tool=memcheck --log-file=vallog --leak-check=full --verbose
TESTFALGS = -DTEST_CREATEMEMORY -DTEST_DESTROYMEMORY -DTEST_ALLOCATEMEMORY -DTEST_FREEMEMORY -DTEST_SAVEOCCUPANCY

SRCS = main.c memory.c
OBJS = $(SRCS:%.c=%.o)

hw18: $(OBJS)
	$(GCC) $(OBJS) -o hw18

.c.o: 
	$(GCC) $(TESTFALGS) -c $*.c 

testall: test1 test2 test3 test4 test5

test1: hw18
	./hw18 20 inputs/test1 output1 
#	diff -w output1 expected/expected1

test2: hw18
	./hw18 20 inputs/test2 output2

test3: hw18 
	./hw18 20 inputs/test3 output3

test4: hw18
	./hw18 10 inputs/test4 output4

test5: hw18
	./hw18 10 inputs/test5 output5

memory: hw16
	$(VAL) ./hw16 inputs/test6in inputs/test6post 

clean: # remove all machine generated files
	rm -f hw18 *.o output? vallog testgen



