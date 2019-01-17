#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> v)
{
	vector<int>::iterator it;
	for (it = v.begin(); it != v.end(); it++)
	{
		cout << *it;
	}
	cout << endl;
}

int main()
{
	int N = 4;
	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	print(v);

	vector<int>::iterator it = v.begin();
	*it = 3;	//v[0]=3
	it++;
	(*it)++;	//v[1]++

	print(v);
	return 0;
}