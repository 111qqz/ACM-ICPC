/*************************************************************************
	> File Name: code/2015summer/0718/B.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月18日 星期六 11时58分14秒
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
const int N=2E3+5;
struct node
{
    int x,y;
};
struct node rec,rec2;
struct node par[N],par2[N];
struct node toy[N];
int ans[N],cnt[N];
int n,m;
bool judge(node p1,node p2,node p3) //判断点是否在直线的[右侧!!]
{
    int s = (p1.x-p3.x)*(p2.y-p3.y)-(p1.y-p3.y)*(p2.x-p3.x);
    if (s>0) return false;
    if (s<0) return true;
}
bool cmp(node a,node b)
{
    if (a.x<b.x) return true;
    if (a.x==b.x&&a.y<b.y) return true;
    return false;
}
int main()
{
    while (scanf("%d",&n)!=EOF&&n)
    {
	  memset(ans,0,sizeof(ans));
	  memset(par,0,sizeof(par));
	  memset(par2,0,sizeof(par2));
	  memset(toy,0,sizeof(toy));
	  cin>>m>>rec.x>>rec.y>>rec2.x>>rec2.y;
	  for ( int i = 1 ;  i <= n ; i++)
	  {
		cin>>par[i].x>>par2[i].x;
		par[i].y=rec.y;
		par2[i].y=rec2.y;
	  }
	  for ( int i = 1 ; i <= n-1 ; i++)
	  {
		for ( int j = i+1 ; j <= n ; j++)
		{
		    if (par[i].x>par[j].x)
		    {
			  swap(par[i].x,par[j].x);
		    //  swap(par[i].y,par[j].y);
			  swap(par2[i].x,par2[j].x);
		    //   swap(par2[i].y,par2[j].y);
		    }
		}
	  }
//	  for ( int i = 1 ;  i <= n ; i++)
//		cout<<par[i].x<<endl;
	  for ( int i = 1 ;  i <= m ; i++ )
	   {
		cin>>toy[i].x>>toy[i].y;
	   }
	  int p;
	  sort(toy+1,toy+m+1,cmp);  //如果第i个娃娃在第k个分划中,那么排序后第i+1个娃娃至少在第k个分划中....(某大神说过,顺手就能写的优化顺手	
//	  for ( int i = 1 ; i <= m ; i++)  cout<<"x[i]:"<<toy[i].x<<" y[i]:"<<toy[i].y<<endl;
	  for ( int i = 1 ; i  <= m ;  i++) 
	  {
		p = n + 1;  //如果在所有board的右侧,那么一定是在最后一个分划中(n个板子形成n+1个分划)
		bool ok=false;
		for ( int j = 1 ; j  <= n ; j++)
		{
		    ok=judge(par2[j],par[j],toy[i]);
		    if (!ok)
		    {
		//	  cout<<"i:"<<i<<" j:"<<j<<" "<<par2[j].x<<" "<<par2[j].y<<" "<<par[j].x<<" "<<par[j].y<<endl;
			  p = j;
			  break;
			//    cout<< "hhhhhh"<<"I:"<<i<<" j:"<<j<<endl;
		    }
		}
		ans[p]++;
	  }
	  cout<<"Box"<<endl;
	  memset(cnt,0,sizeof(cnt));
	  for ( int i = 1 ; i <= n+1 ; i++)
	  {
		if (ans[i]==0) continue;
		cnt[ans[i]]++;
	//	printf("%d: %d\n",i,ans[i]);
	  }
	  for ( int i = 1 ; i <= m ;  i++)
	  {
		if (cnt[i]==0) continue;
	  	printf("%d: %d\n",i,cnt[i]);
	  }
    }
    return 0;
}
