/* ***********************************************
Author :111qqz
Created Time :2015年12月17日 星期四 15时04分52秒
File Name :code/hdu/2785.cpp
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
const int N=2E5+7;
int h,w,n;

struct SegTree   //将每个横格能放置的最大长度看做一个序列，建树。
{
    int mx; 
}tree[4*N];

void PushUp( int rt)
{
    tree[rt].mx = max(tree[rt<<1].mx,tree[rt<<1|1].mx);
}
void build ( int l,int r,int rt)
{
    if (l==r)
    {
	tree[rt].mx = w;
	return ;
    }
    int m = (l+r)>>1;
    build (lson);
    build (rson);
    PushUp(rt);

}

int query( int x,int l,int r,int rt)
{
    if (l==r)
    {
	tree[rt].mx-=x;  //将长度为x的改点放在第l个横格里。
	return l;
    }
    int m = (l+r)>>1;
    int res;
    if (tree[rt<<1].mx>=x)  //先搜左子树，可以保证topmost.
    {
	res=query(x,lson);
    }
    else
    {
	res=query(x,rson);
    }
    PushUp(rt);
    return res;
}




int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (~scanf("%d %d %d",&h,&w,&n))
	{
	    if (h>n) h = n ;  //不用离散化，这样就可以。
	    build(1,h,1);
	    while (n--)
	    {
		int x;
		scanf("%d",&x);
		if (x>tree[1].mx)
		{
		    puts("-1");
		}
		else
		{
		    printf("%d\n",query(x,1,h,1));
		}
	    }
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
