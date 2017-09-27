/* ***********************************************
Author :111qqz
Created Time :2017年09月27日 星期三 21时24分20秒
File Name :1828.cpp
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
const int N=1E4+7;
int n;
struct Seg
{
    double l,r,h;
    int d;
    Seg(){}
    Seg(double l,double r,double h,int d):l(l),r(r),h(h),d(d){}
    bool operator < (const Seg &rhs)const
    {
	return h < rhs.h;
    }
}a[N];

struct Tree
{
     int cnt;
     double len; 
}tree[N<<2];
double X[N];
void pushUP(int l,int r,int rt)
{
    if (tree[rt].cnt==1) tree[rt].len = X[r+1] - X[l];
    if (l==r) tree[rt].len = 0 ;
    else tree[rt].len = tree[rt<<1].len = tree[rt<<1|1].len;
}
void update( int L,int R,int val,int l,int r,int rt)
{
    if (L<=l && r<=R)
    {
	tree[rt].cnt+=val;
	pushUP(l,r,rt);
	return;
    }
    int m = (l+r)>>1;
    if (L<=m) update(L,R,val,lson);
    if (R>=m+1) update(L,R,val,rson);
    pushUP(l,r,rt);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	while (~scanf("%d",&n))
	{
	    for ( int i = 1 ; i<= n ; i++)
	    {
		double x1,y1,x2,y2;
		scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
		X[i] = x1;
		X[i+n] = x2;
		a[i]=Seg(x1,x2,y1,1);
		a[i+n]=Seg(x1,x2,y2,-1);
	    }

	    n=n<<1;
	    sort(X+1,X+n+1);
	    sort(a+1,a+n+1);
	    int m = unique(X+1,X+n+1)-X-1;

	    ms(tree,0);
	    double ans = 0 ;
	    for ( int i = 1 ; i < n ; i++)
	    {
		int l = lower_bound(X+1,X+1+m,a[i].l)-X;
		int r = lower_bound(X+1,X+1+m,a[i].r)-X;
		update(l,r-1,a[i].d,1,n,1);
		ans+=tree[1].len;
		cout<<"ans1:"<<ans;
		double H = a[i+1].h - a[i].h;
		ans+=2*H;
		cout<<"  ans2:"<<ans<<endl;
	    }
	    printf("%.0f\n",ans);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
