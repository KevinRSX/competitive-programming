#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

char infix[105], postfix[105], res[35];

bool isdigit(char c)
{
  return (0 <= c - '0' && c - '0' <= 9) || ('A' <= c && c <= 'F');
}

bool ishexdigit(char c)
{
  return ('A' <= c && c <= 'F');
}

int precedence(char c)
{
  if (c == '+' || c == '-') return 1;
  else if (c == '*' || c == '/') return 2;
  else return 3;
}

void infix_to_postfix()
{
  stack<char> s;
  memset(postfix, '\0', sizeof(postfix));
  int j = 0;
  for (int i = 0; infix[i] != '\0'; i++)
  {
    if (isdigit(infix[i]))
    {
      postfix[j++] = infix[i];
    }
    else if (s.empty() || infix[i] == '(' || (precedence(infix[i]) > precedence(s.top())
                      && (infix[i] != ')')))
    {
      s.push(infix[i]);
    }
    else if (infix[i] == ')')
    {
      while (s.top() != '(' && !s.empty())
      {
        postfix[j++] = s.top();
        s.pop();
      }
      if (s.top() == '(') s.pop();
    }
    else
    {
      while (!s.empty() && precedence(infix[i]) <= precedence(s.top()) && s.top() != '(')
      {
        postfix[j++] = s.top();
        s.pop();
      }
      s.push(infix[i]);
    }
  }
  while (!s.empty())
  {
    postfix[j++] = s.top();
    s.pop();
  }
  postfix[j] = '\0';
}

int calc(char opt, int left, int right)
{
  switch (opt)
  {
    case '+': return left + right; break;
    case '-': return right - left; break;
    case '*': return left * right; break;
    case '/': return right / left; break;
    default: return 0;
  }
}

int main()
{
  while (~scanf("%s", infix))
  {
    infix_to_postfix();
    stack<int> T;
    for (int i = 0; postfix[i] != '\0'; i++)
    {
      if (isdigit(postfix[i]))
      {
        if (ishexdigit(postfix[i]))
        {
          T.push(postfix[i] - 55);
        }
        else T.push(postfix[i] - '0');
      }
      else
      {
        int end1 = T.top();
        T.pop();
        int end2 = T.top();
        T.pop();
        T.push(calc(postfix[i], end1, end2));
      }
    }
    printf("%X\n", T.top());
  }
}
