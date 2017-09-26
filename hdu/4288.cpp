/* ***********************************************
Author :111qqz
Created Time :2017年09月26日 星期二 12时42分10秒
File Name :4288.cpp
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
int n;
struct Node
{
    int cnt; //区间中，在集合中存在的元素的个数。
    LL sum[5]; //sum[i]表示该区间中，以区间起点为下标1开始计算时，位置为x%5==i时的元素的和。
}tree[N<<2];
struct Opt
{
    int opt;
    LL val;
}qu[N];
LL H[N],A[N];
int cnt;
int Hash( int x)
{
    return lower_bound(H,H+cnt,x)-H;
}
void PushUp( int rt)
{
    tree[rt].cnt = tree[rt<<1].cnt + tree[rt<<1|1].cnt;
    for ( int i = 0 ; i < 5 ; i++)
    {
	int left_len = tree[rt<<1].cnt;
	tree[rt].sum[i] = tree[rt<<1].sum[i] + tree[rt<<1|1].sum[((i-left_len)%5+5)%5];
    }
}
void update( int p,int opt,int l,int r,int rt)
{
    if (l==r)
    {
	if (opt==1)
	{
	    tree[rt].cnt=1;
	    tree[rt].sum[1]=H[p-1];
	}
	else
	{
	    tree[rt].cnt=0;
	    tree[rt].sum[1]=0;
	}
	return ;
    }

	int m = (l+r)>>1;
	if (p<=m) update(p,opt,lson);
	else update(p,opt,rson);
	PushUp(rt);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	while (~scanf("%d",&n))
	{
	    ms(tree,0);
	    cnt=0;
	    for ( int i = 1 ; i <= n ; i++)
	    {
		char tmp[5];
		scanf("%s",tmp);
		if (tmp[0]=='a')
		{
		    qu[i].opt=1;
		    int x;
		    scanf("%d",&x);
		    qu[i].val=x;
		    H[cnt++]=x;
		}else if (tmp[0]=='d')
		{
		    qu[i].opt=2;
		    int x;
		    scanf("%d",&x);
		    qu[i].val = x;
		}else
		{
		    qu[i].opt=3;
		}
	    }
		sort(H,H+cnt);
		cnt = unique(H,H+cnt)-H;
		//cout<<"cnt:"<<cnt<<endl;	
		for ( int i = 1 ; i <= n ; i++)
		{
		    LL ans = tree[1].sum[3];
		    if (qu[i].opt==3) printf("%lld\n",ans);
		    else
		    {
			int x = Hash(qu[i].val)+1;
			//cout<<"val:"<<qu[i].val<<"x:"<<x<<" H[p-1]:"<<H[x-1]<<endl;
			update(x,qu[i].opt,1,cnt+1,1);
		    }
		}
	 }
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
