#include <stdio.h>
#include <stdlib.h> //library for system commands
//check OS to clear the screen
#if defined(unix) || defined(__unix__) || defined(__unix)
# define clear "clear"
#endif
#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
# define clear "cls"
#endif

#define NFIELD 9
int field[NFIELD] = {0};

void table();
void print_int_arr(int arr[], int count);
int areyouwin(int arr[]);
void mainmenu();
void helpmenu();
void twoplayergame();
void resetfield(int arr[], int count);

int main(){
	mainmenu();
	int modeselect = 10;
	while(1){
		printf("================================================================\n");
		printf("Please choose the number and press Enter to select a game mode\n(1 - single player, 2 - two players, 3 - help, 0 - exit):");
		scanf("%10i",&modeselect);
		switch(modeselect){
			case 1:
			system(clear);
			printf("Single mode is under development...\n");
			break;
			case 2:
			resetfield(field, NFIELD);
			twoplayergame();
			break;
			case 3:
			helpmenu();
			break;
			case 0:
			printf("Bye bye!\n");
			return 0;
		}
	}
	return 0;
}

void twoplayergame(){
	int p1 = 10;
	int p2 = 10;
	while (areyouwin(field) == 0){
		table(field);
		while (p1 > 9 || p1 < 1 || field[p1-1] != 0){
			printf("Player 1 (X): Please enter the number 1-9\n");
			scanf("%10i", &p1);
		}
		field[p1-1] = 1;
		p1 = 10;
		if (areyouwin(field) == 1 || areyouwin(field) == 3)
			break;
		table(field);
		while (p2 > 9 || p2 < 1 || field[p2-1] != 0){ 
			printf("Player 2 (O): Please enter the number 1-9\n");
			scanf("%10i", &p2);
		}
		field[p2-1] = 2;
		p2 = 10;
		if (areyouwin(field) == 2 || areyouwin(field) == 3)
			break;
	}
	table(field);
	switch(areyouwin(field)){
	case 1:
		printf("=========Congrats, Player 1 (X), you are the winner!!!==========\n");
		break;
	case 2:
		printf("=========Congrats, Player 2 (O), you are the winner!!!==========\n");
		break;
	case 3:
		printf("======Oops, it's a tie! Looks like we have no winner today======\n");
		break;
	}
}

void mainmenu(){
	printf("================Welcome to the Tic-Tac-Toe game!================\n");
}

void helpmenu(){
	system(clear);
	printf("================================================================\n");
	printf("============Below you can see how to play this game=============\n");
	printf("================================================================\n");
	printf("========Just choose the number which appropriate the cell=======\n");
	printf("=================And press the Enter to submit==================\n");
	printf("\t\t\t##### ##### #####\n");
    printf("\t\t\t# 7 # # 8 # # 9 #\n");
    printf("\t\t\t##### ##### #####\n");
    printf("\t\t\t# 4 # # 5 # # 6 #\n");
    printf("\t\t\t##### ##### #####\n");
    printf("\t\t\t# 1 # # 2 # # 3 #\n");
    printf("\t\t\t##### ##### #####\n");
	printf("================================================================\n");
}

int areyouwin(int arr[]){
	//p1 checking
	if ((arr[0] == 1 && arr[1] == 1 && arr[2] == 1) || \
		(arr[0] == 1 && arr[3] == 1 && arr[6] == 1) || \
		(arr[0] == 1 && arr[4] == 1 && arr[8] == 1) || \
		(arr[1] == 1 && arr[4] == 1 && arr[7] == 1) || \
		(arr[2] == 1 && arr[4] == 1 && arr[6] == 1) || \
		(arr[2] == 1 && arr[5] == 1 && arr[8] == 1) || \
		(arr[3] == 1 && arr[4] == 1 && arr[5] == 1) || \
		(arr[6] == 1 && arr[7] == 1 && arr[8] == 1)){
		return 1;
	}
	//p2 checking
	else if ((arr[0] == 2 && arr[1] == 2 && arr[2] == 2) || \
        (arr[0] == 2 && arr[3] == 2 && arr[6] == 2) || \
        (arr[0] == 2 && arr[4] == 2 && arr[8] == 2) || \
        (arr[1] == 2 && arr[4] == 2 && arr[7] == 2) || \
        (arr[2] == 2 && arr[4] == 2 && arr[6] == 2) || \
        (arr[2] == 2 && arr[5] == 2 && arr[8] == 2) || \
        (arr[3] == 2 && arr[4] == 2 && arr[5] == 2) || \
        (arr[6] == 2 && arr[7] == 2 && arr[8] == 2)){
		return 2;
	}
	else
		//tie checking
	for (int i=0,j=0;i<NFIELD;i++){
		if (arr[i] != 0)
			j++;
		if (j == 9)
			return 3;
	}
		return 0;
}

void table(int arr[]){
	char point[NFIELD];
	for (int i=0;i<NFIELD;i++){
		if (arr[i] == 0)
			point[i] = ' ';
		else if (arr[i] == 1)
			point[i] = 'X';
		else if (arr[i] == 2)
			point[i] = 'O';
	}
	system(clear);
	printf("================================================================\n");
	printf("=======================Two Players Mode=========================\n");
	printf("================================================================\n");
	printf("\t\t\t##### ##### #####\n");
    printf("\t\t\t# %c # # %c # # %c #\n",point[6],point[7],point[8]);
    printf("\t\t\t##### ##### #####\n");
    printf("\t\t\t# %c # # %c # # %c #\n",point[3],point[4],point[5]);
    printf("\t\t\t##### ##### #####\n");
    printf("\t\t\t# %c # # %c # # %c #\n",point[0],point[1],point[2]);
    printf("\t\t\t##### ##### #####\n");
	printf("================================================================\n");
}

//debugging function
void print_int_arr(int arr[], int count){
	for (int i=0;i<count;i++){
		printf ("count %i, result %i\n", i, arr[i]);
	}
}

void resetfield(int arr[], int count){
	for (int i=0;i<count;i++){
		arr[i] = 0;
	}
}