/* ***********************************************
Author :111qqz
Created Time :Fri 16 Sep 2016 03:15:50 AM CST
File Name :code/bzoj/1756.cpp
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
const int N=5E5+7;
int n,m;
int a[N];
struct Tree
{
    int sum;
    int mxl;
    int mxr;
    int mx;
}tree[N<<2];
void PushUp(int rt)
{
    tree[rt].sum = tree[rt<<1].sum+tree[rt<<1|1].sum;
    if (tree[rt<<1].mxr>0&&tree[rt<<1|1].mxl>0)
	tree[rt].mx = tree[rt<<1].mxr+tree[rt<<1|1].mxl;
    else tree[rt].mx = max(tree[rt<<1].mxr,tree[rt<<1|1].mxl);
    tree[rt].mx = max(tree[rt].mx,max(tree[rt<<1].mx,tree[rt<<1|1].mx));
    tree[rt].mxl=max(tree[rt<<1].mxl,tree[rt<<1].sum+tree[rt<<1|1].mxl);
    tree[rt].mxr=max(tree[rt<<1|1].mxr,tree[rt<<1|1].sum+tree[rt<<1].mxr);
}
void build(int l,int r,int rt)
{
 //   cout<<"l:"<<l<<" r:"<<r<< " rt:"<<rt<<endl;
    if (l==r)
    {
	int tmp;
	scanf("%d",&tmp);
//	cout<<"tmp:"<<tmp<<endl;
	tree[rt].mx = tree[rt].mxl = tree[rt].mxr = tree[rt].sum = tmp;
	return ;
    }
    int m = (l+r)>>1;
    build(lson);
    build(rson);
    PushUp(rt);
}
void update( int p,int sc,int l,int r,int rt)
{
    if (l==r)
    {
	tree[rt].mx = tree[rt].mxl = tree[rt].mxr = tree[rt].sum = sc;
	return ;
    }
    int m = (l+r)>>1;
    if (p<=m) update(p,sc,lson);
    else update(p,sc,rson);
    PushUp(rt);
}
Tree query(int L,int R,int l,int r,int rt)
{
    if (L<=l&&r<=R) return tree[rt];
    int m = (l+r)>>1;
    if (L<=m&&R>=m+1)
    {
	Tree root,ltree,rtree;
	ltree=query(L,R,lson);
	rtree=query(L,R,rson);
	root.sum = ltree.sum + rtree.sum;
	if (ltree.mxr>0&&rtree.mxl>0)
	    root.mx = ltree.mxr + rtree.mxl;
	else root.mx = max(ltree.mxr,rtree.mxl);
	root.mx = max(root.mx,max(ltree.mx,rtree.mx));
	root.mxl = max(ltree.mxl,rtree.mxl+ltree.sum);
	root.mxr = max(rtree.mxr,ltree.mxr+rtree.sum);
	return root;
    }
    else
    if (L<=m) return query(L,R,lson);
    else   return query(L,R,rson);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	scanf("%d%d",&n,&m);
	build(1,n,1);
	while (m--)
	{
	    int opt;
	    scanf("%d",&opt);
	    if (opt==1)
	    {
		int a,b;
		scanf("%d%d",&a,&b);
		if (a>b) swap(a,b);
		int ans = query(a,b,1,n,1).mx;
		printf("%d\n",ans);
	    }else
	    {
		int p,x;
		scanf("%d%d",&p,&x);
		update(p,x,1,n,1);
	    }
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
