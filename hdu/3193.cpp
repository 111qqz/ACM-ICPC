/* ***********************************************
Author :111qqz
Created Time :2016年05月16日 星期一 20时15分21秒
File Name :code/hdu/3193.cpp
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
const int N=1E4+7;
pi a[N];
int n;
pi ans[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

    	while (scanf("%d",&n)!=EOF){
	    ms(ans,0);
	    ms(a,0);
	    for ( int i = 1 ; i <= n ; i++) scanf("%d %d",&a[i].fst,&a[i].sec);
	    sort(a+1,a+n+1);
	    pi mnf = make_pair(inf,inf);
	    pi mns = make_pair(inf,inf);
	    for ( int i = 1 ; i <= n ; i++)
	    {
		if (a[i].fst<mnf.fst)
		{
		    mnf = a[i];
		}
		if (a[i].sec<mns.sec)
		{
		    mns = a[i];
		}
	    }

	    int cnt = 0 ;
	    for ( int i = 1 ; i <= n ; i++)
	    {
		if (a[i].fst>mnf.fst&&a[i].sec>mnf.sec) continue;
		if (a[i].fst>mns.fst&&a[i].sec>mns.sec) continue;
		if (a[i].fst==mnf.fst||a[i].sec==mns.sec)
		{
		    ans[++cnt]=make_pair(a[i].fst,a[i].sec);
		    continue;
		}
		if (a[i].sec<=mnf.sec||a[i].fst<=mns.fst)
		{
		    ans[++cnt] = make_pair(a[i].fst,a[i].sec);
		}
	    }

	    sort(ans+1,ans+cnt+1);
	    printf("%d\n",cnt);
	for ( int i = 1 ; i <= cnt ; i++)
	{
	    if (i>=2)
	    {
		if (a[i].fst>a[i-1].fst&&a[i].sec>a[i-1].sec) continue;
	    }
	    printf("%d %d\n",a[i].fst,a[i].sec);
	}
	}

#ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}

/* 出错数据：
   5
   5 10
   5 8
   4 10
   4 12
   4 15
*/

/*
  6
  4 15
  4 12
  4 10
  5 8
  5 9
  6 7

*/

/*
  6
  23 435
  100 43
  99 234
  50 123
  100 7
  324 15

  */
