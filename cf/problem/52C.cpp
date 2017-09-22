/* ***********************************************
Author :111qqz
Created Time :Mon 26 Sep 2016 05:30:21 AM CST
File Name :code/cf/problem/52C.cpp
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
const int N=2E5+7;
int n,m;
LL a[N];
LL tree[N<<2];
LL lazy[N<<2];
void PushUp( int rt)
{
    tree[rt] = min(tree[rt<<1],tree[rt<<1|1]);
}
void PushDown( int rt)
{
    if (lazy[rt])
    {
	lazy[rt<<1] += lazy[rt];
	lazy[rt<<1|1] +=lazy[rt];
	tree[rt<<1] +=lazy[rt];
	tree[rt<<1|1] +=lazy[rt];
	lazy[rt] =  0;
    }
}
void build(  int l,int r,int rt)
{
    if (rt)
    if (l==r)
    {
	tree[rt] = a[l] ;
	return;
    }
    int m = (l+r)>>1;
    build(lson);
    build(rson);
    PushUp(rt);
}
void update(int L,int R,LL sc,int l,int r,int rt)
{
    if (L<=l&&r<=R)
    {
	lazy[rt] +=sc;
	tree[rt] +=sc;
	return;
    }
    PushDown(rt);
    int m = (l+r)>>1;
    if (L<=m) update(L,R,sc,lson);
    if (R>=m+1) update(L,R,sc,rson);
    PushUp(rt);
}
LL query( int L,int R,int l,int r,int rt)
{
    if (L<=l&&r<=R) return tree[rt];
    PushDown(rt);
    int m = (l+r)>>1;
    LL ret = 1LL<<60;
    if (L<=m) ret = min(ret,query(L,R,lson));
    if (R>=m+1) ret = min(ret,query(L,R,rson));
    return ret;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	scanf("%d",&n);
	for ( int i = 1 ; i <= n ; i++) scanf("%lld",&a[i]);
	scanf("%d",&m);
	getchar(); //记得回车符。。。
	build(1,n,1);
	while (m--)
	{
	    char str[50];
	    gets(str);
	    int l,r;
	    LL v;
	    if (sscanf(str,"%d%d%lld",&l,&r,&v)==3)
	    {
		l++;
		r++;
		if (l<=r)
		update(l,r,v,1,n,1);
		else update(l,n,v,1,n,1),update(1,r,v,1,n,1);
	    }else
	    {
		l++;
		r++;
		LL ans;
		if (l<=r)
		 ans = query(l,r,1,n,1);
		else ans = min(query(1,r,1,n,1),query(l,n,1,n,1));
		printf("%lld\n",ans);
	    }
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
