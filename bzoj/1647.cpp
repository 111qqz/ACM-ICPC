/* ***********************************************
Author :111qqz
Created Time :2016年04月10日 星期日 21时17分46秒
File Name :code/bzoj/1647.cpp
************************************************ */

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
const int N=20;
int a[N][N],ans[N][N],op[N][N];
int m,n;
int dirx[10]={0,0,0,-1,1};
int diry[10]={0,1,-1,0,0};
int rec[N][N];
void solve(int x,int y)
{
    for ( int i = 0 ; i < 5 ; i++ )
    {
	  int newx = x + dirx[i];
	  int newy = y + diry[i];
	  if (newx>=1&&newx<=m&&newy>=1&&newy<=n)
	  {
		a[newx][newy]=a[newx][newy]^1;
	  }
    }
}
bool on (int x,int y)
{
    int res = a[x][y];
    for ( int i = 0 ; i < 5 ; i++ )
    {
	  int newx = x + dirx[i];
	  int newy = y + diry[i];
	  if (newx>=1&&newx<=m&&newy>=1&&newy<=n)
	  {
		res = res+op[newx][newy];
	  }

    }
    return res&1;
}
int main()
{
    cin>>m>>n;
    int mi = 9999999;
    memset(rec,0,sizeof(rec));
    for ( int i = 1 ; i <= m ; i++ )
    {
	  for (int j = 1 ; j <= n ; j++)
	  {
		cin>>a[i][j];
	  }
    }
    bool flag = false;
    for ( int i = 0  ; i < (1<<n); i++ )   //枚举第一行的好改变情况
    {
        int tmp=i;
	  int num=0;
	  memset(op,0,sizeof(op));
        memset(ans,0,sizeof(ans));
	  int k = n;
	  while (tmp)
	  {
		op[1][k]=tmp%2;
		if (op[1][k]==1) num++;
		tmp = tmp / 2;
		k--;
	  }
//	  cout<<"********************"<<endl;
//	  for ( int i = 1 ; i <= n ; i++)
//	  {
//		cout<<op[1][i]<<" ";
//	  }
//	  cout<<endl;
//	  cout<<"*************************"<<endl;


	  for ( int j = 2 ; j <= m ; j++ )
	  {
		for ( int k = 1 ; k <= n ; k++ )
		{
		    if (on(j-1,k))
		    {
			  op[j][k]=1;
			  num++;
		    }
		}
	  }
	  bool ok = true;
	  for ( int j = 1 ; j <= n ; j++ )
	  {
		if (on(m,j))
		{
		    ok=false;
		    break;
		}
	  }
	  if (ok)
	  {
		flag = true;
		if (num<mi)
		{
		    mi = num;
		    memcpy(rec,op,sizeof(op));
		 //   for ( int j = 1 ; j <= m ; j ++ )
		//    {
		//	  for ( int k = 1 ;  k <= n ; k++ )
		//	  {
	//			rec[j][k]=ans[j][k];
	//		  }
//		    }
		}
	  }
    }
    if (flag)
    {
	  for ( int i = 1 ; i <= m ; i++ )
	  {
		cout<<rec[i][1];
		for ( int j = 2 ; j <= n ; j++ )
		{
		    cout<<" "<<rec[i][j];
		}
		cout<<endl;
	  }
    }
    else
    {
	  printf("IMPOSSIBLE\n");
    }

	return 0;
}
