/* ***********************************************
Author :111qqz
Created Time :2016年03月16日 星期三 09时27分49秒
File Name :code/hdu/3652.cpp
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
LL dp[20][15];
LL dp2[20][2][15];
int digit[20];


LL dfs (int pos,int sum,bool limit)
{
    if (pos==0) return sum==0;
    
    if (!limit&&dp[pos][sum]!=-1) return dp[pos][sum];

    int mx = limit ? digit[pos]:9;

    LL res = 0LL ;
    for ( int i = 0 ; i  <=  mx ; i++)
    {
	res+=dfs(pos-1,(sum*10+i)%13,limit&&i==mx);
    }
    
    if(!limit) dp[pos][sum] = res;
    return res;
}
LL dfs2(int pos,bool preis1,int sum,bool limit)
{
    if (pos==0) return sum==0;

    if (!limit&&dp2[pos][preis1][sum]!=-1) return dp2[pos][preis1][sum];

    int mx = limit? digit[pos]:9;
    LL res = 0 ;
    for ( int i = 0 ; i <=  mx ; i++)
    {
	if (preis1&&i==3) continue;
	res+=dfs2(pos-1,i==1,(sum*10+i)%13,limit&&i==mx);
    }

    if (!limit) dp2[pos][preis1][sum] = res;
    return res;
}

LL solve ( LL n)
{
    ms(digit,0);

    int len =  0;
    while (n)
    {
	digit[++len] = n%10;
	n/= 10;
    }
    return dfs(len,0,true)-dfs2(len,false,0,true); //在能被13整除的数里划分，减去不含“13”的，就是含“13”的。
						  //因为含“13”的情况太复杂了。。。
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	
	ms(dp,-1); //dp数组子啊外面清空就好。。。。因为dp数组是所有数据公用的啊。。。。
	ms(dp2,-1);
	while (~scanf("%lld",&n))
	{
	    LL ans = solve (n);
	    printf("%lld\n",ans);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
