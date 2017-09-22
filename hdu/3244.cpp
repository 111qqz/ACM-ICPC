/* ***********************************************
Author :111qqz
Created Time :2016年11月17日 星期四 20时05分54秒
File Name :code/hdu/3244.cpp
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
const int N=2E5+7;
int n;
int x,y,z;
int a[N],b[N],c[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	while (~scanf("%d",&n))
	{
	    if (n==0) break;
	    for ( int i = 1; i  <= n ; i++)
	    {
		scanf("%d%d%d",&x,&y,&z);
		a[i] = x - y;
		b[i] = y - z;
		c[i] = z - x;
	    }
	    sort(a+1,a+n+1);
	    sort(b+1,b+n+1);
	    sort(c+1,c+n+1);
	    LL ans = 0 ;
	    for (  int i = 1 ; i <= n ; i++)
	    {
		ans += 1LL*(i-1)*a[i];
		ans +=-1LL*(n-i)*a[i];	
		ans += 1LL*(i-1)*b[i];
		ans +=-1LL*(n-i)*b[i];	
		ans += 1LL*(i-1)*c[i];
		ans +=-1LL*(n-i)*c[i];
	    }
	    printf("%lld\n",ans/2);
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
