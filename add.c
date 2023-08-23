#include <stdio.h>

/**
 * add - Add two numbers.
 * @nu1: The first number.
 * @nu2: The second number.
 *
 * Return: The sum of num1 and num2.
 *
 * Description: This function adds two integers and returns the result.
 */
int add(int nu1, int nu2)
{
	return (nu1 + nu2);
}

/**
 * main - Entry point of the program.
 *
 * Return: Always 0 (success).
 *
 * Description: This function demonstrates the use of the 'add' function
 *		by adding two numbers and printing the result.
 */
int main(void)
{
	int result = add(17, 5);

	printf("The sum of 10 and 5 is %d\n", result);

	return (0);
}

