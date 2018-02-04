/* ***********************************************
Author :111qqz
Created Time :2017年10月11日 星期三 14时38分42秒
File Name :I.cpp
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
#define PB push_back
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
LL L,R;
void pr( LL a[], int n)
{
    for ( int i = 1 ; i <= n ; i++) printf("%lld%c",a[i],i==n?'\n':' ');
}
LL solve( LL l,LL r)
{
    LL dig[2][100]={};
    LL ans[100]={};
    int tot=0;
    int cnt[2]={};
    while (l>0)
    {
	dig[0][++cnt[0]] = l % 2LL;
	l/=2;
    }
    while (r>0)
    {
	dig[1][++cnt[1]] = r % 2;
	r/=2;
    }
    
    for ( int i = 1 ; i <= cnt[1]/2 ; i++) swap(dig[0][i],dig[0][cnt[1]-i+1]);
    for ( int i = 1 ; i <= cnt[1]/2 ; i++) swap(dig[1][i],dig[1][cnt[1]-i+1]);
    bool ok = false;
    //cout<<cnt[0]<<endl;
    //pr(dig[0],cnt[1]);
    for ( int i = 1 ; i <= cnt[1] ; i++)
    { 
	if (dig[1][i]==1&&dig[0][i]==0) ok = true;
	if (ok) ans[++tot]=1;
	else
	{
	    if (dig[1][i]==1&&dig[0][i]==1) ans[++tot]=1;
	    else if (dig[1][i]==0&&dig[0][i]==0) ans[++tot] = 0;
	}
    }
    LL ret = 0LL;
    //pr(ans,tot);
    for ( int i = 1 ; i <= tot ; i++)
    {
	ret = ret << 1LL;
	ret = ret + 1LL* ans[i];
    }
    return ret;
}

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	int T;
	scanf("%d",&T);
	while (T--)
	{
	    scanf("%lld %lld",&L,&R);
	    LL ans = solve(L,R);
	    printf("%lld\n",ans);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
