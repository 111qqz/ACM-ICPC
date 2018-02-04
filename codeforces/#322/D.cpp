/*************************************************************************
	> File Name: code/cf/#322/D.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年09月30日 星期三 17时21分24秒
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
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define ms(a,x) memset(a,x,sizeof(a))
#define lr dying111qqz
using namespace std;
#define For(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;
int ans;
struct Point
{
    int x,y;
}p[10];
char maze[110][110];
int ss;
int lst;
int a[10],b[10];
bool solve()
{
    if (lst==-1) return false;
 //   cout<<"lst:"<<lst<<endl;
    if (p[0].x+p[1].x+p[2].x==p[0].y&&p[0].y==p[1].y&&p[0].y==p[2].y)
    {
	ans = p[0].y;
	for ( int i = 0 ; i < p[0].x ; i++)
	{
	    for ( int j = 0 ; j < ans ; j++)
	    {
		maze[i][j] = 'A';
	    }
	}
	for ( int i = p[0].x ; i < p[0].x+p[1].x;i++)
	{
	    for ( int j = 0 ; j < ans ; j++)
	    {
		maze[i][j] = 'B';
	    }
	}
	for ( int i = p[0].x + p[1].x ; i < ans ; i++)
	{
	    for ( int j = 0 ; j < ans ; j++)
	    {
		maze[i][j] = 'C';
	    }
	}
	return true;
    }

    if (p[a[lst]].x+p[b[lst]].x==p[lst].y&&p[a[lst]].y==p[b[lst]].y&&p[a[lst]].y+p[lst].x==p[lst].y)
    {
	ans = p[lst].y;
	for ( int i = 0 ; i < p[lst].x ; i++)
	{
	    for ( int j =  0  ;  j < ans ; j++)
	    {
		maze[i][j] = char(lst+'A');
	    }
	}
	for ( int i = p[lst].x ; i < ans ; i++)
	{
	    for ( int j = 0  ;  j < ans  ;j++)
	    {
		if (j<p[a[lst]].x)
		{
		    maze[i][j]=char(a[lst]+'A');
		   // cout<<i<<" "<<j<<" "<<char(a[lst]+'A')<<endl;
		}
		else
		{
		    maze[i][j] = char (b[lst] + 'A');
		}
	    }
	}
	return true;
    }

    
    if (p[a[lst]].x+ p[b[lst]].y==p[lst].y&&p[a[lst]].y==p[b[lst]].x&&p[a[lst]].y+p[lst].x==p[lst].y)
    {
	//cout<<"22222222222222222"<<endl;
	ans = p[lst].y;
	for ( int i = 0 ; i < p[lst].x ; i++)
	{
	    for ( int j = 0 ;  j < ans ; j ++)
	    {
		maze[i][j] = char(lst+'A');
	    }
	}
	
	for ( int i = p[lst].x ; i < ans ; i++)
	{
	    for ( int j = 0 ; j < ans ; j++)
	    {
		if (j<p[a[lst]].x)
		{
		    maze[i][j] =char(a[lst]+'A');
		}
		else
		{
		    maze[i][j] = char(b[lst]+'A');
		}
	    }
	}
	return true;
    }
if (p[a[lst]].y+p[b[lst]].x==p[lst].y&&p[a[lst]].x==p[b[lst]].y&&p[a[lst]].x+p[lst].x==p[lst].y)
    {
	//cout<<"3333333333333333333333"<<endl;
	ans = p[lst].y;
	for ( int i = 0 ; i < p[lst].x ; i++)
	{
	    for ( int j =  0  ;  j < ans ; j++)
	    {
		maze[i][j] = char(lst+'A');
	    }
	}
	for ( int i = p[lst].x ; i < ans ; i++)
	{
	    for ( int j = 0  ;  j < ans  ;j++)
	    {
		if (j<p[a[lst]].y)
		{
		    maze[i][j]=char(a[lst]+'A');
		}
		else
		{
		    maze[i][j] = char (b[lst] + 'A');
		}
	    }
	}
	return true;
    }
if (p[a[lst]].y+p[b[lst]].y==p[lst].y&&p[a[lst]].x==p[b[lst]].x&&p[a[lst]].x+p[lst].x==p[lst].y)
    {
	//	cout<<"44444444444444444444444444"<<endl;
	ans = p[lst].y;
	for ( int i = 0 ; i < p[lst].x ; i++)
	{
	    for ( int j =  0  ;  j < ans ; j++)
	    {
		maze[i][j] = char(lst+'A');
	    }
	}
	for ( int i = p[lst].x ; i < ans ; i++)
	{
	    for ( int j = 0  ;  j < ans  ;j++)
	    {
		if (j<p[a[lst]].y)
		{
		    maze[i][j]=char(a[lst]+'A');
		 //   cout<<"haaa"<<a[lst]+'A'<<endl;
		}
		else
		{
		    maze[i][j] = char (b[lst] + 'A');
		}
	    }
	}
	return true;
    }
    return false;
}
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif

   ss = 0;
   lst = -1;
   a[0]=1;b[0]=2;
   a[1]=0;b[1]=2;
   a[2]=0;b[2]=1;
   for ( int i = 0 ; i < 3 ; i++) 
    {
	scanf("%d %d",&p[i].x,&p[i].y);
	if (p[i].x>p[i].y) swap(p[i].x,p[i].y);
	ss += p[i].x*p[i].y;
    }
    for ( int i = 0 ; i < 3 ; i++)
    {
	if (p[i].y*p[i].y==ss)
	{
	    lst = i;
	}
    }
    if (solve())
    {
	printf("%d\n",ans);
	for ( int i = 0 ; i < ans ; i++)
	{
	    for ( int j = 0 ; j < ans ;  j++)
	    {
		printf("%c",maze[i][j]);
	    }
	    printf("\n");
	}
    }
    else
    {
	puts("-1");
    }
 #ifndef ONLINE_JUDGE  
  
    fclose(stdin);
  #endif
	return 0;
}
