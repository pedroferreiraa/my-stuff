#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define RED "\033[0;31m"
#define GRN "\033[0;32m"
#define YEL "\033[0;33m"
#define BLU "\033[0;34m"
#define MAG "\033[0;35m"
#define CYN "\033[0;36m"
#define BHRED "\033[1;91m"
#define REDHB "\033[0;101m"
#define GRNHB "\033[0;102m"
#define YELHB "\033[0;103m"
#define BLUHB "\033[0;104m"
#define MAGHB "\033[0;105m"
#define CYNHB "\033[0;106m"
#define COLOR_RESET "\033[0m"

void win(int *code);
void printColors(int *choice);
int verify(int *code, int *choice);
void f_error(const char *message);
void check(int *choice, int m_number, int pos);
void play(int *code, int *choice);
void gen_code(int *code);


/*
 * THIS PROGRAM HAS A PROPUSE TO SIMULATE A MASTERMIND GAME.
 * THE PLAYER WILL PLAY AGAINST THE MACHINE, A CODE WILL BE GENERATED AND
 * THE PLAYER HAS TO FINDOUT THIS CODE.
 *
 * GOOD GAME, SEE YOU!
*/


void win(int *code)
{
	int i = 0;

	printf("\nYou Win!!\tCode: ");

	for (i = 0; i < 4; ++i)
		printf("%d ", code[i]);
	printf("\n");

	exit(EXIT_SUCCESS);
}

void printColors(int *choice)
{
	int i = 0;
	char *background[] = {REDHB, GRNHB, YELHB, BLUHB, MAGHB, CYNHB};

	for (i = 0; i < 4; ++i)
		printf("%s            " COLOR_RESET,
				background[choice[i] - 1]);
}

int verify(int *code, int *choice)
{
	int i, j, black_flag, white_flag, error;
	int array[4] = {-1, -1, -1, -1};

	i = j = black_flag = white_flag = error = 0;

	for (i = 0; i < 4; ++i) {
 		if (choice[i] == code[i]) {
			black_flag++;
			array[i] = 1;
		}
	}

	for (i = 0; i < 4; ++i) {
		for (j = 0; j < 4; ++j) {
			if (choice[i] == code[j] && i != j) {
				white_flag++;
				array[i] = 0;
				break;
			}
		}
	}

	for (i = 0; i < 4; ++i) {
		if (array[i] == -1)
			error++; 
	}

	printf("Verifying: %d black pegs   %d white pegs   %d errors.\n",
			black_flag, white_flag, error);

	printColors(choice);

	if (black_flag == 4)
		return 1;

	return 0;
}

void f_error(const char *message)
{
	fprintf(stderr, BHRED"%s"COLOR_RESET, message);
	exit(EXIT_FAILURE);
}

void check(int *choice, int m_number, int pos)
{
	int i = 0;

	if (m_number < 1 || m_number > 6)
		f_error("ERROR!! Use only numbers 1-6 :)\n");

	for (i = 0; i < 4; ++i) {
		if (m_number == choice[i] && i != pos)
			f_error("Don't use repeated values. Input the "
						"value again.\n");
	}
}

void play(int *code, int *choice)
{
	int i = 0, t = 0;

	printf("Choose four colors:\n"
			RED "\t* RED [1]\n"
			GRN "\t* GREEN [2]\n"
			YEL "\t* YELLOW [3]\n"
			BLU "\t* BLUE [4]\n"
			MAG "\t* PINK [5]\n"
		       CYN "\t* CYAN [6]\n"
			COLOR_RESET
	);

	do {
		for (i = 0; i < 4; ++i) {
			printf(": ");
			scanf("%d", &choice[i]);
			check(choice, choice[i], i);
		}

		if (verify(code, choice))
			win(code);

		memset(choice, 0, 4 * sizeof(int));

		printf("\n");
		t++;
	} while(t < 10);
}

void gen_code(int *code)
{
	int i = 0, j = 0, flag = 0;
	srand(time(NULL));

	for (i = 0; i < 4; ++i) {
		flag = 0;
		code[i] = 1 + rand() % 6;

		for (j = 0; j < 4; ++j)
			if (code[i] == code[j] && i != j) {
				flag = 1;
				break;
			}

		if (flag == 1)
			--i;
	}
}

int main(void)
{
	int code[4] = {0, 0, 0, 0}, choice[4] = {0, 0, 0, 0};

	gen_code(code);
	play(code, choice);

	return 0;
}
