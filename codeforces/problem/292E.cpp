/* ***********************************************
Author :111qqz
Created Time :Tue 06 Sep 2016 08:41:03 PM CST
File Name :code/cf/problem/292E.cpp
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
const int N=1E5+7;
int lazy[N<<2];
int n,m;
int q[N]; //记录覆盖信息，q[i]表示第i个覆盖的位移差。
int a[N],b[N];
void PushDown( int rt)
{
    if (lazy[rt])
    lazy[rt<<1]=lazy[rt<<1|1]=lazy[rt];
    lazy[rt] =  0;
}
void update(int L,int R,int sc,int l,int r,int rt)
{
    if (L<=l && r<=R)
    {
	lazy[rt] = sc;
	return;
    }
    PushDown(rt);
    int m = (l+r)>>1;
    if (L<=m) update(L,R,sc,lson);
    if (R>=m+1) update(L,R,sc,rson); //如果是区间查询或者修改，那么就需要分别两个if来判断。
}
int query(int p,int l,int r,int rt)
{
    if (l==r) return lazy[rt];
    PushDown(rt);
    int m = (l+r)>>1;
    if (p<=m) query(p,lson);  //如果是单点查询或者修改，那么不在这个就一定在另一个。
    else query(p,rson);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for ( int i = 1 ; i <= n ; i++) cin>>a[i];
	for ( int i = 1 ; i <= n ; i++) cin>>b[i];
	ms(lazy,0);
	for ( int i = 1 ; i <=  m; i++)
	{
	    int opt;
	    cin>>opt;
	    if (opt==1)
	    {
		int x,y,k;
		cin>>x>>y>>k;
		q[i]=x-y;
		update(y,y+k-1,i,1,n,1);
	    }
	    else
	    {
		int x;
		cin>>x;
		int markid = query(x,1,n,1);
		if (markid) cout<<a[x+q[markid]]<<endl; else cout<<b[x]<<endl;
	    }
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
