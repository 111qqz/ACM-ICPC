/*************************************************************************
	> File Name: code/2015summer/0714/G.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月15日 星期三 17时17分04秒
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
const int N=10;
bool flag;
bool vis[N][N];
int dirx[8]={-2,-2,-1,-1,1,1,2,2};
int diry[8]={-1,1,-2,2,-2,2,-1,1};
int recx[50],recy[50];
int p,q;
int num;
bool ok(int xxx,int yyy)
{
    if (xxx>0&&xxx<=p&&yyy>0&&yyy<=q&&!vis[xxx][yyy])
	  return true;
    return false;
}

void dfs( int x,int y,int num)
{
		recx[num] = x;
		recy[num] = y;
		if (num==p*q)
		{
		    flag = true;
		    return ;
		}
		for ( int i = 0 ; i < 8 ;i++)
		{
		    int tmpx = x + dirx[i];
		    int tmpy = y + diry[i];
		    if (ok(tmpx,tmpy)&&!flag)
		    {
			  vis[tmpx][tmpy]=true;
			  dfs(tmpx,tmpy,num+1);
			  vis[tmpx][tmpy]=false;
		    }
		}
}
int main()
{
    int T;
    int cas = 0;
    cin>>T;
    while (T--)
    {
	  flag = false;
	  memset(recx,0,sizeof(recy));
	  memset(recy,0,sizeof(recy));
	  cas++;
	  memset(vis,false,sizeof(vis));
	  scanf("%d%d",&q,&p);
	  vis[1][1]= true;
	  printf("Scenario #%d:\n",cas);
	  dfs(1,1,1);
	  if (flag)
	  {

		for ( int i = 1 ;  i <= p*q ; i++)
		{
		   // cout<<char(recx[i]+64)<<recy[i];
		      printf("%c%d",recx[i]+64,recy[i]);
		}

		cout<<endl;
	  }
	  else
	  {		
		cout<<"impossible"<<endl;
	  }
	  cout<<endl;

    }
    return 0;
}
