bin:
	clang++ -Wall -o main main.cpp -g

run: bin
	./main

runval: bin
	valgrind --leak-check=full ./main
