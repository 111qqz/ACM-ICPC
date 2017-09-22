/* ***********************************************
Author :111qqz
Created Time :2016年11月27日 星期日 14时45分27秒
File Name :code/hdu/5367.cpp
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
#define ms(a,x) memset(a,x,sizeof(a))
typedef long long LL;
#define pi pair < int ,int >
#define MP make_pair
using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int INF = 0x3f3f3f3f;
const int N=5E4+7;
int cur,root;
int n,q,nnn;
struct Tree
{
    int sum;//高山脉的长度和
    int child[2];//左右孩子的编号
    int rsum,lsum;//从左端点，右端点其高度相同的连续的山有多少个。
    int lh,rh;//左边连续，右边连续的山的高度。
    int llh,rrh;//左边第一个不连续，右边第一个不连续的山的高度。
    int lazy;
    void init(int l,int r)
    {
	sum = child[0] = child[1] = lh = rh = llh = rrh = lazy = 0;
	lsum = rsum = r-l+1;
    }
};
struct SegmentTree{
    Tree tree[N*60];
    void check(int &rt,int l,int r)
    {
	//cout<<"rt:"<<rt<<" l:"<<l<<" r:"<<r<<endl;
	if (rt) return;
	rt=++cur;
	tree[rt].init(l,r);
	if (l==1) tree[rt].llh = INF;
	if (r==n) tree[rt].rrh = INF;//最左边和最右边的山一定不是“high mountain line"的一部分/
    }
    void add( int rt,int val)
    {
	tree[rt].lazy +=val;
	tree[rt].rrh +=val;
	tree[rt].llh +=val;
	tree[rt].lh +=val;
	tree[rt].rh +=val;
    }
    void PushDown( int rt,int l,int r)
    {
	if (tree[rt].lazy)
	{
	    int m = (l+r)>>1;
	    check(tree[rt].child[0],l,m);
	    check(tree[rt].child[1],m+1,r);
	    add(tree[rt].child[0],tree[rt].lazy);
	    add(tree[rt].child[1],tree[rt].lazy);
	    tree[rt].lazy = 0;
	}
    }
    void PushUp( int rt,int l,int r)
    {
	int m = (l+r)>>1;
	check(tree[rt].child[0],l,m);
	check(tree[rt].child[1],m+1,r);
	int lson = tree[rt].child[0];
	int rson = tree[rt].child[1];
	tree[rt].sum = tree[lson].sum + tree[rson].sum;

	tree[rt].lsum = tree[lson].lsum;
	tree[rt].rsum = tree[rson].rsum;
	tree[rt].lh = tree[lson].lh;
	tree[rt].rh = tree[rson].rh;
	tree[rt].llh = tree[lson].llh;
	tree[rt].rrh = tree[rson].rrh;
	//先继承先前区间的，肯定不会比该答案小
	if (tree[lson].rh==tree[rson].lh)
	{
	    if (tree[lson].rh>tree[lson].rrh&&tree[rson].lh>tree[rson].llh)
		tree[rt].sum += tree[lson].rsum + tree[rson].lsum;
	    if (tree[lson].rsum==m-l+1)
	    {
		tree[rt].lsum += tree[rson].lsum;
		tree[rt].llh = tree[rson].llh;
	    }
	    if (tree[rson].lsum == r-m)
	    {
		tree[rt].rsum += tree[lson].rsum;
		tree[rt].rrh = tree[lson].rrh;
	    }
	}else
	{
	    if (tree[lson].lsum == m-l+1) tree[rt].llh = tree[rson].lh;
	    if (tree[lson].rh>tree[rson].lh&&tree[lson].rh>tree[lson].rrh)
		tree[rt].sum +=tree[lson].rsum;
	    if (tree[rson].rsum== r-m) tree[rt].rrh = tree[lson].rh;
	    if (tree[rson].lh>tree[lson].rh&&tree[rson].lh>tree[rson].llh)
		tree[rt].sum += tree[rson].lsum;
	}


    }
    void update(int &rt,int l,int r,int L,int R,int x)
    {
//	printf("rt %d l %d r %d\n",rt,l,r);
	check(rt,l,r);
	if (L<=l&&r<=R)
	{
	    add(rt,x);
	    return;
	}
	PushDown(rt,l,r);
	int m = (l+r)>>1;
	if (L<=m) update(tree[rt].child[0],l,m,L,R,x);
	if (R>=m+1) update(tree[rt].child[1],m+1,r,L,R,x);
	PushUp(rt,l,r);
    }
}SegTree;
int main()
{
#ifndef  ONLINE_JUDGE 
    freopen("code/in.txt","r",stdin);
#endif
    while (~scanf("%d%d%*d",&n,&q))
    {
	cur = root = 0 ;
	int ans = 0 ;

	int l,r,val;
	for ( int i = 1; i  <= q ; i++)
	{
	    scanf("%d%d%d",&l,&r,&val);
	    l ^= ans;
	    r ^= ans;
	    val ^= ans;
	    if (l>r) swap(l,r);
	    SegTree.update(root,1,n,l,r,val);
	    ans = SegTree.tree[1].sum;
	    printf("%d\n",ans);

	}
    }
#ifndef ONLINE_JUDGE  
    fclose(stdin);
#endif
    return 0;
}
