all: clean
	gcc main.c -o tic-tac-toe

clean:
	rm -rf tic-tac-toe
