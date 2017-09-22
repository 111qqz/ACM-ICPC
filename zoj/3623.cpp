/*************************************************************************
	> File Name: code/zoj/3623.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月19日 星期一 17时01分08秒
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<stack>
#include<cctype>
                 
#define yn hez111qqz
#define j1 cute111qqz
#define ms(a,x) memset(a,x,sizeof(a))
using namespace std;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;
const int N=400; //最坏的情况是建造时间为20s,伤害为1，这样也只需要350s（20s建造，330s每s一滴血）就可以干掉330血(max)的怪物...保险一点400.
int n,v;
int t[35],l[35];
int dp[N];
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif

   while (scanf("%d %d",&n,&v)!=EOF)
    {
	for ( int i = 0 ; i < n ; i++) scanf("%d %d",&t[i],&l[i]);
	ms(dp,0);                       //dp[i]表示到时间i能造成的最大伤害

	for ( int j = 0 ; j < N-25 ; j++)
	    for ( int i = 0; i < n ; i++)            //怒re一发，sad
		dp[j+t[i]] = max(dp[j+t[i]],dp[j]+j*l[i]); //转移方程能这么写是因为，当某个武器建造好后，输出的时候就不影响其他了
							    //这样就可以倒着想，先建造，再输出。
	for ( int i = 0 ; i < N  ; i++)                      //以前觉得背包问题一定是对于某个容量的最大价值
								//但实际上在找这个最大价值的过程中，对于每个容量的最大价值都得到
								
	{
	  //  cout<<"dp[i]:"<<dp[i]<<endl;
	    if (dp[i]>=v)
	    {
		printf("%d\n",i);
		break;
	    }
	}
    }
  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
