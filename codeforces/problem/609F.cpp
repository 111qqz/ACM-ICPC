/* ***********************************************
Author :111qqz
Created Time :Wed 21 Sep 2016 12:30:16 AM CST
File Name :code/cf/problem/609F.cpp
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
#define pi pair < LL ,LL >
#define MP make_pair
using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int N=2E5+7;
struct node
{
    LL x,t;
    LL sum;
    int id;
    bool operator < (node b)const
    {
	return x<b.x;
    }
}frog[N];
pi mos[N];
int n,m;
int cnt;
LL X[N];
LL tree[N<<2];
void PushUp(int rt)
{
    tree[rt] = max(tree[rt<<1],tree[rt<<1|1]);
}
void build( int l,int r,int rt)
{
    if (l==r)
    {
	tree[rt] = frog[l].sum;
	return ;
    }
    int m = (l+r)>>1;
    build(lson);
    build(rson);
    PushUp(rt);
}
void update( int p,LL sc,int l,int r,int rt)
{
    if (l==r)
    {
	tree[rt] += sc;
	return;
    }
    int m = (l+r)>>1;
    if (p<=m) update(p,sc,lson);
    else update(p,sc,rson);
    PushUp(rt);
}
LL query(int L,int R,int l,int r,int rt)
{
    if (L<=l&&r<=R) return tree[rt];
    int m = (l+r)>>1;
    LL ret = -1;
    if (L<=m) ret = max(ret,query(L,R,lson));
    if (R>=m+1) ret = max(ret,query(L,R,rson));
    return ret;
}
int bin( int k)
{
    int l = 1;
    int r = upper_bound(X+1,X+cnt+1,k)-X;//r为X中第一个大于k的下标。
    r--;//此时r为最后一个小于等于k的下标。
    if (r==0||query(1,r,1,n,1)<k) return -1; //因为1..x的最大值是在x递增的意义夏单调的，所以可以二分。
    int res = -1;
    while (l<=r)
    {
	int mid = (l+r)/2;
	if (query(1,mid,1,n,1)>=k) r = mid-1,res = mid;
	else l = mid+1;
    }
    return res;
}
pi ans[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	scanf("%d%d",&n,&m);
	cnt = 0 ;
	for ( int i = 1 ;i  <= n ; i++)
	{
	    scanf("%lld%lld",&frog[i].x,&frog[i].t);
	    frog[i].id = i ;
	}
	sort(frog+1,frog+n+1);
	for ( int i = 1 ; i <= n ; i++) frog[i].sum = frog[i].x + frog[i].t,X[++cnt] = frog[i].x;
	build(1,n,1);
	multiset<pi>mse;
	for ( int i = 1 ; i <= m ; i++) scanf("%lld%lld",&mos[i].fst,&mos[i].sec);
	for ( int i = 1 ; i <= m ; i++)
	{
	    int pos = bin(mos[i].fst); //找到一个最左边的i，满足X[i]<=mos[i].fst并且x[i]+t[i]>=mos[i].fst
	    if (pos!=-1)
	    {
		ans[frog[pos].id].fst++;
		frog[pos].t+=mos[i].sec;
		update(pos,mos[i].sec,1,n,1);
		frog[pos].sum = frog[pos].t + frog[pos].x;
		while (!mse.empty())
		{
		    auto it = mse.lower_bound(make_pair(frog[pos].x,0)); //返回第一个大于等于当前青蛙位置的蚊子
		    if (it==mse.end()||frog[pos].sum< it->fst) break; //没有这样的蚊子或者当前青蛙没办法吃到所有没被吃的蚊子中最左边（最容易被吃到）的
		    //不然就一直吃。。。把之前没被吃的尽量吃。。。直到某个吃不到。。。
		    frog[pos].t += it->sec;
		    frog[pos].sum += it->sec;
		    ans[frog[pos].id].fst++;
		    update(pos,it->sec,1,n,1);
		    mse.erase(it);//论multiset的正确erase方法
		}
	    }else mse.insert(mos[i]);
	}
	for ( int i = 1 ; i <= n ; i++) ans[frog[i].id].sec = frog[i].t;
	for ( int i = 1; i <= n ; i++) printf("%lld %lld\n",ans[i].fst,ans[i].sec);
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
