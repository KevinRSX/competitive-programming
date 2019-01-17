//lower_bound.cpp -- application of binary search algorithm in STL, returns the position of the first
//element greater than or equals to "key"
//Also, upper_bound(iterator start, iterator end, int key) returns the position of the first
//element greater than "key"
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int A[14] = { 1,1,2,2,2,4,5,5,6,8,8,8,10,15 };
	int *pos;
	int idx;
	pos = lower_bound(A, A + 14, 3);
	idx = distance(A, pos);
	cout << "A[" << idx << "] = " << *pos << endl;	//A[5] = 4

	pos = lower_bound(A, A + 14, 2);
	idx = distance(A, pos);
	cout << "A[" << idx << "] = " << *pos << endl;	//A[4] = 2

	return 0;
}

//another example
//consider the array A = [a,a,a,a,a,a,b,b,b,b,c,c,c,c]
//lower_bound(A.begin(), A.end(), b) returns &A[6] (position of the first b)
//upper_bound(A.begin(), A.end(), b) returns &A[10] (position of the first c)
//these two iterators indicates the lowest and highest position where we can insert an element into the given array