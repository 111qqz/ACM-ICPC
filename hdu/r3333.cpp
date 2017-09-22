/* ***********************************************
Author :111qqz
Created Time :Fri 16 Sep 2016 08:26:34 PM CST
File Name :code/hdu/r3333.cpp
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
const int M=1E5+7;
LL tree[N<<2];
LL a[N];
int n,m;
struct node
{
    int l,r;
    int id;
    bool operator < (node b)
    {
	if (r==b.r) return l<b.l;
	return r<b.r;
    }
}q[M];//把M写成N


void PushUp( int rt)
{
    tree[rt] = tree[rt<<1] + tree[rt<<1|1];
}
void update( int p,LL sc,int l,int r,int rt)
{
    if (l==r)
    {
	tree[rt]+=sc;
	return;
    }
    int m = (l+r)>>1;
    if (p<=m)update(p,sc,lson);
    else update(p,sc,rson);
    PushUp(rt);
}

LL query(int L,int R,int l,int r,int rt)
{
    if (L<=l&&r<=R) return tree[rt];
    int m = (l+r)>>1;
    LL ret = 0 ;
    if (L<=m)  ret+= query(L,R,lson);
    if (R>=m+1) ret+=query(L,R,rson);
    return ret;
}
map<LL,int>mp;
LL ans[M]; //把M写成N
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	int T;
	scanf("%d",&T);
	while (T--)
	{
	    ms(tree,0);
	    ms(ans,0);
	    mp.clear();
	    scanf("%d",&n);
	    for ( int i = 1; i  <= n ;  i++) scanf("%lld",a+i);
	    scanf("%d",&m);
	    for ( int i = 1 ; i <= m ; i++)
	    {
		int a,b;
		scanf("%d%d",&a,&b);
		q[i].l = a;
		q[i].r = b;
		q[i].id = i ;
	    }

	    sort(q+1,q+m+1);

	    int l = 1;
	    for ( int i = 1 ; i <= m ; i++)
	    {
		for ( ; l <= q[i].r ; l++)
		{
		    if (mp[a[l]]) update(mp[a[l]],-a[l],1,n,1);
		    mp[a[l]] = l ;
		    update(mp[a[l]],a[l],1,n,1);
		}
		
		ans[q[i].id] = query(q[i].l,q[i].r,1,n,1);
	    }

	    for ( int i = 1 ; i <= m ; i++) printf("%lld\n",ans[i]);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
