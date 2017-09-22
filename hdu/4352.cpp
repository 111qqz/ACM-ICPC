/* ***********************************************
Author :111qqz
Created Time :2016年03月17日 星期四 20时46分09秒
File Name :code/hdu/4352.cpp
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
LL l,r;
int k;
int digit[25];
LL dp[20][12]; //dp[i][j][k]
int g[25];
LL dfs( int pos,int len,bool limit,int n)
{
    if (pos==0) return len==k;
    if (len>k) return 0;
    if (!limit&&dp[pos][len]!=-1) return dp[pos][len];
    int mx = limit?digit[pos]:9;

    LL res = 0LL ;

    for ( int i = 0 ;  i <= mx ;  i++)
    {
	int curk = lower_bound(g+1,g+n+1,i)-g;
	cout<<"curk:"<<curk<<endl;
	g[curk] =  i;
	if (curk>k) break;
	len = max(len,curk);
	res = res + dfs(pos-1,len,limit&&i==mx,n);
    }
    if (!limit) dp[pos][len] = res;
    return res;
}
LL solve (LL n)
{
    ms(digit,0);
    int len = 0 ;
    ms(g,0x3f);
    while (n)
    {
	digit[++len] = n % 10;
	n /= 10;
    }
    
    return dfs(len,0,true,len);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	int T;
//	ios::sync_with_stdio(false);
	cin>>T;
	ms(dp,-1);
	int cas = 0 ;
	while (T--)
	{
	    scanf("%lld %lld %d",&l,&r,&k);
	    LL ans = solve (r) - solve (l-1);
	    cout<<"solve(r):"<<solve(r)<<endl;
	    printf("Case #%d: %lld\n",++cas,ans);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
