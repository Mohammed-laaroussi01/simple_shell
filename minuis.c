#include <stdio.h>

/**
 * mun - substraction of two numbers.
 * @N1: the first number.
 * @N2: the second number.
 *
 * Return: the result of the substraction.
 *
 * description: fonction that makes substraction
 *		 of two integers and return the result.
 */

int mun(int N1, int N2)
{
	return (N1 - N2);
}

/*
 * main - Entry point of the program
 *
 * Return: always 0 (success)
 *
 * Description: print the result by using the fonction mun
 */
int main(void)
{
	int result = mun(10, 5);

	printf("the result is %d\n", result);

	return (0);
}
