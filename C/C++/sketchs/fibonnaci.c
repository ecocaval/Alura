#include <stdio.h>

#define TOP_LIMIT 1000
#define STARTING_N0 0
#define STARTING_N1 1

void main()
{
    printf("\n%d\n", STARTING_N0);
    printf("\n%d\n", STARTING_N1);

    call_fibonacci(STARTING_N0, STARTING_N1);
}

void call_fibonacci(int n0, int n1)
{
    int n2;
    n2 = n1 + n0;

    if(n2 > TOP_LIMIT) return;

    printf("\n%d\n", n2);
    
    call_fibonacci(n1, n2);
}