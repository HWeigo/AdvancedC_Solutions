# ***
# *** DO NOT modify this file
# ***

WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

TESTFALGS =-DTEST_CONVERT -DTEST_CALCULATE -DTEST_READLIST -DTEST_DELETELIST -DTEST_ADDNODE -DTEST_DELETENODE 

SRCS = main.c list.c convert.c
OBJS = $(SRCS:%.c=%.o)

hw14: $(OBJS)
	$(GCC) $(TESTFALGS) $(OBJS) -o hw14 

.c.o:
	$(GCC) $(TESTFALGS) -c $*.c

testmemory: hw14  
	$(VAL) ./hw14 inputs/test4
	#testing only input3 and output3

testall: test1 test2 test3 test4 test5  

test1: hw14 		
	./hw14 inputs/test1 > output1 
	diff output1 expected/expected1 

test2: hw14 
	./hw14 inputs/test2 > output2 
	diff output2 expected/expected2

test3: hw14 
	./hw14 inputs/test3 > output3 
	diff output3 expected/expected3 

test4: hw14 		
	./hw14 inputs/test4 > output4 
	diff output4 expected/expected4 

test5: hw14 
	./hw14 inputs/test5 > output5 
	diff output5 expected/expected5 

test6: hw13 
	./hw13 inputs/test6 > output6 
	diff output6 expected/expected6 


clean: # remove all machine generated files
	rm -f hw14 *.o output?
