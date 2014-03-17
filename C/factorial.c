#include <stdio.h>

int factorial(int);

int
main()
{
    factorial(10);
}

int
factorial(int n)
{
    if (n <= 1) {
	return 1;
    } else {
	return n * factorial(n-1);
    }
}
