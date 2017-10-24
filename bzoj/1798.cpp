/* ***********************************************
Author :111qqz
Created Time :2017年10月20日 星期五 13时49分35秒
File Name :1798.cpp
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
LL a[N];
struct Seg
{
    LL sum;
    LL lazy_add;
    LL lazy_mul;

}
tree[N<<2];
LL n,p;
int m;


void PushUp( int rt)
{
    tree[rt].sum = (tree[rt<<1].sum + tree[rt<<1|1].sum) %p;
}
void PushDown ( int rt,int l,int r) //可以把两个标记的传递写在一起，因为也是互相影响的
{
    if (tree[rt].lazy_mul==1&&tree[rt].lazy_add==0) return;
    tree[rt<<1].sum = (tree[rt<<1].sum * tree[rt].lazy_mul % p + tree[rt].lazy_add * (r-l+1) % p)%p;
    tree[rt<<1|1].sum = (tree[rt<<1|1].sum * tree[rt].lazy_mul % p + tree[rt].lazy_add *(r-l+1)%p)%p;

    tree[rt<<1].lazy_mul = (tree[rt<<1].lazy_mul * tree[rt].lazy_mul) % p;
    tree[rt<<1|1].lazy_mul = ( tree[rt<<1|1].lazy_mul * tree[rt].lazy_mul) % p;
    
    tree[rt<<1].lazy_add = (tree[rt<<1].lazy_add * tree[rt].lazy_mul % p+ tree[rt].lazy_add)%p;
    tree[rt<<1|1].lazy_add = ( tree[rt<<1|1].lazy_add * tree[rt].lazy_mul % p + tree[rt].lazy_add) % p;
    tree[rt].lazy_mul=1;
    tree[rt].lazy_add=0;
}
    
void build ( int l,int r,int rt)
{
//    printf("l:%d r:%d rt:%d\n",l,r,rt);
    if (l==r)
    {
	tree[rt].sum=a[l]%p;
	tree[rt].lazy_add = 0;
	tree[rt].lazy_mul = 1;
	return;
    }
    int m = (l+r)>>1;
    build (lson);
    build(rson);
    PushUp(rt);
}

void update_add( int L,int R,LL val,int l,int r,int rt)
{
    if (L<=l && r<=R)
    {
	tree[rt].lazy_add = (tree[rt].lazy_add + val)%p;
	tree[rt].sum = (tree[rt].sum + val * (r-l+1) % p) % p ;//需要注意的一点是，线段树知道一个区间顶点，对应的区间长度是不固定的。
	return;
    }
    PushDown(rt,l,r);
    int mid = (l+r)>>1;
    if (L<=mid) update_add(L,R,val,lson);
    if (R>=mid+1) update_add(L,R,val,rson);
    PushUp(rt);
}

void update_mul ( int L,int R,LL val,int l,int r,int rt)
{
    //puts("update_mul");
   // printf("l:%d r:%d rt:%d\n",l,r,rt);
    if ( L <= l && r<=R)
    {
	tree[rt].lazy_mul = (tree[rt].lazy_mul * val)%p;
	tree[rt].sum = (tree[rt].sum * val) % p;
	tree[rt].lazy_add = ( tree[rt].lazy_add * val) % p;
	return;
    }
    //PushDown(rt,l,r);
    int m = (l+r)>>1;
    if (L<=m) update_mul(L,R,val,lson);
    if (R>=m+1) update_mul(L,R,val,rson);
    PushUp(rt);
}
int step = 0;
LL query( int L,int R,int l,int r,int rt)
{
  //  printf("L:%d R:%d l:%d r:%d rt:%d",L,R,l,r,rt);
    if (L<=l && r<=R) 
    {
	printf("tree[%d].sum:%lld",rt,tree[rt].sum);
	return tree[rt].sum;
    }
    //PushDown(rt,l,r);
    int m = (l+r)>>1;
  //  printf("m :%d\n",m);
    LL res = 0;
    if (L<=m) res = (res + query(L,R,lson) )%p;
    cout<<"res:"<<res<<endl;
    if (R>=m+1) res = (res +query(L,R,rson) )%p;
    return res;
}
void pr()
{

		for ( int i = 1 ; i <= 10 ; i++) printf("tree[%d].sum %lld \n",i,tree[i].sum);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
//	freopen("./in.txt","r",stdin);
  #endif 


    scanf("%lld %lld",&n,&p);
    ms(tree,0);
    cout<<"n:"<<n<<" p:"<<p<<endl;
    for ( int i = 1 ;  i <= n ; i++) scanf("%lld",&a[i]);
    for ( int i = 1 ; i <= n ; i++) printf("%lld%c ",a[i],i==n?'\n':' ');
    build(1,n,1);
    for ( int i = 1 ; i <= 10 ; i++) printf("tree[%d].sum:%lld\n",i,tree[i].sum);
    cin>>m;
    printf("m:%d\n",m);
    while (m--)
    {
	pr();
	int opt,x,y,z;
	scanf("%d %d %d",&opt,&x,&y);
	//puts("fuck");
	printf("opt %d %d %d\n",opt,x,y);
	
	if (opt==1) 
	{
	    scanf("%d",&z);
	  //  update_mul(x,y,z,1,n,1);
	}
	else if (opt==2)
	{
	    scanf("%d",&z);
	    update_add(x,y,z,1,n,1);
	}
	else
	{
	    LL ret = query(x,y,1,n,1);
	    printf("%lld\n",ret);
	}
	puts("while _ end");
    }
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
