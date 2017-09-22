/* ***********************************************
Author :111qqz
Created Time :2016年01月20日 星期三 23时38分40秒
File Name :code/uva/10474.cpp
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
int n;
int q;
int a[N];
int pos[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int cas = 0 ;
	while (scanf("%d %d",&n,&q)!=EOF)
	{

	    if (n==0&&q==0) break;
	    printf("CASE# %d:\n",++cas);
	    for ( int i = 0 ; i < n ; i++) scanf("%d",&a[i]);
	    sort(a,a+n);
	    ms(pos,-1);
	    for ( int i = 0 ; i < n ; i++)
		if (pos[a[i]]==-1) pos[a[i]] = i+1;
	    
	    while (q--)
	    {
		int x;
		scanf("%d",&x);
		if (pos[x]==-1)
		{
		    printf("%d not found\n",x);
		}
		else
		{
		    printf("%d found at %d\n",x,pos[x]);
		}
	    }

	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
