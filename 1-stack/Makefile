all: clean 
	gcc -std=c11 -g -Wall -I../include ../obj/*.o src/problem.c src/main.c src/stack.* -o ./mysolution -lm

run: clean all
	./mysolution 0 10 5

clean: 
	@rm -f obj/*.o

mem: 
	valgrind ./mysolution

test: all
	python ../scripts/sanitycheck.py || make install && echo "Run make test again"

install:
	pip install python-benedict 

submit:
	@echo "You are in the wrong folder. cd .. and run make submit from the project directory"


# INSTRUCTOR ONLY
solution:
	gcc -std=c11 -g -Wall -I../include ../obj/*.o src/solution.c src/main.c src/stack.* -o ./mysolution -lm
	python ../scripts/sanitycheck.py 
update: 
	python ../scripts/generate_solutions.py 
