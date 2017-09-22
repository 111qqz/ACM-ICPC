/*************************************************************************
	> File Name: code/uva/591.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年09月18日 星期五 08时41分10秒
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
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define ms(a,x) memset(a,x,sizeof(a))
#define lr dying111qqz
using namespace std;
#define For(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;

struct Q
{
    int w,h;
}q[10];


bool cmp(Q a,Q b)
{
    if (a.w<b.w) return true;
    if (a.w==b.w&&a.h<b.h) return true;
    return false;
}
int main()
{
  #ifndef  ONLINE_JUDGE 
    freopen("in.txt","r",stdin); 
  #endif
    while (scanf("%d %d",&w[0],&h[0])!=EOF)
    {
	for ( int i = 1 ; i < 6 ; i++)
	{
	    scanf("%d %d",&q[i].w,&q[i].h);
	}
	sort(q,q+6,cmp);
	bool mp = false;
	if (q[0].w==q[1].w&&q[0].h==q[1].h)
	{
	    if (q[2].w==q[3].w&&q[2].h==q[3].h)
	    {
		if (q[4].w==q[5].w&&q[4].h==q[5].h)
		{
		    mp = true;
		}
	    }
	}
	if (!mp)
	{
	    puts("IMPOSSIBLE");
	    break;
	}
	if (q[0].w==q[2].w&&q[0].h==q[4].h&&q[2].h==q[4].w)
	{
	    puts("POSSIBLE");
	    break;
	}
	if ()


	
    }
  
  
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
