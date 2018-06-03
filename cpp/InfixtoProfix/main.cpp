#include "infixADT.cpp"
#include "infix.h"


using namespace std;

int main() {
   char str[MAX_LEN];

   cout << "Enter the data : ";

   while (fgets(str, sizeof(str), stdin)) {
      Stack MStack;
      int len = strlen(str) - 1;

        for (int i = 0; i < len; i++)
        {
            cout << str[i];
        }
        cout << endl;

      for (int i = 0;i < len;i++) {

         if (str[i] == '(' || str[i] == '{' || str[i] == '[')
            MStack.push(str[i]);
         else if (str[i] == ')') {
            if (MStack.top == '(')
               MStack.pop();
            else
               break;
         }
         else if (str[i] == ']') {
            if (MStack.top == '[')
               MStack.pop();
            else
               break;
         }
         else if (str[i] == '}') {
            if (MStack.top == '{')
               MStack.pop();
            else
               break;
         }
      }
      if (MStack.isEmpty())
         printf("balanced\n");
      else
         printf("unbalanced\n");



   }
}
