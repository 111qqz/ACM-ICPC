/* ***********************************************
Author :111qqz
Created Time :2016年09月04日 星期日 13时44分09秒
File Name :code/poj/r2481.cpp
************************************************ */
//之前这道题是用树状数组过的，这次写一个线段树版本
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
int tree[N<<2];//tree的含义很简单，表示的就是以节点i为根的子树所代表的区间中的点的个数。（由于初始没有点插入，所以初始化tree为0.
int n ;
int ans[N];
struct node
{
    int l,r;
    int id; //由于排序后打乱了顺序，所以要记录id.
    bool operator < (node b)const
    {
	if (r!=b.r) return r>b.r;
	return l<b.l;
    }
    bool operator == (node b)const
    {
	return l==b.l&&r==b.r;
    }
}a[N];
void PushUp(int rt)
{
    tree[rt] = tree[rt<<1]+tree[rt<<1|1];
}
void update( int p,int l,int r,int rt)
{
    if (l==r)
    {
	tree[rt]++;
	return ;
    }
    int m = (l+r)>>1;
    if (p<=m) update(p,lson);
    else update(p,rson);
    PushUp(rt);
}
int query(int L,int R,int l,int r,int rt)
{
    if (L<=l&&r<=R)
	return tree[rt];
    int m = (l+r)>>1;
    int ret = 0 ;
    if (L<=m)
    {
	int res = query(L,R,lson);
	ret = ret + res;
    }
    if (R>=m+1)
    {
	int res = query(L,R,rson);
	ret = ret + res;
    }
    return ret;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	while (~scanf("%d",&n))
	{
	    if (n==0) break;
	    for ( int i = 1 ; i <= n ; i++)
	    {
		scanf("%d%d",&a[i].l,&a[i].r);
		a[i].l++;
		a[i].r++; //index from 1 .
		a[i].id = i;
	    }
	    sort(a+1,a+n+1);
	    ms(ans,0);
	    ms(tree,0);
	    for ( int i = 1 ; i <= n ; i++)
	    {
		if (i>=2&&a[i]==a[i-1])
		    ans[a[i].id] = ans[a[i-1].id];
		else ans[a[i].id] = query(1,a[i].l,1,1E5,1);
		update(a[i].l,1,1E5,1);
	    }
	    for ( int i = 1 ; i <= n ; i++)
		printf("%d%c",ans[i],i==n?'\n':' ');
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
