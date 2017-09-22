/* ***********************************************
Author :111qqz
Created Time :2016年07月30日 星期六 18时15分02秒
File Name :code/hdu/1425.cpp
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
const int N=1E6+7;
const int C=5E5;
int n,m;
int a[N];
int cnt[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (~scanf("%d%d",&n,&m))
	{
	    int l = inf;
	    int r = -inf;
	    ms(cnt,0);
	    for ( int i = 1 ; i <= n ; i++ )
	    {
		scanf("%d",&a[i]);
		l = min(l,C+a[i]);
		r = max(r,C+a[i]);
		cnt[C+a[i]]++;
//		cout<<"i:"<<i<<endl;

	    }

	    int num = 0 ;
	    for ( int i = r ; i >= l&&num<m ; i--)
	    {
		while (cnt[i])
		{
		    num++;
		    if (num!=m)
		    printf("%d ",i-C);
		    else printf("%d\n",i-C);
		    cnt[i]--;
		    if (num==m) break;
		}
	    }
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
