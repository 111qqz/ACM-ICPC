/* ***********************************************
Author :111qqz
Created Time :2016年03月15日 星期二 19时32分24秒
File Name :code/hdu/3555.cpp
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
LL n;
LL digit[30];
LL dp[30][2];
LL dfs ( int pos,bool preis4,bool limit)
{
    if (pos==0) return 1;
    if (!limit&&dp[pos][preis4]!=-1) return dp[pos][preis4];

    LL mx = limit?digit[pos]:9;
    LL res  = 0LL ;
    for ( LL i = 0 ; i <= mx ; i++)
    {
	if (preis4&&i==9) continue;
	res += dfs(pos-1,i==4,limit&&i==mx);
    }
    
    if (!limit) dp[pos][preis4] = res;
    return res;

}
LL solve ( LL n)
{
    int len = 0 ;
    ms(digit,0);
    while (n)
    {
	digit[++len] = n %10;
	n /= 10;
    }
    
    return dfs(len,false,true);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
	    cin>>n;
	    ms(dp,-1);
	    LL ans = solve (n);
	    ans = n - ans + 1;
	    cout<<ans<<endl;
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
