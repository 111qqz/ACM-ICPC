/*************************************************************************
	> File Name: code/cf/#329/B.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年11月05日 星期四 15时34分05秒
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
                 
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ms(a,x) memset(a,x,sizeof(a))
using namespace std;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;
const int N=1E5+7;
int n;
LL x1,x2;
pair<LL,LL>li[N];



int main()
{
  #ifndef  ONLINE_JUDGE 
//   freopen("in.txt","r",stdin);
  #endif

   scanf("%d",&n);
   scanf("%lld %lld",&x1,&x2);
   LL b,k;
   for ( int i = 0 ; i < n ; i++)
    {
	scanf("%lld %lld",&k,&b);
	li[i]=make_pair(k*x1+b,k*x2+b);
    }
   sort(li,li+n);
   bool ok = false;
   for ( int i = 1 ; i < n ; i++)
       if (li[0].second>li[i].second)
	{
	    ok = true;
	    break;
	}

   if (!ok) puts("NO");
   else puts("YES");

  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
