/* ***********************************************
Author :111qqz
Created Time :Tue 20 Sep 2016 02:14:23 PM CST
File Name :code/cf/problem/540E.cpp
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
int n;
struct node
{
    int l,r;
}q[N];
int f[N],p[N];
map<int,int>mp;
LL tree[N<<2];
void PushUp( int rt)
{
    tree[rt] = tree[rt<<1] + tree[rt<<1|1];
}
void update( int p,LL sc,int l,int r,int rt)
{
    if (l==r)
    {
	tree[rt] += sc;
	return ;
    }
    int m = (l+r)>>1;
    if (p<=m) update(p,sc,lson);
    else update(p,sc,rson);
    PushUp(rt);
}
LL query(int L,int R,int l,int r,int rt)
{
    if (L<=l&&r<=R) return tree[rt];
    int m = (l+r)>>1;
    LL ret = 0LL;
    if (L<=m) ret+=query(L,R,lson);
    if (R>=m+1) ret+=query(L,R,rson);
    return ret;
}
int main()
{
#ifndef  ONLINE_JUDGE 
    //freopen("code/in.txt","r",stdin);
#endif
    scanf("%d",&n);
    mp.clear();
    ms(p,0);
    for ( int i = 1 ;i <= n ; i++)
    {
	scanf("%d%d",&q[i].l,&q[i].r);
	mp[q[i].l] = 0 ;
	mp[q[i].r] = 0;
    }
    int cnt = 0 ;
    for ( auto it = mp.begin() ; it!=mp.end() ; it++)
    {
	it->sec = ++cnt;
	f[cnt] = it->fst;
	p[cnt] = cnt;
    }
    for ( int i = 1 ; i <= n ; i++) q[i].l = mp[q[i].l],q[i].r = mp[q[i].r];
    for ( int i = 1 ; i <= n ; i++) swap(p[q[i].l],p[q[i].r]);
    LL ans = 0LL;
    for ( LL i = 1; i <= cnt ; i++)
    {
	update(p[i],1,1,cnt,1);
	ans += i-query(1,p[i],1,cnt,1);
	ans += abs(f[i]-f[p[i]])-abs(i-p[i]);
    }
    printf("%lld\n",ans);
#ifndef ONLINE_JUDGE  
    fclose(stdin);
#endif
    return 0;
}
