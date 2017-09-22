/* ***********************************************
Author :111qqz
Created Time :2016年03月03日 星期四 20时09分47秒
File Name :code/hdu/4451.cpp
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
const int N=2E6+7;
int n,m,k;
int p;
int a[N];
int clo[N];
int sho[N];

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (~scanf("%d %d %d",&n,&m,&k)&&n&&m&&k)
	{
	    ms(clo,0);
	    ms(sho,0);
	    LL ans = 0LL;
	    scanf("%d",&p);
	    if (p==0)
	    {
		ans = 1LL*n*1LL*m*1LL*k;
		printf("%lld\n",ans);
		continue;
	    }
	    for ( int i = 0 ; i < p ; i++)
	    {
		char x[15],y[15];
		int xid,yid;
		scanf("%s %d %s %d",x,&xid,y,&yid);
		if (x[0]=='c') 
		{
		    clo[yid]++;
		}
		else
		{
		    sho[xid]++; 
		}
	    }

	    for ( int i = 1; i <= m ; i++)
	    {
		ans+=1LL*(n-clo[i])*1LL*(k-sho[i]);
	    }
	    printf("%lld\n",ans);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
