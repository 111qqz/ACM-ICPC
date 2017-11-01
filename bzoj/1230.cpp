/* ***********************************************
Author :111qqz
Created Time :2017年11月01日 星期三 09时51分31秒
File Name :1230.cpp
************************************************ */

#include <bits/stdc++.h>
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
const int N=1E5+7;
int n,m;
struct Tree
{
    int lazy;
    int sum;
}tree[N<<2];
void PushDown(int l,int r,int rt)
{
    if (tree[rt].lazy)
    {
	int m = (l+r)>>1;
	tree[rt<<1].lazy  = 1- tree[rt<<1].lazy;
	tree[rt<<1|1].lazy = 1- tree[rt<<1|1].lazy;
	tree[rt<<1].sum = m-l+1-tree[rt<<1].sum;
	tree[rt<<1|1].sum = r-m - tree[rt<<1|1].sum;
	tree[rt].lazy = 0;
    }
}
void PushUp( int rt)
{
    tree[rt].sum = tree[rt<<1].sum + tree[rt<<1|1].sum;
}
void update(int L,int R,int l,int r,int rt)
{
    if (L<=l && r<=R)
    {
	tree[rt].sum = r-l+1 - tree[rt].sum;
	tree[rt].lazy  = 1-tree[rt].lazy;
	return;
    }
    int m = (l+r)>>1;
    PushDown(l,r,rt);
    if (L<=m) update(L,R,lson);
    if (R>=m+1) update(L,R,rson);
    PushUp(rt);
}
int Query(int L, int R,int l,int r,int rt)
{
    if (L<=l && r<=R)
    {
	return tree[rt].sum;
    }
    int m = (l+r)>>1;
    PushDown(l,r,rt);
    int res = 0 ;
    if (L<=m) res = Query(L,R,lson);
    if (R>=m+1) res = res + Query(L,R,rson);
    return res;
}

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	ms(tree,0);
	cin>>n>>m;
	while (m--)
	{
	    int opt,x,y;
	    scanf("%d %d %d",&opt,&x,&y);
	    if (opt==0) update(x,y,1,n,1);
	    else printf("%d\n",Query(x,y,1,n,1));
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
