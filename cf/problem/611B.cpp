/* ***********************************************
Author :111qqz
Created Time :2016年03月18日 星期五 16时33分04秒
File Name :code/cf/problem/611B.cpp
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
int digit[80];
LL dp[80][80];


LL dfs( int pos,int cnt,bool limit,bool prehasnonzero)
{
    if (pos==0) return cnt==1;
    if (!limit&&prehasnonzero&&dp[pos][cnt]!=-1) return dp[pos][cnt];

    int mx = limit?digit[pos]:1;
    LL res = 0LL ;
    if (prehasnonzero)
    {
	for ( int i =  0 ; i <= mx ; i++)
	{
	    res+=dfs(pos-1,i==0?cnt+1:cnt,limit&&i==mx,true);
	}
    }
    else
    {
	for ( int i = 0 ; i <= mx; i++)
	{
	    res+=dfs(pos-1,0,limit&&i==mx,i==0?false:true);
	}
    }

    if (!limit&&prehasnonzero) dp[pos][cnt] = res;
    return res;
}
LL solve  ( LL n)
{
    int len =  0 ;
    ms(digit,0);

    while (n)
    {
	digit[++len] = n % 2;
	n /= 2;
    }
    return dfs(len,0,true,false);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	ms(dp,-1);
	cin>>l>>r;
	//cout<<"solve:"<<solve()<<endl;
	LL ans = solve(r) - solve (l-1);
	cout<<ans<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
