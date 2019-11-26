WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR) 
VAL = valgrind --tool=memcheck --log-file=vallog --leak-check=full --verbose
TESTFALGS = -DTEST_BUILDTREE -DTEST_PRINTPATH 

SRCS = main.c maze.c
OBJS = $(SRCS:%.c=%.o)

hw17: $(OBJS)
	$(GCC) $(OBJS) -o hw17

.c.o: 
	$(GCC) $(TESTFALGS) -c $*.c 

testall: test1 test2 test3 test4 test5 test6 test7 test8 test9 test10 test11 test12 test13 

testmemory: hw17 
	$(VAL) ./hw17 inputs/maze7

test1: hw17
	./hw17 inputs/maze1 > output1
	diff -w output1 expected/expected1

test2: hw17 
	./hw17 inputs/maze2 > output2 
	diff -w output2 expected/expected2

test3: hw17 
	./hw17 inputs/maze3 > output3
	diff -w output3 expected/expected3

test4: hw17
	./hw17 inputs/maze4 > output4
	diff -w output4 expected/expected4

test5: hw17 
	./hw17 inputs/maze5 > output5 
	diff -w output5 expected/expected5 

test6: hw17 
	./hw17 inputs/maze6 > output6
	diff -w output6 expected/expected6 

test7: hw17
	./hw17 inputs/maze7 > output7 
	diff -w output7 expected/expected7

test8: hw17 
	./hw17 inputs/maze8 > output8 
	diff -w output8 expected/expected8

test9: hw17 
	./hw17 inputs/maze9 > output9
	diff -w output9 expected/expected9

test10: hw17
	./hw17 inputs/maze10 > output10
	diff -w output10 expected/expected10 

test11: hw17 
	./hw17 inputs/maze11 > output11 
	diff -w output11 expected/expected11 

test12: hw17 
	./hw17 inputs/maze12 > output12
	diff -w output12 expected/expected12 

test13: hw17 
	./hw17 inputs/maze13 > output13
	diff -w output13 expected/expected13

memory: hw16
	$(VAL) ./hw16 inputs/test6in inputs/test6post 

clean: # remove all machine generated files
	rm -f hw17 *.o output* vallog testgen



