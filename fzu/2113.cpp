/* ***********************************************
Author :111qqz
Created Time :Thu 29 Sep 2016 02:20:09 AM CST
File Name :code/fzu/2113.cpp
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
int digit[30];
LL dp[30][30];

LL  dfs( int pos,int cnt,bool limit)
{
    if (pos==0) return cnt;
    if (!limit&&dp[pos][cnt]!=-1) return dp[pos][cnt];
    
    int mx = limit?digit[pos]:9;
    LL res = 0 ;
    for ( int i = 0 ; i <= mx ; i++)
    {
	if (i==1)
	res = res + dfs(pos-1,cnt+1,limit&&i==mx);
	else res = res + dfs(pos-1,cnt,limit&&i==mx);
    }
    if (!limit) dp[pos][cnt] = res;
    return res;
}
LL solve( LL n)
{
    int len = 0 ;
    ms(digit,0);
    while (n)
    {
	digit[++len] = n%10;
	n/=10;
    }
   // cout<<"len:"<<len<<endl;
    ms(dp,-1);
    return dfs(len,0,true);

}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	ms(dp,-1);
	while (~scanf("%lld%lld",&l,&r))
	{
//	    cout<<"l:"<<l<<" r:"<<r<<endl;
	    if (l>r) swap(l,r);
	    LL ans = solve(r) - solve(l-1);
//	    cout<<solve(r)<<" "<<solve(l-1)<<endl;
	    printf("%lld\n",ans);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
