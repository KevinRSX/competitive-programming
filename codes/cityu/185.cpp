#include <cstdio>
#include <set>
#include <cctype>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

int main()
{
  #ifdef DEBUG
  freopen("in.txt", "r", stdin);
  #endif
  set<string> S;
  string temp, in;
  while (cin >> in)
  {
    //cout << "got " << in << endl;
    for (int i = 0; i < in.length(); i++)
    {
      if (isalpha(in[i])) in[i] = tolower(in[i]);
      else in[i] = ' ';
    }
    stringstream stin(in);
    while (stin >> temp) S.insert(temp);
  }
  for (set<string>::iterator it = S.begin(); it != S.end(); it++)
  {
    cout << *it << endl;
  }
  return 0;
}
