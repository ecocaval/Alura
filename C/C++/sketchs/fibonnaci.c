#include <stdio.h>

#define TOP_LIMIT 1000

void main()
{
    int n0 = 0;
    int n1 = 1;

    printf("\n%d\n", n0);
    printf("\n%d\n", n1);

    call_fibonacci(0, 1);
}

void call_fibonacci(int n0, int n1)
{
    int n2;
    n2 = n1 + n0;

    if(n2 > TOP_LIMIT) return;

    printf("\n%d\n", n2);
    
    call_fibonacci(n1, n2);
}