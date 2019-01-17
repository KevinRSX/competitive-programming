#include <iostream>
#include <cstdio>

int S[1000], top;
// 1 2 + 3 4 - *
void push(int x)
{
	S[++top] = x;
}

int pop()
{
	top--;
	return S[top + 1];
}

int main()
{
	using namespace std;
	char str[200];
	int a, b;
	top = 0;
	while (cin >> str)
	{
		switch (str[0])
		{
		case '+':
			b = pop();
			a = pop();
			push(a + b);
			break;
		case '-':
			b = pop();
			a = pop();
			push(a - b);
			break;
		case '*':
			b = pop();
			a = pop();
			push(a * b);
			break;
		case '/':
			b = pop();
			a = pop();
			push(a / b);
			break;
		default:
			push(atoi(str));
		}
	}
	cout << pop() << endl;
	return 0;
}