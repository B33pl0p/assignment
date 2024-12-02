all: clean 
	gcc -D_GNU_SOURCE -std=c11 -g -Wall -I../include ../obj/*.o src/main.c src/dcll.* -o ./mysolution -lm

run: clean all
	./mysolution 0 1 1

clean: 
	@rm -f obj/*.o

mem: 
	valgrind ./mysolution

test: all
	python ../scripts/sanitycheck.py || make install

install:
	pip install python-benedict 

submit:
	@echo "You are in the wrong folder. cd .. and run make submit from the project directory"


# INSTRUCTOR ONLY
solution:
	gcc -D_GNU_SOURCE -std=c11 -g -Wall -I../include ../obj/*.o src/solution.c src/main.c src/dcll.h -o ./mysolution -lm
update: 
	python ../scripts/generate_solutions.py 
