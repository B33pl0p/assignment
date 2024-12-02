all:
	gcc -std=c11 -g -Wall -I../include src/*.c -o ./mysolution -lm
clean:
	rm ./mysolution
	@echo Cleanup complete!
run: all
	./mysolution ../data/hello.txt
mem: 
	valgrind ./mysolution ../data/double.txt
test:
	python ../scripts/sanitycheck.py 
	