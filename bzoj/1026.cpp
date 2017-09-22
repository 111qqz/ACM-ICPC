/* ***********************************************
Author :111qqz
Created Time :2016年03月15日 星期二 19时49分57秒
File Name :code/bzoj/1026.cpp
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
int dp[30][10];  
int digit[30];


int dfs ( int pos,int pre,bool limit,bool prehasnonzero) // prehasnonzero表示当前位前面的位是否有非0的位。
{
    if (pos==0) return 1;
    if (prehasnonzero&&!limit&&dp[pos][pre]!=-1) return dp[pos][pre];  //位数相同才通用，所以prehasnonzero为true才调用
    
    int mx = limit?digit[pos]:9;

    int res = 0 ;

    if (!prehasnonzero)
    {
	for ( int i =  0 ; i <= mx ; i++ )
	{
	    res+=dfs (pos-1,i,limit&&i==mx,i==0?false:true);
	}
    }
    else
    {
	for ( int i = 0 ; i <= mx ; i++)
	{
	    if (abs(i-pre)>=2)
	    {
		res+=dfs(pos-1,i,limit&&i==mx,true);
	    }
	}
    }
    
    
    if (prehasnonzero&&!limit)  dp[pos][pre] = res; //位数相同才通用，所以prehasnonzero为true时才记录。
    return res;
}
int solve ( int  n )
{
    ms(digit,0);
    
    int len = 0  ;
    
    while (n)
    {
	digit[++len] = n%10;
	n/=10;
    }
    return dfs(len,0,true,0);  //pre的初始值应该是0而不是-1，因为不允许前导0，位数是可变的。..所以不过是一种特殊情况而已。
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	ios::sync_with_stdio(false);
	ms(dp,-1);
	cin>>l>>r;
	int ans = 0 ;
	ans += solve (r)-solve(l-1);
//	cout<<solve(15)<<endl;
	cout<<ans<<endl;


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
