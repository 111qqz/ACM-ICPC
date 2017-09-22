/* ***********************************************
Author :111qqz
Created Time :Wed 14 Sep 2016 12:59:07 AM CST
File Name :code/loj/1080.cpp
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
const int N=1E5+7;
int lazy[N<<2];//记录翻转次数
int n;
string st;
int a[N];
void PushDown( int rt)
{
    if (lazy[rt])
    {
	lazy[rt<<1] +=lazy[rt];
	lazy[rt<<1|1]+=lazy[rt];
	lazy[rt] =  0;
    }
}
void build(int l,int r,int rt)
{
    if (l==r)
    {
	lazy[rt] = 0;
	return;
    }
    int m = (l+r)>>1;
    build(lson);
    build(rson);
}
void update(int L,int R,int l,int r,int rt)
{
    if (L<=l&&r<=R)
    {
	lazy[rt]++;
	return;
    }
    PushDown(rt);
    int m = (l+r)>>1;
    if (L<=m) update(L,R,lson);
    if (R>=m+1) update(L,R,rson);
}
int query( int p,int l,int r,int rt)
{
    if (l==r) return lazy[rt];
    PushDown(rt);
    int m = (l+r)>>1;
    //int res;
    if (p<=m)  query(p,lson);
    else  query(p,rson);
  //  return res;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	int T;
	cin>>T;
	int cas= 0 ;
	while (T--){
	    ms(lazy,0);
	    ms(a,0);
	    cin>>st;    
	    n = st.length();
	    for ( int i = 0 ; i < n ; i++)
	    {
		a[i+1] = st[i]-'0';
	    }
	    build(1,n,1);

		printf("Case %d:\n",++cas);
	    int q;
	    cin>>q;
	    while (q--)
	    {
		char opt[3];
		int x,y;
		scanf("%s",opt);
		if (opt[0]=='I')
		{
		    scanf("%d%d",&x,&y);
		    update(x,y,1,n,1);
		}
		else
		{
		    scanf("%d",&x);
		    int p = query(x,1,n,1);
		    int ans;
		    if (p%2==1) ans = 1-a[x];
		    else ans = a[x];
		    printf("%d\n",ans);
		}
	    }
	}



  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
