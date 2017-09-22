/* ***********************************************
Author :111qqz
Created Time :Fri 16 Sep 2016 05:13:38 PM CST
File Name :code/cf/problem/338E.cpp
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
const int N=150005;
int n,len,h;
int a[N],b[N],f[N];
struct Tree
{
    int mn;//最小前缀和
    int sum;//区间和
}tree[N<<2];
void PushUp( int rt)
{
    tree[rt].sum = tree[rt<<1].sum + tree[rt<<1|1].sum;
    tree[rt].mn = min(tree[rt<<1].mn,tree[rt<<1].sum+tree[rt<<1|1].mn);
}
void build( int l,int r,int rt)
{
    if (l==r)
    {
	if (l<=len)
	tree[rt].sum = tree[rt].mn = -1;
	return;
    }
    int m = (l+r)>>1;
    build(lson);
    build(rson);
    PushUp(rt);
}
void update( int p,int sc,int l,int r,int rt)
{
    if (l==r)
    {
	tree[rt].sum += sc;
	tree[rt].mn +=sc;
	return;
    }
    int m = (l+r)>>1;
    if (p<=m) update(p,sc,lson);
    else update(p,sc,rson);
    PushUp(rt);
}
int bin( int x)
{
    int l = 1;
    int r = len;
    int res = len+1; //无穷。
    while (l<=r)
    {
	int mid = (l+r)>>1;
	if (b[mid]+x>=h)
	{
	    r = mid-1;
	    res = mid;
	}
	else
	{
	    l = mid+1;
	}
    }
    return res;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	ios::sync_with_stdio(false);
	ms(tree,0);
	cin>>n>>len>>h;
	int siz = len+1;
	for ( int i = 1 ;i  <= len ; i++) cin>>b[i];
	sort(b+1,b+len+1);
	for ( int i = 1 ; i <= n ; i++)
	{
	    int x;
	    cin>>x;
	    a[i] = bin(x);
	}
	build(1,siz,1);
	for ( int i = 1 ; i < len ; i++) update(a[i],1,1,siz,1);
	int ans = 0 ;
	for ( int i = len ; i <= n ; i++)
	{
	    update(a[i],1,1,siz,1);
	    if (tree[1].mn==0) ans++;
	    update(a[i-len+1],-1,1,siz,1);
	}
	cout<<ans<<endl;
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
