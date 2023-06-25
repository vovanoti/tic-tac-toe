all: clean
	gcc main.c -Wall -o tic-tac-toe

clean:
	rm -rf tic-tac-toe
