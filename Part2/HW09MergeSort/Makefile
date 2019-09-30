WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

TESTFALGS = -DDEBUG -DTEST_MAIN -DTEST_READDATA -DTEST_WRITEDATA -DTEST_MERGE -DTEST_MERGESSORT
SRCS = main.c hw09.c
OBJS = $(SRCS:%.c=%.o)

hw08: $(OBJS)
	$(GCC) $(TESTFALGS) $(OBJS) -o hw09 

.c.o:
	$(GCC) $(TESTFALGS) -c $*.c

testmemory: hw09  
	$(VAL) ./hw08 inputs/input3 output3
#testing only input3 and output3

testall: test1 test2 test3 test4 test5

test1: hw09
	./hw09 inputs/input1 output1 
	diff output1 expected/expected1 

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
