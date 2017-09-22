/* ***********************************************
Author :111qqz
Created Time :Wed 07 Sep 2016 02:13:55 AM CST
File Name :code/cf/problem/356A.cpp
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
const int N=3E5+7;
int n,m;
struct node
{
    int l,r,x;
}q[N];
int lazy[N<<2];
void PushDown( int rt)
{
    if (lazy[rt])
	lazy[rt<<1]=lazy[rt<<1|1]=lazy[rt];
    lazy[rt] = 0;
}
void update(int L,int R,int sc,int l,int r,int rt)
{
    if (L<=l&&r<=R)
    {
	lazy[rt] = sc;
	return;
    }
    PushDown(rt);
    int m = (l+r)>>1;
    if (L<=m) update(L,R,sc,lson);
    if (R>=m+1) update(L,R,sc,rson);

}
int query(int p,int l,int r,int rt)
{
    if (l==r) return lazy[rt];
    PushDown(rt);
    int m = (l+r)>>1;
    if (p<=m) query(p,lson);
    else query(p,rson);
}

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for ( int i = 1 ; i <= m ; i++) cin>>q[i].l>>q[i].r>>q[i].x;
	ms(lazy,0);

	for ( int i = m ; i >= 1 ; i--)
	{
	    if (q[i].x>q[i].l) update(q[i].l,q[i].x-1,q[i].x,1,n,1);
	    if (q[i].x<q[i].r) update(q[i].x+1,q[i].r,q[i].x,1,n,1);
	}
	for ( int i = 1 ; i <= n ; i++) cout<<query(i,1,n,1)<<" ";

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
