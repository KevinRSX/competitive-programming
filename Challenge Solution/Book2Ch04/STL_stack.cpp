#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<int> S;
	S.push(3);
	S.push(7);
	S.push(1);	//push 3,7,1 respectively into stack
	cout << S.size() << " ";	//show the size of the stack: 3
	cout << S.top() << " ";	//1
	S.pop();	//delete the element on the top of the stack
	cout << S.top() << " ";	//7
	S.pop();
	cout << S.top() << " ";	//3
	S.push(5);
	cout << S.top() << " ";	//5
	S.pop();
	cout << S.top() << endl;	//3
	return 0;
}