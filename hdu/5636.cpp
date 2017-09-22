/* ***********************************************
Author :111qqz
Created Time :2016年03月31日 星期四 17时18分34秒
File Name :code/hdu/5636.cpp
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
const int N=1E5+7;
const LL MOD =1E9+7;
int n,m;
int z[N];
LL a[10];
LL dp[10][10];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	ios::sync_with_stdio(false);
	cin>>T;
	while (T--){
	    cin>>n>>m;
	    for ( int i = 1 ;i  <= 6 ; i++) cin>>a[i];
	    for ( int i = 1 ; i <= 6 ;i ++)
	    {
		for ( int j = 1 ; j <= 6 ; j++) //初始化   //以这六个点构建了张新图，有边相连权为1，否则为点距。
		    dp[i][j] = abs(a[i]-a[j]);
	    }

	    for ( int i = 1 ;i <= 6 ; i+=2)
	    {
		if (a[i]!=a[i+1]) dp[i][i+1]=dp[i+1][i]=1;
	    }


	    for ( int k = 1  ;k <= 6 ; k++)
		for ( int i = 1 ; i  <= 6 ; i++)
		    for ( int j = 1 ; j <= 6 ; j++)
			dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);

	    LL ans = 0 ;
	    LL cas = 0 ;
	    while (m--)
	    {
		cas++;
		LL s,t;
		cin>>s>>t;
		LL res = abs(s-t);

		for ( int i = 1 ; i <= 6 ; i++)   //枚举经过的中间点 
		    for ( int j = 1 ; j <= 6 ; j++)
			res = min(res,abs(s-a[i])+dp[i][j]+abs(t-a[j]));
    //	cout<<"res:"<<res<<endl;
		ans = (ans + (cas*res)%MOD)%MOD;
	    }
	    cout<<ans<<endl;
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
