/* ***********************************************
Author :111qqz
Created Time :2016年08月29日 星期一 16时22分20秒
File Name :code/poj/3422.cpp
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
const int N=52;
int a[N][N];
int dp[N][N];
int n,k;
pi path[N][N];

void print(int x,int y)
{
    cout<<"xx:"<<x<<" yy:"<<y<<endl;
    if (path[x][y].fst!=-1||path[x][y].sec!=-1)
    {
	print(path[x][y].fst,path[x][y].sec);
	a[x][y] = 0 ;
	cout<<"x:"<<x<<" y:"<<y<<endl;
    }
}

void solve()
{
    dp[n][n] = a[n][n];
    for ( int i = n ; i >=1  ; i--)
	for ( int j = n ; j>= 1 ; j--)
	{
	    if (i==n&&j==n) continue;
	    if (dp[i+1][j]>dp[i][j+1])
	    {
		path[i+1][j].fst = i;
		path[i+1][j].sec = j;
		dp[i][j] = dp[i+1][j] + a[i][j];
	    }
	    else
	    {
		path[i][j+1].fst = i;
		path[i][j+1].sec = j;
		dp[i][j] = dp[i][j+1] + a[i][j];
	    }
	}

    for ( int i = 1 ; i <= n ; i++)
    {
	for ( int j =1 ; j <=  n ;  j++)
	    printf("%d ",dp[i][j]);
	printf("\n");
    }
    print(n,n);

}

int main()
{
#ifndef  ONLINE_JUDGE 
    freopen("code/in.txt","r",stdin);
#endif
    ms(dp,0);
    ms(a,-1);
    ms(path,-1);
    cin>>n>>k;
    for ( int i = 1 ; i <= n ; i++)
	for ( int j = 1 ; j <= n ; j++)
	    scanf("%d",&a[i][j]);

    
    for ( int i = 1 ; i <= k ; i++) solve();
    printf("%d\n",dp[1][1]);








#ifndef ONLINE_JUDGE  
    fclose(stdin);
#endif
    return 0;
}
