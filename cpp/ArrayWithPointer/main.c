#include <stdio.h>
#include <stdlib.h>

void printArr (int arr[]);

int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  printArr(arr);

  return 0;
}

void printArr(int arr[]) {

    int indexChk;

    for (indexChk = 0; indexChk < 10; ++indexChk) {
        printf("%d ", *(arr + indexChk));
    }

    return;


}
