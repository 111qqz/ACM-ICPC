/* ***********************************************
Author :111qqz
Created Time :2016年03月17日 星期四 21时30分57秒
File Name :code/hdu/4734.cpp
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
int a,b;
int digit[15],digita[15];
int fa;
int dp[10][110000];//dp[i][j]表示长度为i,f[x]为j的方案数...
int power[20];

int cal( int n)
{
    ms(digita,0);
    int len = 0 ;
    while (n)
    {
	digita[++len] = n % 10;
	n /= 10 ;
    }
    int base = 1;
    int res = 0 ;
    for ( int i = 1 ; i <= len ; i ++)
    {
//	cout<<"digita:"<<digita[i]<<endl;
	res +=digita[i]*base;
	base*=2;
    }

    return res;
}


int dfs(int pos,int sum,bool limit)
{
    if (pos==0)  return  sum<=fa;
    if (sum>fa) return 0; //sum只会越来越大。。所以这里可以减一下。。。
  //  if (sum+(power[pos+1]-1)*9<=fa) return 1; //如果后面的位置取最大仍然满足，可以提前就确定。减！
    if (!limit&&dp[pos][sum]!=-1) return dp[pos][sum];

    int mx = limit?digit[pos]:9;

    int res = 0  ;
    for ( int i = 0 ; i <= mx ; i++)
    {
       res+=dfs(pos-1,sum+i*power[pos],limit&&i==mx);
    }

  //  if (!limit) dp[pos][sum] = res;
    return res;
}
int solve ( int n)
{
    ms(digit,0);
    int len = 0 ;
    while (n)
    {
	digit[++len] = n % 10;
	n /= 10;
    }

    return dfs(len,0,true);
}

void pre()
{
    power[1] = 1;
    for ( int i = 2 ; i <= 12 ; i++)
    {
	power[i] = power[i-1]*2;
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	pre();
	int T;
	cin>>T;
	ms(dp,-1);
	int cas = 0 ;
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
