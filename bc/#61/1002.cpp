/*************************************************************************
	> File Name: code/bc/#61/1002.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月31日 星期六 18时55分41秒
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
#include<cctype>
                 
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ms(a,x) memset(a,x,sizeof(a))
using namespace std;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;
const int N=1E4+7;
int n,s,t;

bool vis[N];

struct node
{
    int x;
    int d;

    bool ok()
    {
	if (x>=1&&x<=n&&!vis[x])
	    return true;
	return false;

    }
}beg;
bool bfs()
{
    queue<node>q;
    ms(vis,false);
    beg.x = s;
    beg.d = 0 ;
    q.push(beg);
    vis[s] = true;

    while (!q.empty())
    {
	node pre = q.front();
	q.pop();
	cout<<"pre.x:"<<pre.x<<endl;

	if (pre.x==t)
	{
	    printf("%d\n",pre.d);
	    return true;
	}
	
	for ( int i = 0 ; i < 4 ; i++)
	{
	    node next;
	    next.x = pre.x;
	    next.d = pre.d;

	    if (i==0)
	    {
		next.x++;
		if (next.ok())
		{
		    q.push(next);
		    vis[next.x] = true;
		}
	    }
	    if (i==1)
	    {
		next.x--;
		if (next.ok())
		{
		    q.push(next);
		    vis[next.x] = true;
		}
	    }
	    if (i==2)
	    {
		next.x = 1;
		next.d++;
		if (next.ok())
		{
		    q.push(next);
		    vis[next.x] = true;
		}
	    }
	    if (i==3)
	    {
		next.x = n ;
		next.d++;
		if (next.ok())
		{
		    q.push(next);
		    vis[next.x] = true;
		}
	    }
	}
    }
    return false;
}
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif

   while (scanf("%d %d %d",&n,&s,&t)!=EOF)
    {
	if (!bfs())
	{
	    puts("-1");
	}
    }
  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
