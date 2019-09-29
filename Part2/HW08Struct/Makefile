# ***
# *** DO NOT modify this file
# ***

WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

TESTFALGS = -DTEST_MAIN -DTEST_COUNTVECTOR -DTEST_READVECTOR -DTEST_COMPAREVECTOR -DTEST_WRITEVECTOR
SRCS = main.c hw08.c
OBJS = $(SRCS:%.c=%.o)

hw08: $(OBJS)
	$(GCC) $(TESTFALGS) $(OBJS) -o hw08

.c.o:
	$(GCC) $(TESTFALGS) -c $*.c

testmemory: hw08 
	$(VAL) ./hw08 inputs/input3 output3
#testing only input3 and output3

testall: test1 test2 test3 test4 test5

test1: hw08
	./hw08 inputs/test1.bin output1.bin
	diff output1.bin expected/expected1.bin

test2: hw08
	./hw08 inputs/test2.bin output2.bin
	diff output2.bin expected/expected2.bin 

test3: hw08
	./hw08 inputs/test3.bin output3.bin
	diff output3.bin expected/expected3.bin 

test4: hw08
	./hw08 inputs/test4.bin  output4.bin 
	diff output4.bin expected/expected4.bin 

test5: hw08 
	./hw08 inputs/test5.bin  output5.bin 
	diff output5.bin expected/expected5.bin 

clean: # remove all machine generated files
	rm -f hw08 *.o output?
