/* ***********************************************
Author :111qqz
Created Time :2016年05月17日 星期二 19时20分14秒
File Name :code/hdu/r3193.cpp
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
bool ok[N];
pi a[N];
int n;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (~scanf("%d",&n))
	{
	    for ( int i = 1 ; i <= n  ; i++) scanf("%d %d",&a[i].fst,&a[i].sec);
	    
	    ms(ok,false);
	    sort(a+1,a+n+1);
	    int ans = 0 ;
	    int tmp = inf;
	    int mn = inf;
	    for ( int  i = 1 ; i <= n ; i++)
	    {
		if (i!=1&&a[i].fst!=a[i-1].fst)
		{
		    mn = min(mn,tmp);
		    tmp = inf;
		}

		tmp = min(tmp,a[i].sec);
		if (mn<a[i].sec) ok [i] = false;
		else ok[i] = true,ans++;
	    }

	    printf("%d\n",ans);
	    for ( int i = 1 ; i <= n ; i++) if (ok[i]) printf("%d %d\n",a[i].fst,a[i].sec);
	}
    
 
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
