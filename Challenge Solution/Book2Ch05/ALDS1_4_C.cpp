#include <cstdio>
#include <cstring>

const int M = 1046527;
const int L = 14;

char H[M][L];
int getChar(char ch);
long long getKey(char str[]);
int h1(int key) { return key % M; }
int h2(int key) { return 1 + (key % (M - 1)); }
int find(char str[]);
void insert(char str[]);

int main()
{
	int i, n, h;
	char str[L], com[9];
	for (i = 0; i < M; i++)
	{
		H[i][0] = '\0';
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s %s", com, str);
		if (com[0] == 'i')
		{
			insert(str);
		}
		else
		{
			if (find(str))
			{
				printf("yes\n");
			}
			else
			{
				printf("no\n");
			}
		}
	}
	return 0;
}

//turn the characters into numbers
int getChar(char ch)
{
	switch (ch)
	{
	case 'A':
		return 1;
		break;
	case 'C':
		return 2;
		break;
	case 'G':
		return 3;
		break;
	case 'T':
		return 4;
		break;
	default:
		return 0;
	}
}

//turn the string into numbers and calculate key
//formula for calculating key: getchar(str[i])*(5^(i))
long long getKey(char str[])
{
	long long sum = 0, p = 1, i;
	for (i = 0; i < strlen(str); i++)
	{
		sum += p*getChar(str[i]);
		p *= 5;
	}
	return sum;
}

int find(char str[])
{
	long long key, h, i;
	key = getKey(str);
	for (i = 0;; i++)
	{
		h = (h1(key) + i*h2(key)) % M;
		if (strcmp(H[h], str) == 0)
		{
			return 1;
		}
		else if (strlen(H[h]) == 0)
		{
			return 0;
		}
	}
	return 0;
}

void insert(char str[])
{
	long long key, h, i;
	key = getKey(str);
	for (i = 0;; i++)
	{
		h = (h1(key) + i*h2(key)) % M;
		//if the argument is the same as the element as in h(k), return
		if (strcmp(H[h], str) == 0)
		{
			return;
		}
		else if (strlen(H[h]) == 0)
		{
			strcpy(H[h], str);
			return;
		}
	}
	return;
}