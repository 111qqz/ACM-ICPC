/* ***********************************************
Author :111qqz
Created Time :2016年03月18日 星期五 12时13分55秒
File Name :code/ural//1057.cpp
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
int l,r;
int k,base;
int digit[700];
int dp[700][700];


int dfs( int pos , int cnt, bool limit)
{
    if (pos==0) return cnt==0;
    if (cnt<0) return 0;

    if (!limit&&dp[pos][cnt]!=-1) return dp[pos][cnt];

    int mx = limit?digit[pos]:1;
   // int mx = 1;
    int res = 0 ;
    for ( int i = 0 ; i <= mx ; i ++)
    {
	if (i>1) continue;
	res += dfs(pos-1,i==1?cnt-1:cnt,limit&&i==mx);
    }
    return limit?res:dp[pos][cnt] = res;
}
int solve(int n )
{
    ms(digit,0);
    int len = 0 ;
    while (n)
    {
	digit[++len] = n % base;
	n/=base;
    }

    return dfs(len,k,true);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
	 #endif
//	ios::sync_with_stdio(false);
	ms(dp,-1);
	cin>>l>>r;
	cin>>k>>base;
//	cout<<"solve(r):"<<solve(r)<<" solve(l-1):"<<solve(l-1)<<endl;
	int ans = solve (r) - solve (l-1);
	cout<<ans<<endl;

  #ifndef ONLINE_JUDGE 
  fclose(stdin);
  #endif
    return 0;
}
