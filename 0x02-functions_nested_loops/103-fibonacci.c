#include <stdio.h>

/**
 * fib - function fibonacci
 * main - main function without para
 *
 * @n: number of
 * Return: always 0
 */


int fib(int n)
{
	if (n <= 1)
		return (n);
	return (fib(n - 1) + fib(n - 2));
}

int main(void)
{
	int n = 9;
	printf("%d", fib(n));
	getchar(0);
	return (0);
}

