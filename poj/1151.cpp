/* ***********************************************
Author :111qqz
Created Time :2017年09月27日 星期三 16时37分39秒
File Name :1542.cpp
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
const int N=205;
int n;

double X[N]; //存储所有x坐标，用来离散化。
//扫描线
struct Seg
{
    double l,r,h;
    //表示扫面线的起点，终点，所在的高度(y坐标）
    int d;//1或者-1，表示扫描线对面积是正向影响还是负向影响
    Seg(){}
    Seg(double l,double r,double h,int d):l(l),r(r),h(h),d(d){}
    bool operator < (const Seg &rhs)const
    {
	return h<rhs.h;
    }
    //从下向上处理扫描线。
}seg[N];
struct Tree
{
    int cnt;
    double len;
}tree[N<<2];
void PushUp(int l,int r,int rt)
{
    /*由于线段树的节点表示的其实是长度为1的区间
     * 因此线段树的区间[l,r]，对应的点的端点是l,r+1
     */
    if (tree[rt].cnt) tree[rt].len = X[r+1]-X[l]; //当前区间已经完全被线段覆盖
    else if (l==r) tree[rt].len=0; //是叶子节点而且没有被覆盖。
    else tree[rt].len = tree[rt<<1].len + tree[rt<<1|1].len; //没有完全被覆盖，从其子区间获得信息。
}

void update( int L,int R,int v,int l,int r,int rt)
{
    if (L<=l && r<=R)
    {
	tree[rt].cnt+=v;
	PushUp(l,r,rt);
	return;
    }
    int m = (l+r)>>1;
    if (L<=m) update(L,R,v,lson);
    if (R>=m+1) update(L,R,v,rson);
    PushUp(l,r,rt);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	int cas = 0;
	while (~scanf("%d",&n)&&n)
	{
	    ms(tree,0);
	    for ( int i = 1 ; i <= n ; i++)
	    {
		double x1,y1,x2,y2;
		scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
		seg[i] = Seg(x1,x2,y1,1);
		seg[i+n]= Seg(x1,x2,y2,-1);
		X[i] = x1;
		X[i+n] = x2;
	    }
	    n<<=1;
	    sort(X+1,X+n+1);
	    int m = unique(X+1,X+1+n)-X-1;
	    
	    sort(seg+1,seg+n+1);
	    double ans = 0;
	    for ( int i = 1 ; i < n ; i++)
	    {
		int l = lower_bound(X+1,X+1+m,seg[i].l)-X;
		int r = lower_bound(X+1,X+1+m,seg[i].r)-X;
		if (l<r)
		update(l,r-1,seg[i].d,1,m,1);
		ans += tree[1].len * (seg[i+1].h-seg[i].h);
	    }
	    printf("Test case #%d\nTotal explored area: %.2f\n\n",++cas,ans);
	    
	}	

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
