/* ***********************************************
Author :111qqz
Created Time :Sun 18 Sep 2016 08:30:02 PM CST
File Name :code/cf/problem/351D.cpp
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
int a[N],pre[N],lst[N];
int n,m;
int tree[N<<2];
int t[N];
int ans[N];
struct node
{
    int l,r;
    int id;
    bool operator < (node b)const
    {
	if (r==b.r) return l<b.l;
	return r<b.r;
    }
}q[N];
void PushUp(int rt){tree[rt] = tree[rt<<1] + tree[rt<<1|1];}
void update( int p,int sc,int l,int r,int rt)
{
    if (l==r)
    {
	tree[rt]+=sc;
	return ;
    }
    int m = (l+r)>>1;
    if (p<=m) update(p,sc,lson);
    else update(p,sc,rson);
    PushUp(rt);
}
int query(int L,int R,int l,int r,int rt)
{
    if (L<=l&&r<=R) return tree[rt];
    int m = (l+r)>>1;
    int ret = 0;
    if (L<=m) ret += query(L,R,lson);
    if (R>=m+1) ret +=query(L,R,rson);
    return ret;
}
int lowbit( int x)
{
    return x&(-x);
}
void update2( int x,int delta)
{
    for ( int i = x; i < N ; i+=lowbit(i)) t[i]+=delta;
}
int Sum( int x)
{
    int res = 0 ;
    for ( int i = x; i >=1 ; i-=lowbit(i)) res+=t[i];
    return res;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n;
	ms(tree,0);
	ms(t,0);
	for ( int i = 1; i  <= n ; i++)
	{
	    //cin>>a[i];
	    scanf("%d",a+i);
	    pre[i] = lst[a[i]];//pre[i]表示a[i]上次出现的位置。
	    lst[a[i]] =  i;
	}
	cin>>m;
	for ( int i = 1; i <= m ; i++)
	{
	    scanf("%d %d",&q[i].l,&q[i].r);
	    //cin>>q[i].l>>q[i].r;
	    q[i].id = i ;
	}
	sort(q+1,q+m+1);
	int cur = 1;
	for ( int i = 1 ; i <= m ; i ++)
	{
	    for ( ; cur <= q[i].r ; cur++)
	    {
		if (pre[cur]) update(pre[cur],-1,1,n,1);
		update(cur,1,1,n,1);
		update2(pre[cur]+1,1);
		update2(cur+1,-1); //+1是bit的下标问题。。从0开始会死循环。。。
		if (pre[cur])
		{
		    int k = pre[cur];
		    if (!pre[k]||k-pre[k]==cur-k);
		    else
		    {
			int len = k - pre[k];
			k = pre[k];
			for ( ;k;)
			{
			    int A = pre[k];
			    update2(A+1,-1);
			    update2(k+1,1);
			    if (!A||k-A!=len) break;
			    k = A;
			}
		    }
		}
	    }
	    ans[q[i].id] = query(q[i].l,q[i].r,1,n,1) + (Sum(q[i].l)==0);
	}
	for ( int i = 1; i  <= m ; i++) cout<<ans[i]<<endl;
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
