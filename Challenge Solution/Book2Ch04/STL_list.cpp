#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<char> L;
	L.push_front('b');	//[b]
	L.push_back('c');	//[bc]
	L.push_front('a');	//[abc]

	cout << L.front();	//a
	cout << L.back();	//c

	L.pop_front();		//[bc]
	L.push_back('d');	//[bcd]

	cout << L.front();	//b
	cout << L.back() << endl;	//d

	return 0;
}