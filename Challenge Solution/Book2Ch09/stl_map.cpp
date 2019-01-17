#include <iostream>
#include <map>
#include <string>

using namespace std;

void print(map<string, int> M)
{
	map<string, int>::iterator it;
	cout << M.size() << endl;
	for (it = M.begin(); it != M.end(); it++)
	{
		pair<string, int> item = *it;
		cout << item.first << " --> " << item.second << endl;
	}
}

int main()
{
	map<string, int> M;
	M["red"] = 32;
	M["blue"] = 688;
	M["yellow"] = 122;
	M["blue"] += 312;
	print(M);

	M.insert(make_pair("zebra", 101010));
	M.insert(make_pair("white", 0));
	M.erase("yellow");
	print(M);

	pair<string, int> target = *M.find("red");
	cout << target.first << " --> " << target.second << endl;
	return 0;
}