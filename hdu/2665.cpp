/* ***********************************************
Author :111qqz
Created Time :2017年10月16日 星期一 21时51分55秒
File Name :2104.cpp
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
const int N=1E5+7;
int a[N],H[N];
int cnt;
int Hash( int x){ return lower_bound(H,H+cnt,x)-H;}
int n,m;
int tot;//线段树的总数。
int root[N];//每个元素对应的根节点
struct PTree
{
    int sum,left,right;
}tree[N*30];
inline int add_node( int _sum,int _left,int _right)
{
    int idx = ++tot;
    tree[idx].sum = _sum;
    tree[idx].left = _left;
    tree[idx].right = _right;
    return idx;
}
void Insert( int &root,int pre_rt,int pos,int l,int r)
{
    root = add_node(tree[pre_rt].sum + 1,tree[pre_rt].left,tree[pre_rt].right);
    //printf("l:%d r %d root:%d\n",l,r,root);
    if (l==r) return;
    int mid = (l+r)>>1;
    if (pos<=mid)
	Insert(tree[root].left,tree[pre_rt].left,pos,l,mid);
    else
	Insert(tree[root].right,tree[pre_rt].right,pos,mid+1,r);
}
int Query( int L,int R,int l,int r,int k)//区间第k大
{
    if (l==r) return l;
    int mid = (l+r)>>1;
    int sum = tree[tree[R].left].sum - tree[tree[L].left].sum;
    //sum表示 左区间的元素个数
    if (k<=sum)
	return Query(tree[L].left,tree[R].left,l,mid,k);
    else return Query(tree[L].right,tree[R].right,mid+1,r,k-sum);
}



int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	while (T--){
	tot = 0 ;
	scanf("%d%d",&n,&m);
	for ( int i = 1 ; i <= n ; i++) scanf("%d",a+i),H[i] = a[i];
	root[0] = 0;
	sort(H+1,H+n+1);
	cnt = unique(H+1,H+n+1)-(H+1);
	for ( int i = 1; i <= n ; i++)
	{
	    int pos = Hash(a[i]);
	    //printf("pos:%d\n",pos);
	    Insert(root[i],root[i-1],pos,1,cnt);
	    //cout<<"i"<<i<<endl;
	}
	while (m--)
	{
	    int l,r,k;
	    scanf("%d %d %d",&l,&r,&k);
	    int pos = Query(root[l-1],root[r],1,cnt,k);
	    printf("%d\n",H[pos]);
	}
	}


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
