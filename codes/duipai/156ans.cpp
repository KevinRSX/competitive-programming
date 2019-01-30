
#include <queue>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;

bool v[1000005];
queue<int> q;
int main(){
  freopen("in.txt", "r", stdin);
  freopen("out2.txt", "w", stdout);
    for(int i=2;i*i<=1000000;i++){
        if(v[i]==1)continue;
        for(int j=2*i;j<=1000000;j+=i){
            v[j]=1;
        }
    }
    int a,b;
    while (~scanf("%d%d",&a,&b) && a && b)
    {
      for(int i=a;i>=2;i--){
          if(v[i])continue;
          if(a%i==0)q.push(i);
      }
      int ans1=q.front();
      q.pop();
      while(!q.empty()){
          ans1-=q.front();
          q.pop();
      }
      for(int i=b;i>=2;i--){
          if(v[i])continue;
          if(b%i==0)q.push(i);
      }
      int ans2=q.front();
      q.pop();
      while(!q.empty()){
          ans2-=q.front();
          q.pop();
      }
      cout<<ans1<<' ';
      cout<<ans2<<endl;
      printf("%c\n",ans1>ans2?'a':'b');
    }
    return 0;
}
