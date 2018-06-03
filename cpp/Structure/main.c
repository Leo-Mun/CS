#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {

    int studentId;
    char name[20];

} Student;


int compare (Student *, Student *);
int BSearch (Student arr[], int target);
void printArr (Student arr[]);


int main()
{
    Student students[10] = { {20170040, "���ٹ�"},{20170003, "�����"}, {20170002, "��â��"}, {2017000, "�谡��"}, {20170011, "������"}, {20170010, "������"},
                            {20170013, "�ȼ���"}, {20173315, "������"}, {20170241, "�迵��"}, {20173910, "�ۼ���"} };

    int target;

    printf("type the studentID : ");
    scanf("%d", &target);

    qsort(students, 10, sizeof(students[0]), compare);
    printArr(students);

    printf("\n");

    printf("%d \n", BSearch(students, target));

    return 0;
}

int compare(Student *studentId1, Student *studentId2) {
        if (studentId1->studentId < studentId2->studentId) {
            return -1;
        }

        else if (studentId1->studentId > studentId2->studentId) {
            return 1;
        }

        else
            return 0;
}

int BSearch(Student arr[], int target) {
    const int NOT_FOUND = -1;
    int left = 0, right = 9;
    while (left <= right) {
    int mid = (left + right) / 2;

        if (target == arr[mid].studentId) {
            return mid;
        }
        else if (target > arr[mid].studentId) {
            left = mid + 1;
        }
        else if (target < arr[mid].studentId) {
            right = mid - 1;
        }
    }

    return NOT_FOUND;
}

void printArr (Student arr[]) {
    int index;
    for (index = 0; index < 10; ++index) {
        printf("%d ", arr[index].studentId);
    }

}
