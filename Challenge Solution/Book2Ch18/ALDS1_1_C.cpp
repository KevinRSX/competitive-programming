#include <iostream>
typedef long long ll;
bool isPrime(ll a);

int main()
{
	using namespace std;
	ll A[10001];
	int n, prime = 0;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> A[i];
		if (isPrime(A[i]))
		{
			prime++;
		}
	}
	cout << prime << endl;
	return 0;
}

bool isPrime(ll a)
{
	for (ll i = 2;i*i <= a;i++)
	{
		if (a%i == 0)
		{
			return false;
		}
	}
	return true;
}