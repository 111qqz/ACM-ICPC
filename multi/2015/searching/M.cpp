/*************************************************************************
	> File Name: code/2015summer/searching/M.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月25日 星期六 15时54分19秒
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
const int N=1E2+2;
int s,m,n;
int a[10];
int lim[10];
int f[5][5];
int d[N][N][N];
int ans;
void bfs()
{
    queue<int>q[10];
    memset(d,-1,sizeof(d));
    q[0].push(s);
    q[1].push(0);
    q[2].push(0);
    d[s][0][0]=0;
    int ne[4];
    memset(ne,0,sizeof(ne));
    while (!q[1].empty()&&!q[2].empty())
    {
	  int p[3];
	  p[0]=q[0].front();q[0].pop();
	  p[1]=q[1].front();q[1].pop();
	  p[2]=q[2].front();q[2].pop();
	 // cout<<p[0]<<" "<<p[1]<<" "<<p[2]<<"d:"<<d[p[0]][p[1]][p[2]]<<endl;;
	  for ( int i = 0 ;  i < 3  ; i++ )
	  {
		if (p[i]==0) continue;
		for ( int j = i+1  ;  j < 3 ; j++ )
		{
		
		    if (p[i]==p[j]&&p[i]+p[j]==s)
		    {
			 // cout<<"fufffffffffffffffffffffffff"<<endl;
			  ans = d[p[0]][p[1]][p[2]];
			//  cout<<"ans:"<<ans<<endl;
			  return;
		    }
		}
	  }
	  for ( int i = 0  ; i < 3 ; i++ )   //i往j里倒
	  {
		if (p[i]==0) continue;  //为空时不能往其他里倒
		for ( int j = 0 ;  j < 3 ; j++ )
		{
	  
		    if(i==j)continue;//不能自己往倒给自己
		    if (p[j]==lim[j]) continue;//被倒的为满时不能倒入
		    if (p[i]+p[j]<=lim[j])//可以完全倒入
		    {
			  int k = f[i][j];
			  ne[i]=0;
			  ne[j]=p[i]+p[j];
			  ne[k]=p[k];
			  if (d[ne[0]][ne[1]][ne[2]]!=-1) continue;  //出现重复
			  q[i].push(0);
			  q[j].push(p[i]+p[j]);
			  q[k].push(p[k]);
			  d[ne[0]][ne[1]][ne[2]]=d[p[0]][p[1]][p[2]]+1;
		    }
		    else  // 不能完全倒入
		    {
			  int k = f[i][j];
			  ne[i]=p[i]-(lim[j]-p[j]);
			  ne[j]=lim[j];
			  ne[k]=p[k];
			  if (d[ne[0]][ne[1]][ne[2]]!=-1) continue; //出现重复
			  q[i].push(ne[i]);
			  q[j].push(ne[j]);
			  q[k].push(ne[k]);
			  d[ne[0]][ne[1]][ne[2]]=d[p[0]][p[1]][p[2]]+1;
		    }
		}
	  }
    }
}
int main()
{
    f[0][1]=2;
    f[0][2]=1;
    f[1][2]=0;
    f[1][0]=2;
    f[2][0]=1;
    f[2][1]=0;
    while (scanf("%d %d %d",&s,&m,&n)!=EOF)
    {
	  ans = -1;
	  if (s==0&&n==0&&m==0) break;
	  if (s%2==1)
	  {
		cout<<"NO"<<endl;
		continue;
	  }
	  lim[0] = s;
	  lim[1] = m;
	  lim[2] = n;
	  bfs();
	  if (ans==-1)
	  {
		cout<<"NO"<<endl;
	  }
	  else
	  {
		cout<<ans<<endl;
	  }
    }
  
	return 0;
}
