#include <cstdio>
#include <cstdlib>
#include <cstring>

struct Node
{
	int key;
	Node *prev, *next;
};

Node *nil;
void init();
void insert(int key);
Node *listSearch(int key);
void deleteNode(Node *t);
void deleteFirst();
void deleteLast();
void deleteKey(int key);
void printList();

int main()
{
	int key, n, i;
	int size = 0;
	char com[20];
	int np = 0, nd = 0;
	scanf("%d", &n);
	init();
	for (i = 0; i < n; i++)
	{
		scanf("%s%d", com, &key);
		if (com[0] == 'i')
		{
			insert(key);
			np++;
			size++;
		}
		else if (com[0] == 'd')
		{
			if (strlen(com) > 6)
			{
				if (com[6] == 'F')
				{
					deleteFirst();
				}
				else
				{
					deleteLast();
				}
			}
			else
			{
				deleteKey(key);
				nd++;
			}
		}
	}
	printList();
	return 0;
}

void init()
{
	nil = new Node;
	nil->next = nil;
	nil->prev = nil;
}

void insert(int key)
{
	Node *x = new Node;
	x->key = key;
	x->next = nil->next;
	nil->next->prev = x;
	nil->next = x;
	x->prev = nil;
}

Node *listSearch(int key)
{
	Node *cur = nil->next;	//start from the first element after cur
	while (cur != nil&&cur->key != key)
	{
		cur = cur->next;	//move cur to the next element
	}
	return cur;
}

void deleteNode(Node *t)
{
	if (t == nil)
	{
		return;
	}
	t->prev->next = t->next;
	t->next->prev = t->prev;
	delete t;
}

void deleteFirst()
{
	deleteNode(nil->next);
}

void deleteLast()
{
	deleteNode(nil->prev);
}

void deleteKey(int key)
{
	deleteNode(listSearch(key));
}

void printList()
{
	Node *cur = nil->next;
	int isf = 0;
	while (1)
	{
		if (cur == nil)
		{
			break;
		}
		if ((isf++) > 0)
		{
			printf(" ");
		}
		printf("%d", cur->key);
		cur = cur->next;
	}
	printf("\n");
}