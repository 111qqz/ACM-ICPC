/* ***********************************************
Author :111qqz
Created Time :2016年04月03日 星期日 14时39分21秒
File Name :code/bzoj/1616.cpp
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
#define pi pair < int ,int >
#define MP make_pair

using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int N=103;
int n,m,T;
int dp[N][N][18];
char maze[N][N];
int r1,c1,r2,c2;

void print()
{
    for ( int i = 1 ; i <= n ; i++)
	for ( int j = 1 ; j <= m ; j++)
	    for ( int t = 1 ; t <= T ;  t++)
		cout<<i<<" "<<j<<" "<<t<<" "<<dp[i][j][t]<<endl;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n>>m>>T;
	for ( int i = 1 ; i <= n ; i++) scanf("%s",maze[i]+1);
	cin>>r1>>c1>>r2>>c2;

	ms(dp,0);
	dp[r1][c1][0]=1;
	
	for ( int t = 1 ;t  <= T ; t++)
	{
	    for ( int i = 1 ; i <= n ; i++)
	    {
		for ( int j = 1 ; j <= m ; j++)
		{
		    if (maze[i][j]=='*') continue;
		    for ( int dir = 0 ; dir < 4 ; dir ++)
		    {
			dp[i+dx4[dir]][j+dy4[dir]][t]+=dp[i][j][t-1];
		    }
		}
	    }
	}
//	print();
	cout<<dp[r2][c2][T]<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
