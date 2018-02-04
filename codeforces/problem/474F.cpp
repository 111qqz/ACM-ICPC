/* ***********************************************
Author :111qqz
Created Time :Mon 05 Sep 2016 08:37:57 PM CST
File Name :code/cf/problem/474F.cpp
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
int n;
pi a[N];
int tree[N<<2];
int gcd( int a,int b)
{
    if (a%b==0) return b;
    return gcd(b,a%b);
}
void PushUp( int rt)
{
    tree[rt] = gcd(tree[rt<<1],tree[rt<<1|1]);
}
void build(int l,int r,int rt)
{
    if (l==r)
    {
	tree[rt] = a[l].fst;
	return;
    }
    int m = (l+r)>>1;
    build(lson);
    build(rson);
    PushUp(rt);
}
int query(int L,int R,int l,int r,int rt)
{
    if (L<=l&&r<=R) return tree[rt];
    int m = (l+r)>>1;
    int ret=-1;
    if (L<=m)
    {
	ret = query(L,R,lson);
    }
    if (R>=m+1)
    {
	if (ret==-1) ret = query(L,R,rson);
	else ret = gcd(ret,query(L,R,rson));
    }
    return ret;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n;
	for ( int i = 1 ; i <= n ; i++)
	{
	    int x;
	    scanf("%d",&x);
	    a[i]=make_pair(x,i);
	}
	build(1,n,1);
	sort(a+1,a+n+1);
	int q;
	cin>>q;
	while (q--)
	{
	    int x,y;
	    scanf("%d%d",&x,&y);
	    int GCD = query(x,y,1,n,1);
	    int upper = upper_bound(a+1,a+n+1,make_pair(GCD,y))-(a+1);
	    int lower = lower_bound(a+1,a+n+1,make_pair(GCD,x))-(a+1);
	    int cnt = upper-lower;
	    printf("%d\n",y-x+1-cnt);
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
