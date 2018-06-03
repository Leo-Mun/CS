#include<cstdio>
#include<stack>
#include <cstring>

#define MAX_LEN 80

using namespace std;

int main() {
   char str[MAX_LEN];
   while (fgets(str, sizeof(str), stdin)) {
      stack < char > st;
      int len = strlen(str) - 1;
      for (int i = 0;i < len;i++) {
         if (str[i] == '(' || str[i] == '{' || str[i] == '[')
            st.push(str[i]);
         else if (str[i] == ')') {
            if (st.top() == '(')
               st.pop();
            else
               break;
         }
         else if (str[i] == ']') {
            if (st.top() == '[')
               st.pop();
            else
               break;
         }
         else if (str[i] == '}') {
            if (st.top() == '{')
               st.pop();
            else
               break;
         }
      }
      if (st.empty())
         printf("balanced\n");
      else
         printf("unbalanced\n");
   }
}
