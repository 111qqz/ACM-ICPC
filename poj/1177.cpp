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
}a[N],b[N];

struct Tree
{
     int cnt;
     double len; 
}tree[N<<2];
double X[N],Y[N];
void pushUP(int l,int r,int rt,double *X)
{
    if (tree[rt].cnt) tree[rt].len = X[r+1] - X[l];
    else
    if (l==r) tree[rt].len = 0 ;
    else tree[rt].len = tree[rt<<1].len + tree[rt<<1|1].len;
}
void update( int L,int R,int val,int l,int r,int rt,double *X)
{
    if (L<=l && r<=R)
    {
	tree[rt].cnt+=val;
//	cout<<"val:"<<val<<" rt:"<<rt<<" tree[rt].cnt:"<<tree[rt].cnt<<endl;
	pushUP(l,r,rt,X);
	return;
    }
    int m = (l+r)>>1;
    if (L<=m) update(L,R,val,lson,X);
    if (R>=m+1) update(L,R,val,rson,X);
    pushUP(l,r,rt,X);
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
		Y[i] = y1;
		Y[i+n] = y2;
		a[i]=Seg(x1,x2,y1,1);
		a[i+n]=Seg(x1,x2,y2,-1);
		b[i] = Seg(y1,y2,x1,1);
		b[i+n] = Seg(y1,y2,x2,-1); //从左到右扫描

	    }

	    n=n<<1;
	    double ans =  0;
	    double lstlen = 0 ;
	    sort(X+1,X+n+1);
	    sort(a+1,a+n+1);

	    int m = unique(X+1,X+n+1)-X-1;
	    ms(tree,0);
	    //求面积的时候不需要计算最后一条扫描线（因为答案是0),但是求周长的时候要计算）
	    for ( int i = 1 ; i <= n ; i++)
	    {
		int l = lower_bound(X+1,X+1+m,a[i].l)-X;
		int r = lower_bound(X+1,X+1+m,a[i].r)-X;
//		cout<<"l:"<<l<<" r:"<<r<<endl;
		update(l,r-1,a[i].d,1,m,1,X);
		ans += abs(tree[1].len-lstlen);
		lstlen = tree[1].len;
		//cout<<"lstlen:"<<lstlen<<endl;
	    }
	    //cout<<"ans:"<<ans<<endl;
	    
	    ms(tree,0);
	    sort(Y+1,Y+n+1);
	    sort(b+1,b+n+1);
	    m = unique(Y+1,Y+n+1)-Y-1;
	    lstlen = 0 ;
//	    cout<<"m:"<<m<<endl;
	    for ( int i = 1 ; i <= n ; i++)
	    {
		int l = lower_bound(Y+1,Y+1+m,b[i].l)-Y;
		int r = lower_bound(Y+1,Y+1+m,b[i].r)-Y;
	//	cout<<"l:"<<l<<" r:"<<r<<endl;
		update(l,r-1,b[i].d,1,m,1,Y);
		ans += abs(tree[1].len - lstlen);
		lstlen = tree[1].len;
	    }
	    printf("%.0f\n",ans);
	    
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
