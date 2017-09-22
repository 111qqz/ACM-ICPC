/* ***********************************************
Author :111qqz
Created Time :2016年07月30日 星期六 17时58分04秒
File Name :code/hdu/1280.cpp
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
const int N=3005;
const int M=1E4+7;
int n;
int a[N];
int cnt[M];
int m;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	
	while (~scanf("%d %d",&n,&m))
	{
	    ms(a,0);
	    ms(cnt,0);
	    for ( int i = 1 ; i <= n ; i++) scanf("%d",&a[i]);
	    int mx = 0;
	    for (  int i = 1 ; i <= n-1 ; i++)
		for ( int j = i+1 ; j <= n ; j++)
		    cnt[a[i]+a[j]]++,mx = max(mx,a[i]+a[j]);

//	    cout<<"mx:"<<mx<<endl;
	    int num = 0 ;
	    for ( int i = mx ; i >=1&&num<m; i--)
	    {
		while (cnt[i]>0)
		{
		    num++;
		    if (num!=m)
		    printf("%d ",i);
		    else printf("%d\n",i);
		    cnt[i]--;
		    if (num==m) break;
		}
	    }
	 //   puts("");
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
