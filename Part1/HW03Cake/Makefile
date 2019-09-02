# ***
# *** DO NOT modify this file 
# ***

WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR) 

TESTFALGS = -DTEST_ELIMINATE

SRCS = main.c eliminate.c
OBJS = $(SRCS:%.c=%.o)

main: $(OBJS) 
	$(GCC) $(TESTFALGS) $(OBJS) -o main

.c.o: 
	$(GCC) $(TESTFALGS) -c $*.c 

testall: test1 test2 test3 
testadditional: test4 test5 test6 test7

test1: main
	./main 6 3 > output1
	diff output1 expected/expected1

test2: main
	./main 6 4 > output2
	diff output2 expected/expected2

test3: main
	./main 25 7 > output3
	diff output3 expected/expected3

test4: main
	./main 4 11 > output4

test5: main
	./main 17 9 > output5

test6: main
	./main 2 3 > output6

test7: main
	./main 6 14 > output7

clean: # remove all machine generated files
	rm -f main *.o output?


