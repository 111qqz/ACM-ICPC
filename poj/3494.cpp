/* ***********************************************
Author :111qqz
Created Time :2016年08月03日 星期三 19时33分14秒
File Name :code/poj/3494.cpp
************************************************ */
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define fst first
#define sec second
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ms(a,x) memset(a,x,sizeof(a))
typedef long long LL;
#define pi pair < int ,int >
#define MP make_pair
using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int N=2E3+50;
int maze[N][N];
int a[N][N],l[N][N],r[N][N];
stack<int>stk;
int n,m;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	while (~scanf("%d%d",&n,&m))
	{
	    ms(maze,-1); //设置哨兵。。。
	    ms(a,-1);
	    while (!stk.empty()) stk.pop();
	    for ( int i = 1 ; i <= n ; i++)
		for ( int j = 1 ; j <= m ; j++)
		    scanf("%d",&maze[i][j]);
	    int x;
	    for ( int i = 1 ; i <= n ; i++)
	    {
		while (!stk.empty()) stk.pop();
		stk.push(m+1);
		for ( int j = m ; j >=1 ; j--)
		{
		    for (x=stk.top() ; maze[i][x]==1 ; x = stk.top()) stk.pop();
		    a[i][j] = x-j;
		    if (maze[i][j]==0) a[i][j] = 0 ;
		    stk.push(j);
		}
	    }
/*	    for ( int i = 1 ;i <= n ; i++){
		for ( int j = 1 ; j <= m ; j++)
		    printf("%d hhh",a[i][j]);
		printf("\n");
	    }  */
	    for ( int j = 1 ; j <= m ; j++)
	    {
		while (!stk.empty()) stk.pop();
		stk.push(0);
		for ( int i = 1 ; i <= n ; i++)
		{
		    for (x=stk.top() ; a[x][j]>=a[i][j] ; x=stk.top()) stk.pop();//cout<<"x:"<<x<<endl;
		    l[i][j] = x+1;
		    stk.push(i);
		//    cout<<i<<endl;
		}
		while (!stk.empty()) stk.pop();
		stk.push(n+1);
		for ( int i = n ; i >=1 ; i--)
		{
		    for (x=stk.top() ; a[x][j]>=a[i][j] ; x = stk.top()) stk.pop();
		    r[i][j] = x-1;
		    stk.push(i);
		}
	    }
	    int ans = 0 ;
	    for ( int i = 1; i <= n ; i++)
		for ( int j = 1 ; j <= m ; j++)
		    ans = max(ans,(r[i][j]-l[i][j]+1)*a[i][j]);
	    printf("%d\n",ans);
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
