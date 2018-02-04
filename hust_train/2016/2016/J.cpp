/* ***********************************************
Author :111qqz
Created Time :2016年05月28日 星期六 16时24分55秒
File Name :code/hust/2016/J.cpp
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
const int N=1E5+7;
int n;
LL sum[N];
struct  Hand
{
    LL l,r;

    
}h[N];

bool cmp(Hand a,Hand b)
{
  //  return a.l-a.r>b.l-b.r;
   // return a.l-a.r<b.l-b.r;
    return a.r+b.r<a.l+b.l;
}
LL llmax( LL a,LL b)
{
    if (a>b) return a;
    else return b;
}
int main()
{
//	#ifndef  ONLINE_JUDGE 
//	freopen("code/in.txt","r",stdin);
//  #endif

	while (scanf("%d%lld%lld",&n,&h[0].l,&h[0].r)!=EOF)
	{

	    ms(sum,0);
	    sum[0] = h[0].r;
	    for ( int i = 1 ; i <= n ; i++) scanf("%lld %lld",&h[i].l,&h[i].r);

	    sort(h+1,h+n+1,cmp);
	    for ( int i = 1 ; i <= n ; i++) sum[i] = sum[i-1] + h[i].r;
	    LL mx = -1LL;

	    for ( int i = 1 ; i <= n ; i++)
	    {
		LL tmp = sum[i-1]-h[i].l;
		mx = llmax(mx,tmp);
	    }
	    printf("%lld\n",mx);
	}

//  #ifndef ONLINE_JUDGE  
//  fclose(stdin);
//  #endif
    return 0;
}
