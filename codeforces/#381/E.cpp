/* ***********************************************
Author :111qqz
Created Time :2016年11月27日 星期日 22时16分44秒
File Name :code/cf/#381/E.cpp
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
const int N=3E5+7;
int a[N];
int n,m;
struct Tree
{
    LL lm,rm;//左右端点值。
    int ans,len,upL,upR,downL,downR,maxL,maxR;
    /* 分别为
     * ans:区间最优解
     * len:区间长度
     * upL,downL,maxL：包含左端点的递增，递减，山型的长度
     * upR,downR,maxR: 包含右端点的递增，递减，山型的长度
     */
    Tree()
    {
	ans = len = upL = upR = downL = downR = maxL = maxR = lm = rm = 0;
    }
    Tree( int x)
    {
	ans = len = upL = upR = downL = downR = maxL = maxR = 1;
	lm = rm = x;
    }
};

Tree operator + ( Tree x,Tree y) //x为左子树所表示的区间，y为右子树所表示的区间
{
    Tree res;
    if (x.rm>y.lm)
    {
	res.ans = max(x.ans,y.ans);
	res.len = x.len + y.len;//区间长度这个变量也可以不放在线段树的域中，而是每次pushUp和pushdown的时候传参数进去。
	res.upL = x.upL;
	res.upR = y.upR;
	res.downL = x.downL +(x.downL==x.len) * (y.downL);//如果左区间全都递减，那么新区间包含左端点的递减长度可以把右区间包含左端点的递减长度包含进来。
	res.downR = y.downR + (y.downR==y.len) *(x.downR);//如果右区间全都递减，那么新区间包含右端点的递减长度可以把左区间包含右端点的递减长度包含进来。
	res.lm = x.lm;
	res.rm = y.rm; //更新端点值
	res.ans = max(res.ans,x.maxR+y.downL);//左区间包含右端点的山型可以再接一部分右区间包含左端点的下降序列，仍然是山型。
	res.maxL = x.maxL + (x.maxL == x.len) *(y.downL);//新区间包含左端点的山形在左区间都是山型的时候可以把右区间包含左端点的下降序列包含进来。
	res.maxR = y.maxR +(y.downL == y.len) *(x.maxR);//新区间包含右端点的山形 在右区间都是下降的时候可以把左区间包含右端点的山形序列包含进来。

    }
    else if (x.rm<y.lm)//同上，只是方向相反。
    {
	res.ans = max(x.ans,y.ans);
	res.len = x.len + y.len;
	res.upL = x.upL +(x.upL == x.len)*(y.upL);
	res.upR = y.upR +(y.upR == y.len)*(x.upR);
	res.downL = x.downL;
	res.downR = y.downR;
	res.lm = x.lm;
	res.rm = y.rm;
	res.ans = max(res.ans,x.upR + y.maxL);
	res.maxL = x.maxL + (x.upL==x.len)*(y.maxL);
	res.maxR = y.maxR + (y.maxR==y.len)*(x.upR);	
    }
    else //不要忘记相等的情况。
    {
	res.ans = max(x.ans,y.ans);
	res.len = x.len + y.len;
	res.upL = x.upL;
	res.upR = y.upR;
	res.downL = x.downL;
	res.downR = y.downR;
	res.lm = x.lm;
	res.rm = y.rm;
	res.maxL = x.maxL;
	res.maxR = y.maxR;

    }
    return res;
}
Tree tree[N<<2];
LL lazy[N<<2];
void doit(int rt,LL v)
{
    lazy[rt]+=v;
    tree[rt].lm += v;
    tree[rt].rm += v;
}
void PushDown(int rt)
{
    if (lazy[rt])
    {
	doit(rt<<1,lazy[rt]);
	doit(rt<<1|1,lazy[rt]);
	lazy[rt] = 0 ;
    }
}
void build( int l,int r,int rt)
{
  //  cout<<l<<" "<<r<<" "<<rt<<endl;
    if (l==r)
    {
	tree[rt] = Tree(a[l]);
	return ;	
    }
    
    int m = (l+r)>>1;
    build(lson);
    build(rson);
    tree[rt] = tree[rt<<1] + tree[rt<<1|1];
}

void update(int L,int R,int d,int l,int r,int rt)
{
    if (L<=l&&r<=R)
    {
	doit(rt,d);
	return;
    }
    PushDown(rt);
    int m = (l+r)>>1;
    if (L<=m)
    update(L,R,d,lson);
    if (R>=m+1)
    update(L,R,d,rson);
    tree[rt] = tree[rt<<1] + tree[rt<<1|1];
}

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n;
	for ( int i = 1;  i <= n ; i++) scanf("%d",&a[i]);
	cin>>m;
	build(1,n,1);
	while (m--)
	{
	    int l,r,d;
	    scanf("%d%d%d",&l,&r,&d);
	    update(l,r,d,1,n,1);
	    printf("%d\n",tree[1].ans);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
