#include <stdio.h>
#include <stdlib.h>

void reverse (int arr[]);

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    reverse(arr);

    return 0;
}

void reverse(int arr[]) {

    int index, tmp;

    for (index = 0; index < 5; ++index) {

        tmp = *(arr + index);
        *(arr + index) = *(arr + (9 - index));
        *(arr + (9 - index)) = tmp;

    }

    for (index = 0; index < 10; ++index) {

        printf("%d ", *(arr + index));
    }

    return;

}
