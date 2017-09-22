/*************************************************************************
	> File Name: code/poj/2828.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月29日 星期四 09时00分08秒
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<stack>
#include<cctype>
                 
#define yn hez111qqz
#define j1 cute111qqz
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ms(a,x) memset(a,x,sizeof(a))
using namespace std;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;
const int N=2E5+7;
int pos[N],val[N];
int n;
int tree[N<<2]; //tree[i]存储的是以i为根节点的子树对应的区间中空位置的数量。
int ans[N];


void PushUp(int rt)
{
    tree[rt] = tree[rt<<1]+tree[rt<<1|1]; //一段区间空位置的数量等于两端子区间中空位置的数量的和。
}
void build(int l,int r,int rt)
{
  //  cout<<"l:"<<l<<" r:"<<r<<" rt:"<<rt<<endl;
    if (l==r)
    {
	tree[rt] = 1; //初始的空位置的数量为区间长度r-l+1
	return ;
    }
    int m = (l+r)>>1;
    build(lson);
    build(rson);
    PushUp(rt);
}

void update (int p,int val,int l,int r,int rt)
{
    if (l==r)
    {
	ans[l] = val;
	tree[rt]--;
	return ;
    }
    int m = (l+r)>>1;
    if (p<=tree[rt<<1]) update(p,val,lson); //如果左子树所代表的区间中空位置的数目够的话就放左边
    else update(p-tree[rt<<1],val,rson);//否则放右边，一共需要p个空位置，左边提供了tree[rt<<1]个，还需要右边提供p-tree[rt<<1]个。
    PushUp(rt);

}


int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("code/in.txt","r",stdin);
  #endif

   while (~scanf("%d",&n))
    {

	for ( int i = 0 ; i < n ;i++) scanf("%d %d",&pos[i],&val[i]);
	build(1,n,1);

	for ( int i = n-1 ; i >= 0 ; i--)
	{
	    pos[i]++;
	    update(pos[i],val[i],1,n,1);
//	    cout<<"i:"<<i<<endl;
	}
	for ( int i =  1 ; i <= n-1 ; i++) printf("%d ",ans[i]);
	printf("%d\n",ans[n]);


    }
  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
