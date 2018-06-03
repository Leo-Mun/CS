#include <cstdio>
#include <iostream>
#include <cstring>

#define MAX_LEN 80

bool isPelindronm(char * str, int start, int end) {
   if (start >= end)
      return true;
   return str[start] == str[end] && isPelindronm(str, start + 1, end - 1);
}

int main() {
   char str[MAX_LEN];
   while (fgets(str, sizeof(str), stdin)) {
      if (isPelindronm(str, 0, strlen(str) - 2))
         printf("True\n");
      else
         printf("False\n");
   }
}
