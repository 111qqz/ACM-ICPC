/* ***********************************************
Author :111qqz
Created Time :2016年03月17日 星期四 16时17分07秒
File Name :code/poj/3252.cpp
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
int digit[35];
int dp[35][35][35]; //dp[i][j][k]表示长度为i，有j个0，k个1的方案数。

int dfs( int pos,int cnt0,int cnt1,bool limit,bool prehasnonzero)  //不允许前导0，所以要加prehasnonzero这个参数
								    //来确定是否位数减少了....
{
    if (pos==0) return cnt0>=cnt1;

    if (!limit&&dp[pos][cnt0][cnt1]!=-1) return dp[pos][cnt0][cnt1];

    int mx = limit?digit[pos]:1; //2进制。。最大是1.
    
    int res = 0;

    if (prehasnonzero)
    {
	for ( int i = 0 ; i <= mx;  i++)
	{
	    res+=dfs(pos-1,i==0?cnt0+1:cnt0,i==1?cnt1+1:cnt1,limit&&i==mx,true);
	}
    }
    else
    {
	for ( int i = 0 ; i <= mx  ; i++)
	{
	    if (i==0)
	    {
		res+=dfs(pos-1,0,0,limit&&i==mx,false);
	    }
	    else
	    {
		res+=dfs(pos-1,0,1,limit&&i==mx,true);
	    }
	}
    }
	if (!limit) dp[pos][cnt0][cnt1] = res;
	return res;
    }
int solve ( int n)
{
    ms(digit,0);
    int len =  0 ;
    
    while (n)
    {
	digit[++len] = n % 2;
	n /= 2;
    }

    return  dfs(len,0,0,true,false);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	ms(dp,-1);
	cin>>l>>r;
	int ans = solve ( r ) - solve ( l - 1 );
	cout<<ans<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
