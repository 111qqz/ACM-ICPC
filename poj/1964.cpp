/* ***********************************************
Author :111qqz
Created Time :2016年08月03日 星期三 05时55分30秒
File Name :code/poj/1964.cpp
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
const int N=1E3+7;
int n,m;
char maze[N][N];
int row[N][N],col[N][N];
int a[N][N];
int l[N][N],r[N][N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	scanf("%d",&T);
	while (T--)
	{
	    ms(a,0);
	    scanf("%d%d",&n,&m);
	    getchar();
	    for ( int i = 1 ; i <= n ; i++)
	    {
		for ( int j = 1 ; j <= m ; j++)
		{
		    char ch = getchar();
		    while (ch!='F'&&ch!='R') ch = getchar();
		    maze[i][j]=ch;
		}
		maze[i][m+1] = 'R'; //单调栈的哨兵
	    }
/*	    for ( int i = 1 ;i  <= n ;i++){
		for ( int j = 1 ; j <= m ; j++)
		    printf("%c ",maze[i][j]);
	    	printf("\n");
   	    }       */
	    for ( int j = 1 ;j <= m ; j++) maze[n+1][j] = 'R'; //单调栈的哨兵
	    int x;
	    for ( int i = 1 ; i <= n ; i++)
	    {
		stack<int>stk;
		stk.push(m+1);
		for ( int j = m ; j >=1 ; j--)
		{
	/*	    if (maze[i][j]=='R')
		    {
			row[i][j]=j;
			stk.push(j);
			continue;
		    }                     */
		    for (x=stk.top() ; maze[i][x]=='F' ; x = stk.top()) stk.pop();
		    row[i][j] = x-1;
		    stk.push(j);
		    a[i][j] = row[i][j]-j+1;
		    if (maze[i][j]=='R') a[i][j] = 0 ;
		}
	    }
/*	    for ( int i = 1 ; i <= n ; i++)
	    {
		for ( int j = 1 ; j <= m ; j++)
		{
		    printf("%d ",a[i][j]);
		}
		printf("\n");
	    }   */
	    for ( int j = 1 ; j <= m ; j++)  //把a[i][j]看成高度，再做上下两个方向的单调栈
	    {
		a[0][j]=a[n+1][j]=-1; //单调栈的哨兵
		stack<int>stk;
		stk.push(0);
		for ( int i = 1 ; i <= n ; i++)
		{
		    for (x=stk.top(); a[x][j]>=a[i][j] ; x = stk.top()) stk.pop();
		    l[i][j] = x+1;
		    stk.push(i);
		}
		while (!stk.empty()) stk.pop();
		stk.push(n+1);
		for ( int i = n ; i >=1 ; i --)
		{
		    for (x = stk.top() ; a[x][j]>=a[i][j]; x = stk.top()) stk.pop();
		    r[i][j] = x-1;
		    stk.push(i);
		}
	    }
	    int ans = 0 ;
	    for ( int i = 1 ; i <= n ; i++)
		for ( int j = 1 ; j <= m ; j++)
		    if (maze[i][j]=='F')
			ans = max(ans,(r[i][j]-l[i][j]+1)*a[i][j]);
	    printf("%d\n",ans*3);


	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
