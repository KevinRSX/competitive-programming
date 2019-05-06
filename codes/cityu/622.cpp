#include<cstdio>
#include<cstring>
#include<algorithm>
const int MAXN = 1005;
using namespace std;
char s[MAXN];
int N, M, rak[MAXN], sa[MAXN], tax[MAXN], tp[MAXN], Height[MAXN];
void GetHeight()
{
    int j, k = 0;
    for(int i = 1; i <= N; i++)
    {
        if(k) k--;
        j = sa[rak[i] - 1];
        while(s[i + k] == s[j + k]) k++;
        Height[rak[i]] = k;
    }
}
void radixsort()
{
    for (int i = 0; i <= M; i++) tax[i] = 0;
    for (int i = 1; i <= N; i++) tax[rak[i]]++;
    for (int i = 1; i <= M; i++) tax[i] += tax[i - 1];
    for (int i = N; i >= 1; i--) sa[ tax[rak[tp[i]]]-- ] = tp[i];
}
void SuffixSort()
{
    M = 75;
    for (int i = 1; i <= N; i++) rak[i] = s[i] - '0' + 1, tp[i] = i;
    radixsort();
    for (int w = 1, p = 0; p < N; M = p, w <<= 1)
    {
        p = 0;
        for (int i = 1; i <= w; i++) tp[++p] = N - w + i;
        for (int i = 1; i <= N; i++) if (sa[i] > w) tp[++p] = sa[i] - w;
        radixsort();
        std::swap(tp, rak);
        rak[sa[1]] = p = 1;
        for (int i = 2; i <= N; i++)
            rak[sa[i]] = (tp[sa[i - 1]] == tp[sa[i]] && tp[sa[i - 1] + w] == tp[sa[i] + w]) ? p : ++p;
    }
}
int main()
{
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    #endif
    int n;
    scanf("%d", &n);
    while (n--)
    {
      scanf("%s", s + 1);
      N = strlen(s + 1);
      SuffixSort();
      GetHeight();
      int len = 0, count = 0;
      for (int i = 1; i <= N; i++)
      {
        len = len > Height[i] ? len : Height[i];
      }
      if (len == 0) printf("No repetitions found!\n");
      else
      {
        for (int i = 1; i <= N; i++)
        {
          if (len == Height[i])
          {
            for (int j = 0; j < len; j++)
            {
              printf("%c", s[sa[i] + j]);
            }
            while (i <= N && len == Height[i])
            {
              i++;
              count++;
            }
            break;
          }
        }
        printf(" %d\n", count + 1);
      }
    }
    return 0;
}
