/*************************************************************************
	> File Name: code/2015summer/0713B.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月13日 星期一 14时14分27秒
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
const int N=1E4+5;
int T,n,m;
int f[N];
struct node
{
    int a,b,c;
}r[N];
bool cmp(node x,node y)
{
    if (x.c<y.c) return true;
    return false;
}
void init()
{
    for ( int i = 0 ; i < N ; i++)
	  {
		f[i]=i;
		r[i].a=0;
		r[i].b=0;
		r[i].c=9999999;
	  }
}
int root(int x)
{
    if (x==f[x]) return x;
    else return f[x]=root(f[x]);
}
int main()
{
	cin>>T;
	while (T--)
	{
	    init();
	    scanf("%d%d",&n,&m);
	    for ( int i = 1 ; i <= n ; i++)
	    {
		  scanf("%d%d%d",&r[i].a,&r[i].b,&r[i].c);
	    }
	    sort(r+1,r+n+1,cmp);
	    LL ans = 0;
	    int cnt =0;
	    bool flag=false;
	    for (int i = 1 ; i <= n ; i++)
	    {
		  int x=root(r[i].a);
		  int y=root(r[i].b);
		  if (x!=y)
		  {
			cnt++;
			ans = ans + r[i].c;
			f[x]=y;
		  }
		  if (cnt==m-1)
		  {
			flag=true;
			break;
		  }
	    }
	    if (flag)
	    {
		  cout<<ans<<endl;
	    }
	    else
	    {
		  cout<<"I'm not sure."<<endl;
	    }
	}
	return 0;
}
