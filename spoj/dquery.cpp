/* ***********************************************
Author :111qqz
Created Time :Fri 16 Sep 2016 11:34:32 PM CST
File Name :code/spoj/dquery.cpp
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
const int N=3E4+7;
const int M=2E5+7;
int n,Q;
int a[N];
int tree[N<<2];
map<int,int>mp;
struct node
{
    int l,r;
    int id;
    bool operator < (node b)const
    {
	if (r==b.r) return l<b.l;
	return r<b.r;
    }
}q[M];


void PushUp( int rt)
{
    tree[rt] = tree[rt<<1] + tree[rt<<1|1];
}
void update( int p,int sc,int l,int r ,int rt)
{
    if (l==r)
    {
	tree[rt]+=sc;
	return;
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
    int ret = 0 ;
    if (L<=m)  ret += query(L,R,lson);
    if (R>=m+1) ret+=query(L,R,rson);
    return ret;
}
int ans[M];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n;
	for ( int i = 1 ; i <= n ; i++) scanf("%d",&a[i]);
	cin>>Q;
	for ( int i = 1 ; i <= Q ; i++) scanf("%d %d",&q[i].l,&q[i].r),q[i].id = i ;
	sort(q+1,q+Q+1);

	int cur = 1;
	for ( int i = 1 ; i <= Q ; i++)
	{
	    for ( ; cur <= q[i].r ; cur++)
	    {
		if (mp[a[cur]]) update(mp[a[cur]],-1,1,n,1);
		mp[a[cur]] = cur;
		update(mp[a[cur]],1,1,n,1);
	    }
	    ans[q[i].id] = query(q[i].l,q[i].r,1,n,1);
	}
	for ( int i = 1 ; i <= Q ; i++) printf("%d\n",ans[i]);

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
