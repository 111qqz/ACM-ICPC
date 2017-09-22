/* ***********************************************
Author :111qqz
Created Time :2016年08月20日 星期六 01时27分37秒
File Name :code/uvalive/5881.cpp
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <deque>
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
int a[N],b[N];
int n,m;
map<int,int>mp;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	while (~scanf("%d%d",&n,&m))
	{
	    if (n==0&&m==0) break;
	    mp.clear();
	    for ( int i = 1 ; i <= n ; i++) scanf("%d",a+i);
	    b[n+1] = n+1;//b[i]表示的是a[i]后面距离i最近的出现相等的位置
	    
	    for ( int i = n ; i >=1 ; i--)
	    {
		b[i] = b[i+1];
		if (mp[a[i]])
		    b[i] = min(mp[a[i]],b[i]);
		mp[a[i]] = i;
	    }
	    while (m--)
	    {
		int x;
		int y;
		scanf("%d%d",&x,&y);
		if (b[x]>y)
		    puts("OK");
		else printf("%d\n",a[b[x]]);
	    }
	    printf("\n");

	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
