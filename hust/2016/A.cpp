/* ***********************************************
Author :111qqz
Created Time :2016年05月28日 星期六 13时30分01秒
File Name :code/hust/2016/A.cpp
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
const int N=1E3+7;
int n,m;
char maze[N][N];
int dp[N][N][3];

bool check1( int x,int y)
{
    if (x==n) return false;
    if (maze[x+1][y]=='b') return false;
    return true;
}

bool check2( int x,int y)
{
    if (y==m) return false;
    if (maze[x][y+1]=='b') return false;
    return true;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	while (scanf("%d %d",&n,&m)!=EOF)
	{
	  //  cout<<"ssssssssssssssad"<<endl;
	    for ( int i = 1 ; i <= n ;  i++) scanf("%s",maze[i]+1);

	    ms(dp,0x3f);
	    
	    bool dok;
	    bool rok;
	    for ( int i = 1 ; i <= n ; i++)
	    {
		for ( int j = 1 ; j <= m ; j++)
		{
		     dok =check1(i,j);
		     rok =check2(i,j);
	//	     cout<<"dok:"<<dok<<" rok:"<<rok<<endl;
		     for ( int k = 0 ; k <= 1 ; k++) dp[i][j][k]= maze[i][j]=='b'?1:0;
		
		if (i==1&&j==1)
		{
		    dp[i][j][0] = dp[i][j][1] + rok;
		    continue;
		}

		dp[i][j][0] +=min(dp[i-1][j][0],dp[i][j-1][1]+rok);
		dp[i][j][1] +=min(dp[i][j-1][1],dp[i-1][j][0]+dok);
		}
	    }
	    
	//    cout<<"dp[n][m][0]:"<<dp[n][m][0]<<" dp[n][m][1]:"<<dp[n][m][1]<<endl;
	    int ans = min(dp[n][m][0],dp[n][m][1]);
	    printf("%d\n",ans);



	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
