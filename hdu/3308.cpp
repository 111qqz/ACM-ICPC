/* ***********************************************
Author :111qqz
Created Time :2016年11月26日 星期六 18时12分49秒
File Name :code/hdu/3308.cpp
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
int n,m;
int a[N];
struct Tree
{
    int mx,lm,rm;
}tree[N<<2];
void PushUp(int rt,int l,int r)
{
    tree[rt].lm = tree[rt<<1].lm;
    tree[rt].rm = tree[rt<<1|1].rm;
    tree[rt].mx = max(tree[rt<<1].mx,tree[rt<<1|1].mx);
    int m = (l+r)>>1;
    if (a[m]<a[m+1])
    {
	if (tree[rt<<1].lm==m-l+1) tree[rt].lm+=tree[rt<<1|1].lm;
	if (tree[rt<<1|1].rm == r-m) tree[rt].rm += tree[rt<<1].rm;
	tree[rt].mx = max(tree[rt].mx,tree[rt<<1].rm + tree[rt<<1|1].lm);
    }
}
void build( int l,int r,int rt)
{
    if (l==r)
    {
	tree[rt].mx = tree[rt].lm = tree[rt].rm = 1;
	return;
    }
    int m = (l+r)>>1;
    build(lson);
    build(rson);
    PushUp(rt,l,r);
}
void update( int p,int sc,int l,int r,int rt)
{
    if (l==r)
    {
	a[p] = sc;
	return ;
    }
    int m = (l+r)>>1;
    if (p<=m) update(p,sc,lson);
    else update(p,sc,rson);
    PushUp(rt,l,r);
}
int query(int L,int R,int l,int r,int rt)
{
 //   printf("l:%d r: %d rt:%d tree[rt].mx :%d\n",l,r,rt,tree[rt].mx);
    if (L<=l&&r<=R) return tree[rt].mx;
    int m = (l+r)>>1;
    int ret = 0 ;
    if (L<=m) ret = max(ret,query(L,R,lson)); 
    if (R>=m+1) ret = max(ret,query(L,R,rson));
    if (a[m]<a[m+1])
    {
	ret = max(ret,min(tree[rt<<1|1].lm,R-m)+min(tree[rt<<1].rm,m-L+1)); //一段区间对答案的贡献不会超过区间长度
    }
    return ret;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	while (T--)
	{
	    scanf("%d %d",&n,&m);
	    for ( int i = 1; i <= n ; i++) scanf("%d",&a[i]);
	    ms(tree,0);
	    build(1,n,1);
	    while (m--)
	    {
		char opt[3];
		int x,y;
		scanf("%s %d %d",opt,&x,&y);
		if (opt[0]=='Q') printf("%d\n",query(x+1,y+1,1,n,1));
		else update(x+1,y,1,n,1);
	    }
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
