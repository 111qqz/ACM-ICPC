/* ***********************************************
Author :111qqz
Created Time :2017年11月10日 星期五 17时18分40秒
File Name :4819_2D.cpp
 ************************************************ */

#include <bits/stdc++.h>
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
const int N=803;
struct Treey
{
    int l,r;
    int Max,Min;
};
int n;
int rtx[N],rty[N] ; //rtx[i]表示横坐标为i的点属于哪棵线段树
struct  Treex
{
    int l,r;
    Treey treey[N<<2];
    void build ( int _l,int _r,int rt)
    {
	treey[rt].l = _l;
	treey[rt].r = _r;
	treey[rt].Max = -inf;
	treey[rt].Min = inf;
	if (_l==_r)
	{
	    rty[_l] = rt;
	    return;
	}
	int m = (_l + _r) / 2;
	build (_l,m,rt<<1);
	build(m+1,_r,rt<<1|1);
    }
    int QMin( int L,int R,int rt)
    {
	if (treey[rt].l >= L && treey[rt].r <= R) return treey[rt].Min;
	int m = (treey[rt].l + treey[rt].r) / 2;
	int ret = 1E9;
	if (L<=m) ret = QMin(L,R,rt<<1);
	if (R>=m+1) ret = min(ret,QMin(L,R,rt<<1|1));
	return ret;
    }
    int QMax( int L,int R,int rt)
    {
	if (treey[rt].l >= L && treey[rt].r <= R) return treey[rt].Max;
	int m = (treey[rt].l + treey[rt].r) / 2;
	int ret = 0 ;
	if (L<=m) ret = QMax (L,R,rt<<1);
	if (R>=m+1) ret = max(ret,QMax(L,R,rt<<1|1));
	return ret;
    }
}treex[N<<2];

void build (int l,int r,int rt)
{
    treex[rt].l = l;
    treex[rt].r = r;
    treex[rt].build(1,n,1);
    if (l==r)
    {
	rtx[l] = rt;
	return;
    }
    int m = (l+r)>>1;
    build (lson);
    build (rson);
}
void update ( int x,int y,int val) //单点更新，更新a[x,y]到val
{
    int rx = rtx[x];
    int ry = rty[y];
    treex[rx].treey[ry].Min = treex[rx].treey[ry].Max = val;
    for ( int i = rx ; i ; i >>=1)
	for ( int j = ry ; j ; j >>=1)
	{
	    if (i==rx && j==ry) continue; //上面更新过了
	    if (j==ry)
	    {
		treex[i].treey[j].Min = min(treex[i<<1].treey[j].Min,treex[i<<1|1].treey[j].Min);
		treex[i].treey[j].Max = max(treex[i<<1].treey[j].Max,treex[i<<1|1].treey[j].Max);
	    }
	    else
	    {
	    	treex[i].treey[j].Min = min(treex[i].treey[j<<1].Min,treex[i].treey[j<<1|1].Min);
		treex[i].treey[j].Max = max(treex[i].treey[j<<1].Max,treex[i].treey[j<<1|1].Max);
	    }
	}
}
int QMin( int L1,int R1,int L2,int R2,int rt)
{
    if (treex[rt].l >= L1 && treex[rt].r <= R1) return treex[rt].QMin(L2,R2,1);
    int m = (treex[rt].l + treex[rt].r)/2;
    int ret = 1E9;
    if (L1<=m) ret = QMin(L1,R1,L2,R2,rt<<1);
    if (R1>=m+1) ret = min(ret,QMin(L1,R1,L2,R2,rt<<1|1));
    return ret;
}
int QMax ( int L1,int R1,int L2,int R2,int rt)
{
 //   printf("rt:%d l:%d r:%d  L1:%d R1:%d \n",rt,treex[rt].l,treex[rt].r,L1,R1);
    if (treex[rt].l >= L1 && treex[rt].r <=R1) return treex[rt].QMax(L2,R2,1);
    int m = (treex[rt].l + treex[rt].r) / 2;
    int ret = 0 ;
    if (L1<=m) ret = QMax(L1,R1,L2,R2,rt<<1);
    if (R1>=m+1) ret = max(ret, QMax(L1,R1,L2,R2,rt<<1|1));
    return ret;
}

int main() 
{
#ifndef  ONLINE_JUDGE 
    freopen("./in.txt","r",stdin);
#endif
    int T,cas=0;
    cin>>T;
    while (T--)
    {
	printf("Case #%d:\n",++cas);
	scanf("%d",&n);
	build (1,n,1);
	for ( int i = 1 ; i  <= n ; i++)
	    for ( int j = 1; j <= n ; j++)
	    {
		int x;
		scanf("%d",&x);
		update(i,j,x);
	    }
	int q;
	scanf("%d",&q);
	while (q--)
	{
	    int x,y,L;
	    scanf("%d %d %d",&x,&y,&L);
	    int L1 = max(x-L/2,1);
	    int R1 = min(x+L/2,n);
	    int L2 = max(y-L/2,1);
	    int R2 = min(y+L/2,n);
//	    printf("[%d,%d] [%d,%d]\n",L1,R1,L2,R2);
	    int Mx = QMax(L1,R1,L2,R2,1);
	    int Mn = QMin(L1,R1,L2,R2,1);
	    int val = floor((Mx+Mn)/2);
	    printf("%d\n",val);
	    update(x,y,val);
	}
    }	
#ifndef ONLINE_JUDGE  
    fclose(stdin);
#endif
    return 0;
}
