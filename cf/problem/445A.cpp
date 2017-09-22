/* ***********************************************
Author :111qqz
Created Time :2015年12月04日 星期五 17时18分45秒
File Name :code/cf/problem/445A.cpp
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
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



using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int N=105;
char maze[N][N];
int n,m;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	scanf("%d %d",&n,&m);
	for ( int i = 0 ; i < n ;i++) scanf("%s",maze[i]);
	int x;
	 for ( int i = 0 ; i < n ; i++)
	{
	    for ( int j =  0 ; j < m ; j++)
	    {
		x =(i+j)%2;
		if (maze[i][j]=='.')
		{
		    if (x) maze[i][j]='W';
			else maze[i][j]='B';

		}
	    }
	}
	 for ( int i = 0 ; i < n ;i++) printf("%s\n",maze[i]);

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
