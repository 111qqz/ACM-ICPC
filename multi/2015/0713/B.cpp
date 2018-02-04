/*************************************************************************
	> File Name: code/2015summer/0713/B.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com
	> Created Time: 2015年07月13日 星期一 10时46分26秒
 ************************************************************************/
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
#define REP(i, n) for (int i=0;i<int(n);++i)
typedef long long LL;
typedef unsigned long long ULL;
const int N=1E2+5;
const int inf=0x7fffffff;
int T,m,n,f[N];
struct node
{
    int from,to,cost;
}c[N];
bool cmp(node a,node b)
{
    if (a.cost<b.cost) return true;
    return false;
}
int root (int x)
{
    if (x==f[x]) return x;
    else return f[x]=root(f[x]);
}
void u(int x,int y)
{
   // if (x==y) return;
  //  else 
    f[root(x)]=root(y);
}
void init()
{
    for ( int i = 0 ; i <N ; i++ )
	  f[i]=i;
    for ( int i = 0 ; i < N ; i++ )
    {
	  c[i].from=0;
	  c[i].to=0;
	  c[i].cost=inf;
    }
}
int main()
{
    cin>>T;
    while ( T-- )
    {
	  init();
	  memset(c,0,sizeof(c));
	  scanf("%d %d",&m,&n);
	  for  ( int i = 1 ; i <= m ; i++)
	  {
		scanf("%d %d %d",&c[i].from,&c[i].to,&c[i].cost);
	  }
	  sort(c+1,c+m+1,cmp);
	  int cnt = 0;
	  int ans = 0;
	  int k = 0;
	 // cout<<"***1**"<<endl;
        bool flag=false;
	  for ( int i = 1 ; i <= m ; i++ )
      {
         // cout<<"i:"<<i<<endl;
          if (root(c[i].from)!=root(c[i].to))
          {
              cnt++;
		  if (c[i].from>c[i].to) u(c[i].to,c[i].from );
		  else
		     u(c[i].from,c[i].to);
              ans = ans + c[i].cost;
          }
           if (cnt==n-1) {flag = true; break;}
      }
      if (flag)
	  cout<<ans<<endl;
	  else cout<<"I'm not sure."<<endl;
    }
	return 0;
}
