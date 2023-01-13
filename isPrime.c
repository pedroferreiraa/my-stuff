#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*
 * This program checks if a number is prime.
*/

int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "Use: %s PrimeNumber\n", argv[0]);
		return EXIT_FAILURE;
	}

	uint64_t i = 2;
	uint64_t number = strtol(argv[1], NULL, 10);
	int32_t FLAG = 0;


	while (((FLAG = number % i), FLAG != 0) && i < number - 1) {
		i++;
	}

	FLAG != 0 ? printf("Is prime\n") : printf("Not prime\n");

	return 0;
}
