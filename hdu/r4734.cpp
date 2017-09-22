/* ***********************************************
Author :111qqz
Created Time :2016年03月18日 星期五 08时57分02秒
File Name :code/hdu/r4734.cpp
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
int digit[20];
int a,b;
int dp[11][11000];
int power[15];
int fa;
int cal( int n)
{
//    cout<<"n:"<<n;
    int base = 1;
    int res = 0 ;
    while (n)
    {
	res += (n%10)*base;
	base*=2;
	n/=10;
    }
//    cout<<" res:"<<res<<endl;
    return res;
}

int dfs( int pos,int sum,bool limit)
{
//    cout<<"pos:"<<pos<<" sum:"<<sum<<endl;
    if (pos==0) return sum>=0;
    if (sum<0) return 0;
    
    if (!limit&&dp[pos][sum]!=-1) return dp[pos][sum];
    
    int mx = limit? digit[pos] : 9 ;
    int res = 0 ;
    for ( int i =  0 ; i <= mx ; i++)
    {
	res+=dfs(pos-1,sum-power[pos]*i,limit&&i==mx);
    }
    if (!limit) dp[pos][sum] = res;
    return res;
}
int solve ( int n )
{
    int len = 0 ;
    ms(digit,0);
    while (n)
    {
	digit[++len] = n % 10;
	n/=10;
    }
//    for ( int i = len ; i >=1 ;  i--) cout<<digit[i];
    return dfs(len,cal(a),true);
}
int main()
    {
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	
	power[1] = 1;
	for ( int  i = 2 ; i <= 12 ; i++) power[i] = power[i-1] * 2; //循环不小心从1开始。。。结果全0了。。。。2333
	int T;
	cin>>T;
	int cas = 0;
	ms(dp,-1);
	while (T--)
	{
	    scanf("%d %d",&a,&b);
	    fa = cal(a);
	    int ans = solve(b);
	    printf("Case #%d: %d\n",++cas,ans);

	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
