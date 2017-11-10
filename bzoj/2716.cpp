/* ***********************************************
Author :111qqz
Created Time :2017年10月10日 星期二 13时35分26秒
File Name :2716.cpp
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
const LL linf = 1LL<<60;
const int N=5E5+7;
int n,m;
int idx,rt;
LL ans;
LL getLL() {
    LL k = 0, fh = 1; char c = getchar();
    for(; c < '0' || c > '9'; c = getchar())
        if (c == '-') fh = -1;
    for(; c >= '0' && c <= '9'; c = getchar())
        k = k * 10 + c - '0';
    return k * fh;
}
struct KDT
{
    LL coor[2];
    LL mn[2],mx[2]; //需要维护四个方向的最值，是因为是曼哈顿距离。
    int son[2];
    bool operator < (const KDT &u)const{ return coor[idx]<u.coor[idx];}
    void init() { for ( int i = 0 ; i < 2 ;i++) mn[i]=mx[i]=coor[i];}
    void input() { for ( int i = 0 ; i < 2 ; i++) coor[i]=getLL();}
}v[N<<1],tar; //开一倍空间是因为可能全都是插点。
inline LL getDis(KDT a,KDT b) {return abs(a.coor[0]-b.coor[0]) + abs(a.coor[1]-b.coor[1]);}
void up( int x)
{
    for ( int i = 0 ; i < 2 ; i++) if (v[x].son[i]){
	int y =v[x].son[i];
	for (int j = 0 ; j < 2 ; j++) 
	    v[x].mn[j]=min(v[x].mn[j],v[y].mn[j]),v[x].mx[j]=max(v[x].mx[j],v[y].mx[j]);
    }
}
int build( int l=1,int r=n,int dim=0)
{
    idx = dim;
    int mid = (l+r)>>1;
    nth_element(v+l,v+mid,v+r+1);
    v[mid].init();
    if (l!=mid) v[mid].son[0] = build(l,mid-1,1-dim);
    if (r!=mid) v[mid].son[1] = build(mid+1,r,1-dim);
    up(mid);
    return mid;
}
LL ask( int x,KDT p)
{
    LL ret=0;
    for ( int i = 0 ; i < 2 ; i++)
    {
	ret = ret +max(0LL,v[x].mn[i]-p.coor[i])+ max(0LL,p.coor[i]-v[x].mx[i]);
    }
    return ret;
}
void insert(int x=rt,int dim=0)
{
    bool fg=v[n].coor[dim]>v[x].coor[dim];
    if (v[x].son[fg]) insert(v[x].son[fg],1-dim);
    else v[x].son[fg]=n;
    up(x);
}
void query(int x=rt,int dim=0)
{
    LL dis=getDis(v[x],tar),dl=linf,dr=linf;
    ans=min(dis,ans);
    if (v[x].son[0]) dl=ask(v[x].son[0],tar);
    if (v[x].son[1]) dr=ask(v[x].son[1],tar);
    int xx = v[x].son[0],yy=v[x].son[1];
    if (dl>=dr) swap(dl,dr),swap(xx,yy);
    if (dl<ans) query(xx,1-dim);
    if (dr<ans) query(yy,1-dim);
}

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	cin>>n>>m;
	for ( int i = 1 ; i <= n ; i++) v[i].input();
	rt =build();
	while (m--)
	{
	    int t;
	    scanf("%d",&t);
	    ans=linf;
	    if (t==1) v[++n].input(),v[n].init(),insert();
	    else tar.input(),query(),printf("%lld\n",ans);
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
