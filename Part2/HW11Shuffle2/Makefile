# ***
# *** DO NOT modify this file
# ***

WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

# TESTFALGS =-DTEST_DIVIDE -DTEST_INTERLEAVE -DTEST_SHUFFLE

SRCS = main.c shuffle.c
OBJS = $(SRCS:%.c=%.o)

hw11: $(OBJS)
	$(GCC) $(OBJS) -o hw11 

.c.o:
	$(GCC) $(TESTFALGS) -c $*.c

testmemory: hw11 
	$(VAL) ./hw11 4 5
#testing only input3 and output3

testall: test1 test2 test3 test4

test1: hw11 
	./hw11 11 2|sort|uniq > output_11_2
	diff output_11_2 expected/expected_11_2

test2: hw11  
	./hw11 4 5|sort|uniq > output_4_5
	diff output_4_5 expected/expected_4_5

test3: hw11 
	./hw11 7 3|sort|uniq > output_7_3
	diff output_7_3 expected/expected_7_3

test4: hw11 
	./hw11 8 2|sort|uniq > output_8_2
	diff output_8_2 expected/expected_8_2  

clean: # remove all machine generated files
	rm -f hw11 *.o output?
