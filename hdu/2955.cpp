/* ***********************************************
Author :111qqz
Created Time :Tue 15 Nov 2016 06:53:53 PM CST
File Name :code/hdu/2955.cpp
************************************************ */
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <deque>
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
const int N=105;
double dp[N];
double p;
int n,V;
int value[N];
double cost[N];
void solve(double Cost,int Value)
{
        for ( int i = V ; i >= Value ; i--)
                dp[i] = max(dp[i],dp[i-Value]*Cost);
}
int dblcmp( double d)
{
    return d<-eps?-1:d>eps;
}
int main()
{
  #ifndef  ONLINE_JUDGE
    freopen("code/in.txt","r",stdin);
  #endif
   int T;
   cin>>T;
   while (T--)
   {
        

        scanf("%lf%d",&p,&n);
        p = 1 - p;	
	V = 0 ;
        for ( int i = 1; i <= n ; i++)
        {
                scanf("%d%lf",&value[i],&cost[i]);
                cost[i] = 1 - cost[i];
		V = V + value[i];
        }
	for ( int i = 0 ; i <= V ; i++) dp[i] =  0;
        for ( int i = 1 ; i <= n ; i++)
                solve(cost[i],value[i]);
      
        for ( int i = V ; i >= 0 ; i--)
	{
	    if (dblcmp(dp[i]-p)>0)
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
