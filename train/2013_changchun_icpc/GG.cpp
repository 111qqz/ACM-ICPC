#include <bits/stdc++.h>
#define ms(a,x) memset(a,x,sizeof(a))
#define lowbit(x) (x&(-x))
#define lson  l,m,rt<<1
#define rson  m+1,r,rt<<1|1
using namespace std;
typedef long long LL;
const double eps = 1e-8;
const double PI = acos(-1.0);
const int N=802;
int n;
int a[N][N];
struct Tree
{
	int mx;
	int mn;
	Tree()
	{
		mx=0;
		mn=1E9;
	}
	void init()
	{
	    mx = 0;
	    mn =1E9;
	}
}tree[N<<2][N<<2];
void PushUpY( int id_rt,int rt)
{
	tree[id_rt][rt].mx = max(tree[id_rt][rt<<1].mx,tree[id_rt][rt<<1|1].mx);
	tree[id_rt][rt].mn = min(tree[id_rt][rt<<1].mn,tree[id_rt][rt<<1|1].mn);
}
void PushUpX( int rt)
{
	tree[rt][1].mx = max(tree[rt<<1][1].mx,tree[rt<<1|1][1].mx);
	printf("mxL:%d mxR:%d  rt:%d\n",tree[rt<<1][1].mx,tree[rt<<1|1][1].mx,rt);
	tree[rt][1].mn = min(tree[rt<<1][1].mn,tree[rt<<1|1][1].mn);
}

void updatey( int id_rt,int pos,int val,int l,int r,int rt)
{
	if (l==r)
	{
		tree[id_rt][rt].mn =tree[id_rt][rt].mx= val;
		return;
	}
	int m = (l+r)>>1;
	if (pos<=m) updatey(id_rt,pos,val,lson);
	else updatey(id_rt,pos,val,rson);
	PushUpY(id_rt,rt);
}

void updatex( int x,int y,int val,int l,int r,int rt)
{
	if (l==r)
	{
		updatey(rt,y,val,1,n,1);
		return;
	}
	int m = (l+r)>>1;
	if (x<=m) updatex(x,y,val,lson);
	else updatex(x,y,val,rson);
	PushUpX(rt);
}

int queryY_mx( int id_rt,int L,int R,int l,int r,int rt)
{
    if (L<=l && r<=R) return tree[id_rt][rt].mx;
    int m = (l+r)>>1;
    int ret = 0 ;
    if (L<=m) ret = queryY_mx(id_rt,L,R,lson);
    if (R>=m+1) ret = max(ret,queryY_mx(id_rt,L,R,rson));
    return ret;
}
int queryX_mx( int L1,int R1,int L2 ,int R2,int l,int r,int rt )
{
    if (L1<=l && r<=R1)
    {
	return queryY_mx(rt,L2,R2,1,n,1);
    }
    int m = (l+r)>>1;
    int ret = 0;
    if (L1<=m) ret =queryX_mx(L1,R1,L2,R2,lson);
    if (R1>=m+1) ret = max(ret,queryX_mx(L1,R1,L2,R2,rson));
    return ret;
}
int queryY_mn( int id_rt,int L,int R,int l,int r,int rt)
{
//    printf("Y_mn id_rt:%d L:%d R:%d l:%d r:%d rt:%d\n",id_rt,L,R,l,r,rt);
    if (L<=l&&r<=R)
    {
	printf("id_rt %d rt:%d\n",id_rt,rt);
	return tree[id_rt][rt].mn;
    }
    int m = (l+r)>>1;
    int ret = 1E9;
    if (L<=m) ret = queryY_mn(id_rt,L,R,lson);
    if (R>=m+1) ret = min(ret,queryY_mn(id_rt,L,R,rson));
    printf("Y_mn:%d\n",ret);
    return ret;
}
int queryX_mn( int L1,int R1,int L2,int R2,int l,int r,int rt)
{
	printf("l:%d r:%d rt:%d L1:%d R1:%d \n",l,r,rt,L1,R1);
	if (L1<=l&&r<=R1)
	{
	    return queryY_mn(rt,L2,R2,1,n,1);
	}
	int m = (l+r)>>1;
	int ret = 1E9;
	if (L1<=m) ret = queryX_mn(L1,R1,L2,R2,lson);
	if (R1>=m+1) ret = min(ret,queryX_mn(L1,R1,L2,R2,rson));
	return ret;
}
void init()
{
    for ( int i = 0 ; i < 4*N ; i++)
	for ( int j = 0 ; j < 4*N ; j++) 
	    tree[i][j].init();
}
int main(){
	freopen("./in.txt","r",stdin);
	int T;
	cin>>T;
	while (T--)
	{
		init();
		scanf("%d",&n);
		for ( int i = 1 ; i <= n ; i++)
			for ( int j = 1 ; j  <= n ; j++) 
			{
			    scanf("%d",&a[i][j]);
			    updatex(i,j,a[i][j],1,n,1);
			}

		//for ( int i = 1 ; i <= 5 ; i++) printf("mn: %d mx: %d\n",tree[i][1].mn,tree[i][1].mx);
		
		int q;
		scanf("%d",&q);
		while (q--)
		{
		    int x,y,L;
		    scanf("%d %d %d",&x,&y,&L);
		    int Lx = max(1,x-L/2);
		    int Rx = min(n,x+L/2);
		    int Ly = max(1,y-L/2);
		    int Ry = min(n,y+L/2);
		    int mn = queryX_mn(Lx,Rx,Ly,Ry,1,n,1);
		    int mx = queryX_mx(Lx,Rx,Ly,Ry,1,n,1);
		    int val = floor((mn+mx)/2);
		    printf("X:[%d,%d]  Y:[%d,%d]\n",Lx,Rx,Ly,Ry);
		    printf("mn:%d mx:%d\n",mn,mx);
		    printf("%d\n",val);
		    //updatex(x,y,val,1,n,1);
		}
		
	    }


	fclose(stdin);
	return 0;
}
