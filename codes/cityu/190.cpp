#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

bool isdigit(char c)
{
  return (0 <= c - '0' && c - '0' <= 9);
}

int precedence(char c)
{
  if (c == '+' || c == '-') return 1;
  else if (c == '*' || c == '/') return 2;
  else return 3;
}

int main()
{
  int T;
  scanf("%d", &T);
  getchar();
  getchar();
  while (T--)
  {
    int cnt = 0;
    char temp[3], str[55];
    while (fgets(temp, 3, stdin))
    {
      if (temp[0] == '\n') break;
      str[cnt++] = temp[0];
    }
    str[cnt] = '\0';
    stack<char> s;
    for (int i = 0; str[i] != '\0'; i++)
    {
      if (isdigit(str[i]))
      {
        putchar(str[i]);
      }
      else if (s.empty() || str[i] == '(' || (precedence(str[i]) > precedence(s.top())
                        && (str[i] != ')')))
      {
        s.push(str[i]);
      }
      else if (str[i] == ')')
      {
        while (s.top() != '(' && !s.empty())
        {
          putchar(s.top());
          s.pop();
        }
        if (s.top() == '(') s.pop();
      }
      else
      {
        while (!s.empty() && precedence(str[i]) <= precedence(s.top()) && s.top() != '(')
        {
          putchar(s.top());
          s.pop();
        }
        s.push(str[i]);
      }
    }
    while (!s.empty())
    {
      putchar(s.top());
      s.pop();
    }
    printf("\n");
    if (T > 0)
    {
      printf("\n");
    }
  }
  return 0;
}
