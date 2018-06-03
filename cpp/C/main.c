#include <stdio.h>
#include <stdlib.h>

void swap(int * a, int * b);

int main()
{
    int a, b;

   scanf("%d", &a);
   scanf("%d", &b);

   printf("a : %d, b : %d \n", a, b);

   swap(&a, &b);
   printf("a : %d, b : %d \n", a, b);

    return 0;

}

void swap(int * a, int * b) {

    int tmp = *a;
    *a = *b;
    *b = tmp;

    return;

}
