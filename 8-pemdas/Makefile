all:
	gcc -std=c11 -g -Wall -I../include src/problem.c src/stack.* -o ./mysolution -lm
clean:
	rm ./mysolution
	@echo Cleanup complete!
run: all
	./mysolution ../data/hello.txt
mem: 
	valgrind ./mysolution ../data/double.txt
test:
	python ../scripts/sanitycheck.py 
# INSTRUCTOR ONLY
solution:
	gcc -std=c11 -g -Wall -I../include src/solution.c src/stack.* -o ./mysolution -lm
update: 
	python ../scripts/generate_solutions.py 
