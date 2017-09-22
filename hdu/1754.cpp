/* ***********************************************
Author :111qqz
Created Time :2016年08月18日 星期四 18时40分24秒
File Name :code/hdu/1754.cpp
************************************************ */
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <deque>
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
const int N=2E5+7;
int a[N],n,m;
int _max( int x,int y)
{
    if (x==-1||y==-1)
	return x==-1?y:x;
    return a[x]>a[y]?x:y;
}
struct Tree
{
    Tree *pl,*pr;
    int l,r,mx;
     void update()
    {
	mx = _max(pl->mx,pr->mx);
    }
    Tree(int l,int r) :
	    l(l),r(r)
	    {
		if ( l + 1 == r)
		{
		    mx = l ;
		    return ;
		}
		pl = new Tree(l,(l+r)>>1);
		pr = new Tree((l+r)>>1,r);
		update();
	    }
    void change(int p,int x)
    {
	if (p < l|| p>=r) return;
	if (l+1==r)
	{
	    a[l] = x;
	    return ;
	}
	pl->change(p,x);
	pr->change(p,x);
	update();
    }
    int queryMax(int L,int R)
    {
	if (L <= l && r <= R) return mx;
	if (L>=r || l >=R)
	    return -1;
	return _max(pl->queryMax(L,R),pr->queryMax(L,R));
    }
}*rt;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
    while (~scanf("%d%d",&n,&m))
    {
	for ( int i = 0 ; i < n ; i++) scanf("%d",a+i);
	rt = new Tree(0,n);
	while (m--)
	{
	    char opt[3];
	    int x,y;
	    scanf("%s %d %d",opt,&x,&y);
	    x--;
	    if (opt[0]=='Q')
		printf("%d\n",a[rt->queryMax(x,y)]);
	    else rt->change(x,y);
	}
    }
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
