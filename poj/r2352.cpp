/* ***********************************************
Author :111qqz
Created Time :2016年09月04日 星期日 14时31分12秒
File Name :code/poj/r2352.cpp
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
const int N=32005;
int tree[N<<2];//tree的N写成了区间个数的15000，wa了一发。
int ans[N];
int n;
pi a[N];
void PushUp( int rt)
{
    tree[rt] = tree[rt<<1] + tree[rt<<1|1];
}
void update(int p,int l,int r,int rt)
{
    if (l==r)
    {
	tree[rt]++;
	return;
    }
    int m = (l+r)>>1;
    if (p<=m) update(p,lson);
    else update(p,rson);
    PushUp(rt);
}
int query(int L,int R,int l,int r,int rt)
{
    if (L<=l&&r<=R) return tree[rt];
    int m = (l+r)>>1;
    int ret = 0 ;
    if (L<=m)
    {
	int res  =query(L,R,lson);
	ret = ret + res;
    }
    if (R>=m+1)
    {
	int res  = query(L,R,rson);
	ret = ret + res;
    }
    return ret;
}
int main()
{
#ifndef  ONLINE_JUDGE 
    freopen("code/in.txt","r",stdin);
#endif
    scanf("%d",&n);
    ms(ans,0);
    for ( int i = 1 ;i  <= n ; i++) scanf("%d%d",&a[i].fst,&a[i].sec),a[i].fst++,a[i].sec++;
    for ( int i = 1 ; i <= n ; i++)
    {
	int tmp = query(1,a[i].fst,1,32001,1);
	ans[tmp]++;
	update(a[i].fst,1,32001,1);
    }
    for ( int i = 0 ; i <= n-1 ; i++)
	printf("%d\n",ans[i]);
#ifndef ONLINE_JUDGE  
    fclose(stdin);
#endif
    return 0;
}
