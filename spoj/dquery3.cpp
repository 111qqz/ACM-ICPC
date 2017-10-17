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
map<int,int>mp;
int cnt;
struct node
{
    int l,r;
    int id;
}q[M];
struct Ptree
{
    int sum;
    int left,right;
}tree[N*30];
inline int add_node(int _sum,int _left,int _right)
{
    int idx = ++cnt;
    tree[idx].sum = _sum;
    tree[idx].left = _left;
    tree[idx].right = _right;
    return idx;
}
void Insert(int &root,int pre_rt,int pos,int val,int l,int r)
{
    root = add_node(tree[pre_rt].sum + val,tree[pre_rt].left,tree[pre_rt].right);
    if (l==r) return ;
    int mid = (l+r)>>1;
    if (pos<=mid) update(tree[root].left,tree[pre_rt].left,pos,val,l,mid);
    else update(tree[root].right,tree[pre_rt].right,pos,val,mid+1,r);
}
int query(int pos,int l,int r,int rt)
{
    if (l==r) return tree[rt].sum;
    int mid = (l+r)>>1;
    if (pos<=mid) return query(tree[rt].left,l,mid,pos);
    else tree[tree[rt].left].sum + query(tree[rt].right,mid+1,r,pos);
}


int ans[M];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	cnt = 0 ;
	cin>>n;
	for ( int i = 1 ; i <= n ; i++) scanf("%d",&a[i]);
	cin>>Q;
	for ( int i = 1 ; i <= Q ; i++) scanf("%d %d",&q[i].l,&q[i].r),q[i].id = i ;
	
	mp.clear();
	for ( int i = n ; i >= 1 ; i--)
	{
	    if (mp.find(a[i])==mp.end())
	    {
		update(root[i+1],root[i],1,n,i,1)
	for ( int i = 1 ; i <= Q ; i++) printf("%d\n",ans[i]);

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
