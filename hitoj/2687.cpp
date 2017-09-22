/* ***********************************************
Author :111qqz
Created Time :Fri 16 Sep 2016 04:01:49 AM CST
File Name :code/hitoj/2687.cpp
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
struct
{
    int mx;
    int mxr;
    int mxl;
    int sum;
}tree[N<<2];
void PushUp( int rt)
{
    tree[rt].sum = tree[rt<<1].sum + tree[rt<<1|1].sum;
    if (tree[rt<<1].mxr>0&&tree[rt<<1|1].mxl>0) //区间合并
	tree[rt].mx = tree[rt<<1].mxr + tree[rt<<1|1].mxl;
    else tree[rt].mx = max(tree[rt<<1].mxr,tree[rt<<1|1].mxl);
    tree[rt].mx = max(tree[rt].mx,max(tree[rt<<1].mx,tree[rt<<1|1].mx));
    tree[rt].mxl = max(tree[rt<<1].mxl,tree[rt<<1|1].mxl+tree[rt<<1].sum);
    tree[rt].mxr = max(tree[rt<<1|1].mxr,tree[rt<<1].mxr+tree[rt<<1|1].sum);
}
void build(int l,int r,int rt)
{
   // cout<<"l:"<<l<<" r:"<<r<<" rt:"<<rt<<endl;
    if (l==r)
    {
	int x;
	scanf("%d",&x);
	tree[rt].mx = tree[rt].mxl = tree[rt].mxr = tree[rt].sum = x;
	return;
    }
    int m = (l+r)>>1;
    build(lson);
    build(rson);
    PushUp(rt);
}
void update( int p,int sc,int l,int r,int rt)
{
//    cout<<"p:"<<p<<" sc:"<<sc<<" l:"<<l<<" r:"<<r<<" rt:"<<rt<<endl;
    if (l==r)
    {
	tree[rt].mx = tree[rt].mxl = tree[rt].mxr = tree[rt].sum = sc;
	return;
    }
    int m = (l+r)>>1;
    if (p<=m) update(p,sc,lson);
    else update(p,sc,rson);
    PushUp(rt);
}

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	while (~scanf("%d%d",&n,&m))
	{
	    build(1,n,1);
	    while (m--)
	    {
		int p,x;
		scanf("%d%d",&p,&x);
//		cout<<"p:"<<p<<" x:"<<x<<endl;
		update(p,x,1,n,1);
		printf("%d\n",tree[1].mx);
	    }
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
