/* ***********************************************
Author :111qqz
Created Time :Sun 18 Sep 2016 01:11:37 PM CST
File Name :code/net/2016/shenyang/1007.cpp
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
int digit[40];
LL dp2[30][30][5];
LL dfs2(int pos,int cnt,int lst,bool limit,bool prehasnonzero)
{
    if (pos==0)
    {
	if (lst==1&&cnt%2==0) return 1;
       if (lst==2&&cnt%2==1) return 1;
	return 0;
    }
    if (prehasnonzero&&!limit&&dp2[pos][cnt][lst]!=-1) return dp2[pos][cnt][lst];
    int mx = limit?digit[pos]:9;
    LL res = 0 ;
    if (!prehasnonzero)
    {
	for ( int i = 0 ; i <= mx ; i++)
	{
	    res+=dfs2(pos-1,i==0?0:1,i==0?0:2-i%2,limit&&i==mx,i==0?false:true);
	}
    }
    else
    {
	for ( int i = 0 ; i <= mx ; i++)
	{
	   if (lst==1&&cnt>0&&cnt%2==0&&i%2==1&&pos==1) continue;
	    if (lst==1&&cnt%2==1&&i%2==0) continue;
	    if (lst==2&&cnt>0&&cnt%2==0&&i%2==1) continue;
	    if (lst==2&&cnt%2==1&&i%2==0&&pos==1) continue;
	    res+=dfs2(pos-1,((i%2==1&&lst==1)||(i%2==0&&lst==2))?cnt+1:1,2-i%2,limit&&i==mx,true);
	}
    }
    if (prehasnonzero&&!limit) dp2[pos][cnt][lst] = res;
    return res;
}
/*
LL dfs( int pos,int odd,int even,int lst,bool limit, bool prehasnonzero)
{
    if (pos==0) return 1;
    if (prehasnonzero&&!limit&&dp[pos][odd][even][lst]!=-1) return dp[pos][odd][even][lst];
    int mx = limit?digit[pos]:9;
    LL res = 0;
    if (prehasnonzero)
    {
	for ( int i = 0 ; i <= mx ; i++)
	{
	    if (lst==1)
	    {
		if (odd%2==0&&i%2==1) continue;
		if (odd%2==1&&i%2==0) continue;
	    }else if (lst==2)
	    {
		if (even%2==1&&i%2==0) continue;
		if (even%2==0&&i%2==1) continue;
	    }
	    cout<<"pos:"<<pos<<" i:"<<i<<endl;
	    res += dfs(pos-1,i%2==1?odd+1:0,i%2==0?even+1:0,i%2==0?2:1,limit&&i==mx,true);
	}
    }
    else
    {
	for ( int i = 0 ; i <= mx ; i++)
	{
	    cout<<"pos::"<<pos<<"  i:"<<i<<endl;
	    res += dfs(pos-1,i%2==1?1:0,i%2==0?1:0,0,limit&&i==mx,i==0?false:true);
	}
    }
	if (prehasnonzero&&!limit) dp[pos][odd][even][lst] = res;
    return res;
}  */
LL solve(LL n)
{
    ms(digit,0);
    int len = 0 ;
    while (n)
    {
	digit[++len] = n%10;
	n /= 10;
    }
	return dfs2(len,0,0,true,false);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	ms(dp2,-1);
	int cas = 0 ;
	while (T--)
	{
	    LL l,r;
	    scanf("%lld%lld",&l,&r);
	    LL ans = solve(r) - solve(l-1);
	    printf("Case #%d: ",++cas);
	    printf("%lld\n",ans);
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
