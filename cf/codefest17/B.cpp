/* ***********************************************
Author :111qqz
Created Time :2017年09月25日 星期一 19时26分34秒
File Name :B.cpp
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
#define PB push_back
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
const int N=1E5+7;
LL a[N];
LL p,q,r;
int n;
LL dp[N][3];
int main()
{
#ifndef  ONLINE_JUDGE 
    freopen("./in.txt","r",stdin);
#endif
    cin>>n>>p>>q>>r;
    for ( int i = 1 ; i <= n ; i++) cin>>a[i];
    LL ans = 1LL<<60;
    ans*=-5LL;
    ms(dp,0xc0);
    //重要的是维护一个前缀最大值。
    for ( int i = 1 ; i <= n ; i++)
	dp[i][0] = max(dp[i-1][0],p*a[i]);
    for ( int i = 1 ; i <= n ; i++)
	dp[i][1] = max(dp[i-1][1],dp[i][0]+q*a[i]);
    for ( int i = 1 ; i <= n ; i++)
	dp[i][2] = max(dp[i-1][2],dp[i][1]+r*a[i]);
    cout<<dp[n][2]<<endl;

#ifndef ONLINE_JUDGE  
    fclose(stdin);
#endif
    return 0;
}
