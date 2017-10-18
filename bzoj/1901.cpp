/* ***********************************************
Author :111qqz
Created Time :2017年10月16日 星期一 23时50分14秒
File Name :1901.cpp
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
#define PB push_back
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
const int N = 2E5+7;
int n,m;
int a[N],H[N];
int root[N];
int cnt,p[2];
int num;
int prefix_l[100],prefix_r[100];

struct node
{
    int a,b,c;
    char opt[3];
}querys[N];
struct PTree
{
    int sum;
    int left,right;
}tree[N*30];
int Hash( int x){ return lower_bound(H+1,H+num+1,x)-H;}
inline int lowbit( int x) { return x&(-x);}
inline int add_node( int _sum,int _left,int _right)
{
    int idx = ++cnt;
    tree[idx].sum = _sum;
    tree[idx].left = _left;
    tree[idx].right = _right;
    return idx;
}
void build( int &root,int pre_rt,int pos,int l,int r)
{
    root = add_node(tree[pre_rt].sum+1,tree[pre_rt].left,tree[pre_rt].right);
    if (l==r) return;
    int mid = (l+r)>>1;
    if (pos<=mid)
	build(tree[root].left,tree[root].left,pos,l,mid);
    else
	build(tree[root].right,tree[root].right,pos,mid+1,r);
}
void Insert( int &root,int pos,int l,int r,int val)
{
    if (!root) root = add_node(0,0,0);
    tree[root].sum += val;
    if (l==r) return;
    int mid = (l+r)>>1;
    if (pos<=mid)
	Insert(tree[root].left,pos,l,mid,val);
    else
	Insert(tree[root].right,pos,mid+1,r,val);
}
int query(int l,int r,int k)
{
    if (l==r) return l;
    int mid = (l+r)>>1,sum=0;
    for ( int i = 0 ; i < p[0] ; i++)
	sum += tree[tree[prefix_r[i]].left].sum;
    for ( int i = 0 ; i < p[1] ; i++)
	sum -= tree[tree[prefix_l[i]].left].sum;
    if (k<=sum)
    {
	for (int i = 0 ; i < p[0] ; i++)
	    prefix_r[i] = tree[prefix_r[i]].left;
	for ( int i = 0 ; i < p[1] ; i++)
	    prefix_l[i] = tree[prefix_l[i]].left;
	return query(l,mid,k);
    }
    else
    {
	for ( int i = 0 ; i < p[0] ; i++)
	    prefix_r[i] = tree[prefix_r[i]].right;
	for ( int i = 0 ; i < p[1] ; i++)
	    prefix_l[i] = tree[prefix_l[i]].right;
	return query(mid+1,r,k-sum);
    }
}

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif 
	scanf("%d %d",&n,&m);
	int p_val = n;
	ms(root,0);
	for ( int i = 1 ; i <= n ; i++) scanf("%d",a+i),H[i] = a[i];
	cnt = 0;
	for ( int i = 0 ; i < m; i++) //读入所有操作是为了离散化
	{
	    scanf("%s %d %d",querys[i].opt,&querys[i].a,&querys[i].b);
	    if (querys[i].opt[0]=='Q') scanf("%d",&querys[i].c);
	    else H[++p_val] = querys[i].b;
	}
	sort(H+1,H+p_val+1);
	num = unique(H+1,H+p_val+1)-(H+1);
	for ( int i = 1 ; i <= n ; i++)
	{
	    a[i] = Hash(a[i]);
	}
//	for ( int i = 1 ; i <= n ; i++) printf("a[%d]=%d\n",i,a[i]);
	for ( int i = 1 ; i <= n ; i++)
	{
	    build(root[i+n],root[(i-1)+n],a[i],1,num);
	}
	for ( int i = 0 ; i < m ; i++)
	{
	    if (querys[i].opt[0]=='Q')
	    {
		p[0] = p[1] = 1;
		prefix_r[0] = root[querys[i].b + n];
		prefix_l[0] = root[querys[i].a-1==0?0:querys[i].a-1+n];
		for ( int arr = querys[i].b; arr ; arr-=lowbit(arr))
		    prefix_r[p[0]++] = root[arr];
		for ( int arr = querys[i].a-1 ; arr ; arr-=lowbit(arr))
		    prefix_l[p[1]++] = root[arr];
		int id = query(1,num,querys[i].c);
		printf("%d\n",H[id]);
	    }
	    else
	    {
		for ( int j = querys[i].a ; j <= n ; j+=lowbit(j))
		    Insert(root[j],a[querys[i].a],1,num,-1);
		a[querys[i].a] = Hash(querys[i].b);
		for ( int j = querys[i].a ; j <= n ; j+=lowbit(j))
		    Insert(root[j],a[querys[i].a],1,num,1);
	    }
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
