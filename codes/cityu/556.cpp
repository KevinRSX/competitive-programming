#include <iostream>
#include <cstring>
#include <stack>
#include <set>
using namespace std;
char infix[105], postfix[105];

struct bvalue
{
  bool value;
  bool appear;
};

bvalue ab[25];
set<int> appear;

int precedence(char c)
{
  if (c == '+') return 1;
  else if (c == '&') return 2;
  else return 3;
}

bool isvar(char c)
{
  return 'a' <= c && c <= 'z';
}

void infix_to_postfix()
{
  stack<char> s;
  memset(postfix, '\0', sizeof(postfix));
  int j = 0;
  for (int i = 0; infix[i] != '\0'; i++)
  {
    if (infix[i] == ' ') continue;
    if (isvar(infix[i]))
    {
      postfix[j++] = infix[i];
      ab[int(infix[i] - 'a')].appear = true;
      appear.insert(int(infix[i] - 'a'));
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

void setVal(int r)
{
  for (set<int>::iterator i = appear.begin(); i != appear.end(); i++)
  {
    int alpha_val = (*i);
    ab[alpha_val].value = (r & 1);
    r >>= 1;
    //printf("%d %c\n", ab[alpha_val].value, char(alpha_val + 'a'));
  }
  //printf("\n");
}

bool evaluate()
{
  stack<bool> s;
  for (int i = 0; i < strlen(postfix); i++)
  {
    if (isvar(postfix[i]))
    {
      int index = int(postfix[i] - 'a');
      s.push(ab[index].value);
    }
    else if (postfix[i] == '!')
    {
      bool q = s.top();
      s.pop();
      s.push(!q);
    }
    else if (postfix[i] == '&')
    {
      bool q1 = s.top();
      s.pop();
      bool q2 = s.top();
      s.pop();
      s.push(q1 && q2);
    }
    else if (postfix[i] == '+')
    {
      bool q1 = s.top();
      s.pop();
      bool q2 = s.top();
      s.pop();
      s.push(q1 || q2);
    }
  }
  return s.top();
}

int main()
{
  #ifdef DEBUG
  freopen("in.txt", "r", stdin);
  #endif
  while (cin.getline(infix, 105))
  {
    infix_to_postfix();
    bool sat = false;
    int p = (1 << appear.size());
    for (int i = 0; i < p; i++)
    {
      setVal(i);
      if (evaluate())
      {
        sat = true;
        break;
      }
    }
    if (sat) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}
