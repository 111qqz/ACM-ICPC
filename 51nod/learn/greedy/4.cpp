/*************************************************************************
	> File Name: code/51nod/learn/greedy/4.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月11日 星期日 16时08分34秒
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
const int N=1E6+7;
int n;
struct Q
{
    int a,b;
}q[N];
int r[N],o[N];
bool cmp(Q x,Q y)
{
    return x.b>y.b;
}
int main()
{
 // #ifndef  ONLINE_JUDGE 
//   freopen("in.txt","r",stdin);
//  #endif
   
   scanf("%d",&n);
   for ( int i = 0 ; i < n ; i++)
    {
	int x,y;
	scanf("%d %d",&r[N],&o[N]);
	q[i].a = r[N];
	q[i].b =r[N] - o[N];
    }
   sort(q,q+n,cmp);
   int now = 0 ;
   int ans = 0 ;
   for ( int i = 0 ; i < n ; i ++)
    {
	now = now + q[i].a;
	ans = max(ans,now);
	now = now - q[i].b;

    }
   printf("%d",ans);
      
   
// #ifndef ONLINE_JUDGE  
//  fclose(stdin);
//  #endif
	return 0;
}
