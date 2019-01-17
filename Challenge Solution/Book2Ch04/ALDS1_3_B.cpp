#include <iostream>
#include <cstring>

const int LEN = 100005;

typedef struct pp
{
	char name[100];
	int t;
} P;

P Q[LEN];

int head, tail, n;

void enqueue(P x)
{
	Q[tail] = x;
	tail = (tail + 1) % LEN;
}

P dequeue()
{
	P x = Q[head];
	head = (head + 1) % LEN;
	return x;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	using namespace std;
	int elaps = 0, c;
	int q;
	P u;
	cin >> n >> q;
	for (int i = 0; i < n; i++)
	{
		cin >> Q[i].name;
		cin >> Q[i].t;
	}
	head = 0, tail = n;
	while (head != tail)
	{
		u = dequeue();
		c = min(q, u.t);	//execute for time q or u.t
		u.t -= c;			//calculate the remaining time
		elaps += c;			//calculate the time elapsed
		if (u.t > 0)enqueue(u);
		else cout << u.name << ' ' << elaps << endl;
	}
	return 0;
}