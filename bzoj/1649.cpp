/* ***********************************************
Author :111qqz
Created Time :2016年04月11日 星期一 16时43分19秒
File Name :code/bzoj/1649.cpp
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
const int N=1E4+3;
int n,l,b;
int dp[1005][1005];
struct node
{
    int l,r;
    int w;
    int f;
    int c;

    bool operator < (node b) const
    {
	if (l==b.l) return r<b.r;
	return l<b.l;
    }

}p[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	scanf("%d %d %d",&l,&n,&b);
	for ( int i = 1 ; i <= n ; i++)
	{
	    scanf("%d %d %d %d",&p[i].l,&p[i].w,&p[i].f,&p[i].c);
	    p[i].r = p[i].l + p[i].w;
	}

	sort(p+1,p+n+1);

	ms(dp,-1);
	dp[0][0] = 0;
	for ( int i = 1 ; i <= n ; i++)
	{
	    for ( int j = p[i].c ;  j <= b ; j++) 
		if (dp[p[i].l][j-p[i].c]!=-1) dp[p[i].r][j]=max(dp[p[i].r][j],dp[p[i].l][j-p[i].c]+p[i].f);
	}
	int ans = 0 ;
	for ( int i = 1 ;i <= b ; i++) ans = max(ans,dp[l][i]);
	printf("%d\n",ans);



  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
