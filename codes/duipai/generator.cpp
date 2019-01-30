#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
  freopen("in.txt", "w", stdout);
  srand(time(NULL));
  for (int i = 0; i < 100; i++)
  {
    printf("%d %d\n", rand() % 1000000, rand() % 1000000);
  }
}
