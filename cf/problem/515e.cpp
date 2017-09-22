/* ***********************************************
Author :111qqz
Created Time :Mon 19 Sep 2016 04:35:20 PM CST
File Name :code/cf/problem/515e.cpp
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
#define  INF (~0ull>>1)
using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int N=2E5+7;
int n,m;
LL d[N],h[N];
struct node
{
    LL mx; //mx保存的是不相同区间的lx+mx的最大值。目的是避免u==v的情况。注意体会这种区间合并。
    LL lx;
    LL rx;
}tree[N<<2];
void PushUp(int rt)
{
    tree[rt].lx = max(tree[rt<<1].lx,tree[rt<<1|1].lx);
    tree[rt].rx = max(tree[rt<<1].rx,tree[rt<<1|1].rx);
    tree[rt].mx = max(tree[rt<<1].lx+tree[rt<<1|1].rx,max(tree[rt<<1].mx,tree[rt<<1|1].mx));
}
void build( int l,int r,int rt)
{
    if (l==r)
    {
	tree[rt].mx = 0;
	tree[rt].lx = 2*h[l]-d[l-1]; //注意到lx可能为负。。。因为初始的时候要为负无穷。。。。并且负无穷要足够小。。。
	tree[rt].rx = 2*h[l]+d[l-1];
	return;
    }
    int m =  (l+r)>>1;
    build(lson);
    build(rson);
    PushUp(rt);
}
node query(int L,int R,int l,int r,int rt)
{
    if (L<=l&&r<=R) return tree[rt];
    int m = (l+r)>>1;
    node null;
    null.mx = 0 ;
    null.lx = -INF;
    null.rx = -INF;
    node resl,resr,res;
    resl=resr=res=null;
    if (L<=m) resl = query(L,R,lson);
    if (R>=m+1) resr = query(L,R,rson);
    if (resl.lx==-INF) //只有一半有结果，那么直接更新这一半的结果到res
    {
	res.lx = max(res.lx,resr.lx);
	res.rx = max(res.rx,resr.rx);
	res.mx = max(res.mx,resr.mx);
    }else if (resr.lx==-INF)
    {
	res.lx = max(res.lx,resl.lx);
	res.rx = max(res.rx,resl.rx);
	res.mx = max(res.mx,resl.mx);
    }
    else //两个区间都有结果。。要合并区间。。。。类似于pushup操作
    {
	res.mx = max(resl.mx,resr.mx);
	res.lx = max(resl.lx,resr.lx);
	res.rx = max(resl.rx,resr.rx);
	res.mx = max(resl.lx+resr.rx,res.mx);
    }
    return res;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
    	ios::sync_with_stdio(false);
	cin>>n>>m;
	for ( int i = 1 ; i <= n ; i++) cin>>d[i],d[i+n] = d[i];
	for ( int i = 1 ; i <= n ; i++) cin>>h[i],h[i+n] = h[i];
	for ( int i = 1 ; i <= 2*n ; i++) d[i] = d[i-1] + d[i]; //处理成前缀和.
	build(1,n<<1,1);
	while (m--)
	{
	    int x,y;
	    cin>>x>>y;
	    node ans;
	    if (x<=y)
		ans = query(y+1,x+n-1,1,n<<1,1);
	    else ans = query(y+1,x-1,1,n<<1,1);
	    cout<<ans.mx<<endl;
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
