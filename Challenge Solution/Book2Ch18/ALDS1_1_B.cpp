#include <iostream>

typedef long long ll;
template<typename T>
T GCD(T p, T q);

int main()
{
	using namespace std;
	ll a, b;
	cin >> a >> b;
	if (a < b)
	{
		ll temp = a;
		a = b;
		b = temp;
	}
	cout << GCD(a, b) << endl;
	return 0;
}


template<typename T>
T GCD(T p, T q)
{
	if (q == 0)
	{
		return p;
	}
	return GCD(q, p % q);
}