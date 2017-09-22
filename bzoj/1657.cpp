/* ***********************************************
Author :111qqz
Created Time :2016年04月15日 星期五 15时34分08秒
File Name :code/bzoj/1657.cpp
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
const int N=5E4+7;
int left[N],right[N];
int n;
int h[N],v[N];
int st[N];
int ans;
int val[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	scanf("%d",&n);
	for ( int i = 1 ; i <= n ; i++) scanf("%d %d",&h[i],&v[i]);

	int top = 0;
	ans = 0 ;
	for (int i = 1 ; i <= n ; i++) //枚举i，将i作为作为右边能听到歌的奶牛，看左边有多少个奶牛的歌声能被听到。
	{
	    while (top&&h[i]>h[st[top]])   val[i]+=v[st[top--]];
	    st[++top] = i;
	}
	ms(st,0);
	top = 0 ;
	for ( int i = n ; i >= 1 ; i--) //枚举i,将i作为左边能听到歌声的奶牛，看右边有多少个奶牛的歌声能被听到。
	{
	    while (top&&h[i]>h[st[top]])
		val[i]+=v[st[top--]];
	    st[++top] = i;
	}
	for ( int i = 1 ; i <= n ; i++) ans = max(ans,val[i]);
	cout<<ans<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
