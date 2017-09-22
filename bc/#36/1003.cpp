/*************************************************************************
	> File Name: code/bc/#36/1003.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年09月19日 星期六 19时50分53秒
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
const int N=5E2+7;
int a[N][N];
int c[N][N];
int n,m,q;
int lowbit(int x)
{
    return x&(-x);
}

void update ( int x,int y,int delta)
{
    for ( int i = x ; i <= n ; i = i + lowbit(i))
    {
	for ( int j = y ;  j <= m ; j = j + lowbit(j))
	{
	    c[i][j] += delta;
	}
    }
}
int sum ( int x,int y)
{
    int res = 0 ;
    for ( int i = x ; i >= 1 ; i = i - lowbit(i))
    {
	for ( int j = y ; j >= 1 ; j = j - lowbit(j))
	{
	    res = res + c[i][j];
	}
    }
}
int main()
{
  #ifndef  ONLINE_JUDGE 
  freopen("in.txt","r",stdin); 
  #endif
  int T;
  cin>>T;
  while (T--)
    {
	ms(c,0);
	scanf("%d %d",&n,&m);
	scanf("%d",&q);
	for (int i = 1 ; i <= n ; i++)
	{
	    for ( int j = 1 ; j <= m ;  j++)
	    {
		scanf("%d",&a[i][j]);
		update (i,j,a[i][j]);
	    }
	}
	for ( int i = 0 ; i < q ; i++)
	{
	    int opt;
	    scanf("%d",&opt);
	 //   cout<<"fuccccc"<<endl;
	 //   cout<<"q:"<<q<<endl;
	    if (opt==1)
	    {
		int x1,y1,x2,y2;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		int tmp = (x2-x1+1)*(y2-y1+1);
		cout<<"tmp:"<<tmp<<endl;
		if (tmp%2==1)
		{
		    puts("Yes");
		    continue;
		}
		int Sum; 
		Sum= sum (x2,y2)-sum(x1-1,y2)-sum(x2,y1-1)+sum(x1-1,y1-1);
		cout<<sum(x2+1,y2+1)<<endl;
		cout<<sum(x1,y2+1)<<endl;
		cout<<sum(x2+1,y1)<<endl;
		cout<<sum(x1,y1)<<endl;
		cout<<"Sum:"<<Sum<<endl;
		if (Sum>tmp) //至少存在一堆不是1
		{
		    puts("Yes");
		    continue;
		}
		puts("No");
	    }
	    else
	    {
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		int tmp = z-c[x][y];
		update (x,y,tmp);
	    }
	}
    }

  
  
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
