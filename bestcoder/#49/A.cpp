/*************************************************************************
	> File Name: code/bc/#49/A.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月01日 星期六 18时59分20秒
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
#define y0 abc111qqz
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define tm crazy111qqz
#define lr dying111qqz
using namespace std;
#define REP(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef unsigned long long ULL;
const int inf = 0x7fffffff;
const int N=1E6+7;
int a,b[25];
int n;
int d[N];
bool cmp(int x,int y)
{
    if (x>y) return true;
    return false;
}
void bfs()
{
    memset(d,-1,sizeof(d));
    queue<int>x;
    x.push(a);
    d[a] = 0;
    while (!x.empty())
    {
	int px = x.front();x.pop();

//	cout<<"px:"<<px<<endl;
	if (px==0)
	{
	    return;
	}
	for ( int i = 1 ; i <= n ; i++)
	{
	  //  cout<<"i:"<<i<<" b[i]:"<<b[i]<<endl;
	    if (b[i]<=px&&d[px%b[i]]==-1)
	    {
		d[px%b[i]]=d[px]+1;
	//	cout<<"asdasd:"<<px%b[i]<<endl;
		x.push(px%b[i]);
	    }
	}
    }
}
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
	scanf("%d %d",&n,&a);
	for ( int i = 1; i <= n ; i++)
	{
	    scanf("%d",&b[i]);
	}
	sort(b+1,b+n+1,cmp);
	bfs();
	if (d[0]==-1)
	{
	    cout<<-1<<endl;
	}
	else
	{
	    cout<<d[0]<<endl;
	}
    }
  
	return 0;
}
