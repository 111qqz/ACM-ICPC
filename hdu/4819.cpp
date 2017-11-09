#include <bits/stdc++.h>
#define ms(a,x) memset(a,x,sizeof(a))
#define lowbit(x) (x&(-x))
using namespace std;
typedef long long LL;
const double eps = 1e-8;
const double PI = acos(-1.0);
const int N=805;
int n;
int a[N][N];
struct Tree
{
	int mn,mx;
	Tree()
	{
		mn = 1E9;
		mx = 0;
	}
	void init()
	{
		mn = 1E9;
		mx = 0;
	}
}tree[N*10000];
int _max( int a,int b,int c,int d)
{
	int ret = max(a,b);
	ret = max(ret,c);
	ret = max(ret,d);
	return ret;
}
int _min( int a,int b,int c,int d)
{
	int ret = min(a,b);
	ret = min(ret,c);
	ret = min(ret,d);
	return ret;
}
void PushUp( int rt)
{
//	cout<<"rt:"<<rt<<endl;
	tree[rt].mn = _min(tree[rt*4+1].mn,tree[rt*4+2].mn,tree[rt*4+3].mn,tree[rt*4+4].mn);
	tree[rt].mx = _max(tree[rt*4+1].mx,tree[rt*4+2].mx,tree[rt*4+3].mx,tree[rt*4+4].mx);
}


void insert( int idx,int lx,int rx,int ly,int ry,int X,int Y,int val)
{
//	cout<<"val:"<<val<<endl;
	if (lx==rx&&ly==ry)
	{
		tree[idx].mn = tree[idx].mx = val;

//		cout<<"fuck"<<" val:"<<val<<" mn:"<<tree[idx].mn <<" mx:"<<tree[idx];
		return;
	}
	int mx = (lx+rx) >> 1;
	int my = (ly+ry) >> 1;
	if (X<=mx&&Y<=my) insert(idx*4+1,lx,mx,ly,my,X,Y,val);
	if (X<=mx&&Y>=my+1) insert(idx*4+2,lx,mx,my+1,ry,X,Y,val);
	if (X>=mx+1&&Y<=my) insert(idx*4+3,mx+1,rx,ly,my,X,Y,val);
	if (X>=mx+1&&Y>=my+1) insert(idx*4+4,mx+1,rx,my+1,ry,X,Y,val);
//	puts("miao");
	PushUp(idx);
}
int queryMN( int idx,int lx,int rx,int ly,int ry,int Lx,int Rx,int Ly,int Ry)
{
	if (Lx<=lx && Rx>=rx && Ly<=ly && Ry>=ry) return tree[idx].mn;
	int mx = (lx+rx)>>1,my = (ly+ry)>>1,t=1E9;
	if (Lx<=mx && Ly<=my)  t = min(t,queryMN(idx*4+1,lx,mx,ly,my,Lx,Rx,Ly,Ry));
	if (Lx<=mx && Ry>my) t = min(t,queryMN(idx*4+2,lx,mx,my+1,ry,Lx,Rx,Ly,Ry));
	if (Rx>mx  && Ly<=my) t = min (t,queryMN(idx*4+3,mx+1,rx,ly,my,Lx,Rx,Ly,Ry)); 
	if (Rx>mx&&Ry>my) t = min (t,queryMN(idx*4+4,mx+1,rx,my+1,ry,Lx,Rx,Ly,Ry));
	return t;
}
int queryMX( int idx,int lx,int rx,int ly,int ry,int Lx,int Rx,int Ly,int Ry)
{
	if (Lx<=lx && Rx>=rx && Ly<=ly && Ry>=ry) return tree[idx].mx;
	int mx = (lx+rx)>>1,my = (ly+ry)>>1,t=0;
	if (Lx<=mx && Ly<=my)  t = max(t,queryMX(idx*4+1,lx,mx,ly,my,Lx,Rx,Ly,Ry));
	if (Lx<=mx && Ry>my) t = max(t,queryMX(idx*4+2,lx,mx,my+1,ry,Lx,Rx,Ly,Ry));
	if (Rx>mx  && Ly<=my) t = max (t,queryMX(idx*4+3,mx+1,rx,ly,my,Lx,Rx,Ly,Ry)); 
	if (Rx>mx&&Ry>my) t = max(t,queryMX(idx*4+4,mx+1,rx,my+1,ry,Lx,Rx,Ly,Ry));
	return t;
}
void init()
{
	for ( int i = 0 ; i < 8E6 ; i++) tree[i].init();
}
int main(){
#ifdef YourCodeHasBug
//	freopen("in2","r",stdin);
#endif
	int T;
	cin>>T;
	int cas = 0 ;
	while (T--)
	{
		init();
		scanf("%d",&n);
		for ( int i = 1 ; i <= n ; i++)
			for ( int j = 1 ; j <= n ; j++)
			{
				scanf("%d",&a[i][j]);
//				cout<<"a[i][j]:"<<a[i][j]<<endl;
				insert(0,1,n,1,n,i,j,a[i][j]);
			}
//		for ( int i = 0 ; i <= 20 ; i++) printf("tree_mn:%d mx:%d\n",tree[i].mn,tree[i].mx);
		int m;
		scanf("%d",&m);
			printf("Case #%d:\n",++cas);
		while (m--)
		{
			int x,y,L;
			scanf("%d %d %d",&x,&y,&L);
			int Lx = max(x-L/2,1);
			int Rx = min(n,x+L/2);
			int Ly = max(y-L/2,1);
			int Ry = min(n,y+L/2);
//			printf("x:[%d,%d] y:[%d,%d]\n",Lx,Rx,Ly,Ry);
			int mn = queryMN(0,1,n,1,n,Lx,Rx,Ly,Ry);
			int mx = queryMX(0,1,n,1,n,Lx,Rx,Ly,Ry);
			int newval = floor((mn+mx)/2);
			//printf("mn:%d mx:%d %d\n",mn,mx,newval);
			printf("%d\n",newval);
			insert(0,1,n,1,n,x,y,newval);
		}
	}
#ifdef YourCodeHasBug
	fclose(stdin);
#endif
	return 0;
}

