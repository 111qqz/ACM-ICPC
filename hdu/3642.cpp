/* ***********************************************
Author :111qqz
Created Time :2017年09月28日 星期四 14时18分35秒
File Name :hdu3642.cpp
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
const int N=2E3+7;
int n;
struct Seg
{
    LL l,r,h;
    int d;
    Seg(){}
    Seg(LL l,LL r,LL h,int d):l(l),r(r),h(h),d(d){}
    bool operator < (const Seg & rhs)const
    {
	return h < rhs.h;
    }
}a[N];
struct Tree
{
    LL one,two,three;
    int cnt;
}tree[N<<2];
LL X[N],Z[N];
struct Cube
{
    LL  x1,y1,z1,x2,y2,z2;
}cube[N];
struct Rec
{
    LL x1,y1,x2,y2;
    void print()
    {
	printf("x1:%lld y1:%lld x2:%lld y2:%lld\n",x1,y1,x2,y2);
    }
    Rec(){}
    Rec(LL x1, LL y1,LL x2, LL y2):x1(x1),y1(y1),x2(x2),y2(y2){}
};
vector< Rec >rec[N];
void PushUp(int l,int r,int rt)
{
    //cout<<"l:"<<l<<" r:"<<r<<" rt:"<<rt<<" id:"<<id<<endl;
    if (tree[rt].cnt>=3)
    {
	    tree[rt].one = tree[rt].two = tree[rt].three = X[r+1]-X[l];
    }
    else 
    if (tree[rt].cnt==2)
    {
	tree[rt].one = tree[rt].two = X[r+1]-X[l];
	
	if (l==r) tree[rt].three = 0 ;
	else tree[rt].three = tree[rt<<1].one + tree[rt<<1|1].one;

    }else if (tree[rt].cnt==1)
    {
	    tree[rt].one = X[r+1] - X[l];

	if (l==r) tree[rt].two = tree[rt].three = 0;
	else 
	{
	    tree[rt].two = tree[rt<<1].one + tree[rt<<1|1].one;
	    tree[rt].three = tree[rt<<1].two + tree[rt<<1|1].two;
	}
    }
    else
    {
	if (l==r) tree[rt].one = tree[rt].two =  tree[rt].three = 0;
	else 
	{
	    tree[rt].one = tree[rt<<1].one + tree[rt<<1|1].one;
	    tree[rt].two = tree[rt<<1].two + tree[rt<<1|1].two;
	    tree[rt].three = tree[rt<<1].three + tree[rt<<1|1].three;
	}
    }
}
void update( int L,int R,int val,int l,int r,int rt)
{
    if (L<=l && r<=R)
    {
	tree[rt].cnt +=val;
	PushUp(l,r,rt);
	return;
    }
    int m = (l+r)>>1;
    if (L<=m) update(L,R,val,lson);
    if (R>=m+1) update(L,R,val,rson);
    PushUp(l,r,rt);
}

LL solve( int z)
{
    int siz = rec[z].size();
    if (siz<3) return 0LL;
   // for ( int i = 0 ; i < siz ; i++) rec[z][i].print();
    ms(tree,0);
    for ( int i = 0 ; i < siz ; i++)
    {
	LL x1 = rec[z][i].x1;
	LL y1 = rec[z][i].y1;
	LL x2 = rec[z][i].x2;
	LL y2 = rec[z][i].y2;
//	printf("x1:%lld y1:%lld x2:%lld y2:%lld\n",x1,y1,x2,y2);
	X[i+1] = x1;
	X[i+1+siz] = x2;
	a[i+1]=Seg(x1,x2,y1,1);
	a[i+1+siz]=Seg(x1,x2,y2,-1);
    }
    siz<<=1;
    sort(X+1,X+siz+1);
    sort(a+1,a+siz+1);
    int m = unique(X+1,X+siz+1)-X-1;
    LL ret = 0;
    for ( int i = 1 ; i < siz; i++)
    {
	int l = lower_bound(X+1,X+m+1,a[i].l)-X;
	int r = lower_bound(X+1,X+m+1,a[i].r)-X;
	update(l,r-1,a[i].d,1,m,1);
	ret += tree[1].three * (a[i+1].h-a[i].h);
    }
    //cout<<"Z:"<<z<<" ret:"<<ret<<endl;
    return ret;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	int T;
	int cas =  0;
	cin>>T;
	while (T--)
	{
	    scanf("%d",&n);
	    ms(tree,0);
	    for ( int i = 0 ; i < N ; i++) rec[i].clear();
	    for ( int i = 1 ; i <= n ; i++)
	    {
		scanf("%lld %lld %lld",&cube[i].x1,&cube[i].y1,&cube[i].z1);
		scanf("%lld %lld %lld",&cube[i].x2,&cube[i].y2,&cube[i].z2);
		//此处先存储下来是为了将Z坐标离散化
		Z[i] = cube[i].z1;
		Z[i+n] = cube[i].z2;
		for ( int j = cube[i].z1 ; j < cube[i].z2 ; j++)
		{
                    rec[j+500].PB(Rec(cube[i].x1,cube[i].y1,cube[i].x2,cube[i].y2));
		}
	    }
	    LL ans = 0;
	    for ( int i = 0 ; i <=1000 ; i++)
	    {
		ans += solve(i);
	    }
	    printf("Case %d: %lld\n",++cas,ans);
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
