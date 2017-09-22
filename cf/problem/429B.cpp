/* ***********************************************
Author :111qqz
Created Time :2016年07月28日 星期四 02时13分58秒
File Name :code/cf/429B.cpp
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
LL a[N][N];
LL dp[5][N][N];
int main()
{
#ifndef  ONLINE_JUDGE 
    freopen("code/in.txt","r",stdin);
#endif
    cin>>n>>m;
    ms(dp,0);
    //	cout<<"dp[1][1][1]"<<dp[1][1][1]<<endl;
    for ( int i = 1 ; i <= n ; i++)
	for ( int j = 1 ; j <= m ; j++)
	    scanf("%lld",&a[i][j]);

    for ( int i = 1 ;i  <= n ; i++)  //1 --left up
	for ( int j = 1 ; j <= m ; j++)
	    dp[1][i][j] = max(dp[1][i-1][j],dp[1][i][j-1]) + a[i][j];

    for ( int i = 1 ;i <= n ; i++)  //2 -- right up
	for ( int j = m ; j >= 1 ;j--)
	    dp[2][i][j] = max(dp[2][i-1][j],dp[2][i][j+1]) + a[i][j];

    for ( int i = n ; i >=1 ; i--) //3 -- left down
	for ( int j = 1 ; j <= m ; j++)
	    dp[3][i][j] = max(dp[3][i+1][j],dp[3][i][j-1]) + a[i][j];


    for ( int i = n ; i >= 1 ; i--)  //4 -- right down
	for ( int j =  m ; j >= 1 ; j--)
	    dp[4][i][j] = max(dp[4][i+1][j],dp[4][i][j+1]) + a[i][j];


    for ( int i = 1 ; i <= n ; i++) 
	for ( int k = 1 ; k <= 4 ; k++)
	    dp[k][i][0]=dp[k][i][m+1]=-inf;

    for ( int j = 1 ; j <= m ; j++)
	for ( int k = 1 ; k <=  4 ; k++)
	    dp[k][0][j]=dp[k][n+1][j]=-inf;
    //保护好边界。

	LL ans = 0 ;
    for ( int i = 1 ; i <= n ; i++)
	for ( int j = 1 ; j <= m ;j++ )
	{
	    LL  tmp;
	    tmp = dp[1][i-1][j] + dp[4][i+1][j] + dp[3][i][j-1] + dp[2][i][j+1];
	    ans = max(tmp,ans);
	    tmp = dp[1][i][j-1] + dp[4][i][j+1] + dp[3][i+1][j] + dp[2][i-1][j];
	    ans = max(tmp,ans);
	}
    cout<<ans<<endl;

#ifndef ONLINE_JUDGE  
    fclose(stdin);
#endif
    return 0;
}
