/* ***********************************************
Author :111qqz
Created Time :2017年09月27日 星期三 19时10分37秒
File Name :1255.cpp
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
    double l,r,h;
    int d;
    Seg(){}
    Seg(double l,double r,double h,int d):l(l),r(r),h(h),d(d){}
    bool operator < (const Seg & rhs)const
    {
	return h<rhs.h;
    }
}a[N];
struct Tree
{
    double one,two; //分别是被覆盖一次以上的长度和被覆盖两次以上的长度。
    int cnt;
}tree[N<<2];
double X[N];
void PushUp( int l,int r,int rt)
{
    //整段区间被完全覆盖2次，长度可以直接得到。
    if (tree[rt].cnt>=2) tree[rt].one = tree[rt].two = X[r+1]-X[l];
    else if (tree[rt].cnt==1)  
    {
	tree[rt].one = X[r+1]-X[l];
	if (l==r) tree[rt].two = 0;
	else tree[rt].two = tree[rt<<1].one + tree[rt<<1|1].one;
	//父节点本身覆盖了一次，这样只需要左右子节点再至少覆盖一次即可。
	//此处更新是本题唯一的难点。
    }
    else
    {
	if (l==r) tree[rt].one =  tree[rt].two = 0;
	else 
	{
	    tree[rt].one = tree[rt<<1].one + tree[rt<<1|1].one;
	    tree[rt].two = tree[rt<<1].two + tree[rt<<1|1].two;
	}
    }
}
void update(int L,int R,int val,int l,int r,int rt)
{
    if (L<=l && r<=R)
    {
	tree[rt].cnt+=val;
	PushUp(l,r,rt);
	return ;
    }
    int m = (l+r)>>1;
    if (L<=m) update(L,R,val,lson);
    if (R>=m+1) update(L,R,val,rson);
    PushUp(l,r,rt);
}

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	int T;
	scanf("%d",&T);
	while (T--)
	{
    	    scanf("%d",&n);    
	    for ( int i = 1 ; i <= n ; i++)
	    {
		double x1,y1,x2,y2;
		//给的坐标实际是左下角和右上角，而不是“左上角和右下角”，题目说错了。
		scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
		X[i] = x1;
		X[i+n]=x2;
		a[i]=Seg(x1,x2,y1,1);
		a[i+n]=Seg(x1,x2,y2,-1);
	    }
	    n<<=1;
	    sort(X+1,X+n+1);
	    sort(a+1,a+n+1);
	    int m = unique(X+1,X+1+n)-X-1;
	    ms(tree,0);
	    double ans=0;
	    for (  int i = 1 ; i < n ; i++)
	    {
		int l = lower_bound(X+1,X+m+1,a[i].l)-X;
		int r = lower_bound(X+1,X+m+1,a[i].r)-X;
	//	cout<<"l:"<<l<<" r:"<<r<<endl;
		update(l,r-1,a[i].d,1,m,1);
		ans+=tree[1].two * (a[i+1].h-a[i].h);
	//	cout<<"len:"<<tree[1].two<<" h:"<<a[i+1].h-a[i].h<<" ans:"<<ans<<endl;
	    }
	    //是四舍五入保留2位小数，题目没说清楚。
	    ans = round(ans*100)*0.01;
	    printf("%.2f\n",ans);
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
