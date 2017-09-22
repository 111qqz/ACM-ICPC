/* ***********************************************
Author :111qqz
Created Time :Thu 22 Sep 2016 02:07:39 PM CST
File Name :code/cf/problem/594D.cpp
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
const int N=2E5+7;
const int M=1E6+7;
const LL MOD = 1E9+7;
struct node
{
    int l,r;
    int id;
    bool operator < (node b)const
    {
	return r<b.r;
    }
}q[N];
LL a[N],pre[N];
int lst[M];
int n,Q;
LL ksm(LL a,LL b)
{
    LL res = 1LL;
    while (b>0LL)
    {
	if (b%2)
	    res = (res*a)%MOD;
	b = b>>1LL;
	a = (a*a)%MOD;
    }
    return res;
}
LL get_inv(LL x){
    return ksm(x,MOD-2);
}
bool vis[M];
vector <int>factor[M];
void init( ) //预处理1到1E6的每个数的质因子
{
    ms(vis,false);
    for ( int i = 2 ; i < M ; i++) 
	if (!vis[i])
	    for ( int j = i ; j < M ; j+=i)
		vis[j] = true,factor[j].push_back(i);
}
LL t[M];
int lowbit( int x) 
{
    return x&(-x);
}
void update( int x,LL delta)
{
    for ( int i = x ; i <= n ; i+=lowbit(i) )
	t[i] = (t[i] * delta)%MOD;
}
LL get_mul( int x)
{
    LL res = 1LL;
    for ( int i = x ; i >= 1 ; i-=lowbit(i))
	res = (res * t[i])%MOD;
    return res;
}
LL ans[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	init();
//	cout<<"www"<<endl;
	ms(lst,0);
	scanf("%d",&n);
	for ( int i = 1 ;  i < M ; i++) t[i] = 1LL; //bit的初始化。。由于是乘积。。所以初始化为1.
	pre[0]=1LL;
	for ( int i = 1 ; i <= n ; i++) scanf("%lld",a+i),pre[i] = (pre[i-1]*a[i])%MOD;
	scanf("%d",&Q);
	for ( int i = 1 ; i <= Q ; i++) scanf("%d%d",&q[i].l,&q[i].r),q[i].id = i;
	sort(q+1,q+Q+1);
	int cur = 1;
	for ( int i = 1 ; i <= Q ; i++)
	{
	    for  ( ; cur <= q[i].r ; cur++)
	    {
		int siz = factor[a[cur]].size();
		for ( int j = 0 ; j < siz;  j++)
		{
		    int val = factor[a[cur]][j];
	//	    cout<<"a[cur]:"<<a[cur]<<" val:"<<val<<endl;
		    if (lst[val])
		    {
			update(lst[val],val);
			update(lst[val],get_inv(val-1));
		    }
		    update(cur,val-1);
		    update(cur,get_inv(val));
		    lst[val] = cur;
		}
	    }
	    LL ans1 = get_mul(q[i].r)*get_inv(get_mul(q[i].l-1))%MOD;
	    LL ans2 = pre[q[i].r]*get_inv(pre[q[i].l-1])%MOD;
	    ans[q[i].id] = (ans1*ans2)%MOD;
	    //mgj....这种这么长的一堆括号的式子分开写会死啊。。。。。。有毒。
	    //ans[q[i].id] = (( get_mul(q[i].r)*get_inv(get_mul(q[i].l-1))%MOD ) * ( pre[q[i].r] * get_inv( pre[q[i].l-1] )%MOD ) )%MOD;
	}
	for ( int i = 1 ; i <= Q ; i ++) printf("%lld\n",ans[i]);
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
