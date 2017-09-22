/*************************************************************************
	> File Name: code/hust/20151107/D.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年11月07日 星期六 13时15分23秒
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
#define fst first              
#define sec second      
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ms(a,x) memset(a,x,sizeof(a))
using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
typedef long long LL;
const int inf = 0x3f3f3f3f;
int n,a,b;
int gcd( int a,int b)
{
    if (a<b) return gcd(b,a);
    if (a%b==0) return b;
    return gcd(b,a%b);
}
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif
   int T;
   int cas = 0 ;
   scanf("%d",&T);
   while (T--)
    {
	cas++;
	scanf("%d %d %d",&n,&a,&b);
	int GCD = gcd(a,b);
	int num = n/GCD-1;
	if (num%2)
	{
	    printf("Case #%d: Iaka\n",cas);
	}
	else
	{
	    printf("Case #%d: Yuwgna\n",cas);
	}

    }
  
   
 #ifndef ONLINE_JUDGE  
  #endif
  fclose(stdin);
	return 0;
}
