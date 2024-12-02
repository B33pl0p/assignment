all:
	gcc -std=c11 -D_GNU_SOURCE -g -Wall -I../include ../include/transcript.c src/problem.c src/adt.* -o ./mysolution -lm
clean:
	rm ./mysolution
	@echo Cleanup complete!
run: all
	./mysolution ../data/emails.txt
test:
	python ../scripts/sanitycheck.py 


# INSTRUCTOR ONLY
solution:
	gcc -std=c11 -D_GNU_SOURCE -g -Wall -I../include ../obj/*.o src/solution.c  ../include/transcript.c  -o ./mysolution -lm
	python ../scripts/sanitycheck.py 
update: 
	python ../scripts/generate_solutions.py 
