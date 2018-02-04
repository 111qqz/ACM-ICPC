/* ***********************************************
Author :111qqz
Created Time :2017年10月02日 星期一 13时21分45秒
File Name :C.cpp
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
int n;
/*
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int N=2E6+7;

int n;
int mx[N];
struct Node
{
    int cf,tc;
    int id;
    bool operator < (Node &b)const
    {
	return cf<b.cf;
    }
}a[N];
int ans[N];
int t[N];
int tree[N<<2];
void PushUp( int rt)
{
    tree[rt] = tree[rt<<1] + tree[rt<<1|1];
}
void update( int x,int l,int r,int rt)
{
    //cout<<"l:"<<l<<" r:"<<r<<" rt:"<<rt<<" x:"<<x<<endl;
    if (l==r) 
    {
	tree[rt]++;
	return;
    }
    int m = (l+r)>>1;
    if (x<=m) update(x,lson);
    else update(x,rson);
    PushUp(rt);
}
int query( int L,int R,int l,int r,int rt)
{
    //cout<<"L:"<<L<<" R:"<<R<<" l:"<<l<<" r:"<<r<<" rt:"<<rt<<endl;
    if (L>R) return 0;
    if (L<=l && r<=R)
    {
	return tree[rt];
    }
    int m = (l+r)>>1;
    int ret = 0 ;
    if (L<=m) ret = ret + query(L,R,lson);
    if (R>=m+1) ret = ret + query(L,R,rson);
    return ret;
}

int lowbit( int x)
{
    return x&(-x);
}
void update ( int x,int delta)
{
    for ( int i = x ; i < N ;  i+=lowbit(i))
    {
	t[i] += delta;
    }
}
int sum ( int x)
{
    //cout<<"x:"<<x<<endl;
    int ret = 0;
    for ( int i = x ; i >=1 ; i-=lowbit(i))
    {
	ret += t[i];
    }
    return ret;
}
*/
struct node{
    int idx,cc,tf,posc;
}p[100010];
int ans[100010];
bool cmpcc(node x,node y){
    return x.cc>y.cc;
}
bool cmptf(node x,node y){
    return x.tf>y.tf;
}

int main()
{
	//freopen("./in.txt","r",stdin);
	freopen("codecoder.in","r",stdin);
	freopen("codecoder.out","w",stdout);
/*	
    cin>>n;
	ms(tree,0);
	for ( int i = 1 ; i <= n ; i++) 
	{
	    int x,y;
	    scanf("%d %d",&x,&y);
	    a[i].cf = x;
	    a[i].tc = y;
	    a[i].id = i;
	    
	}
	sort(a+1,a+n+1);
	ms(mx,0);
	for ( int i = 1 ; i <= n ; i++) mx[i] = max(mx[i-1],a[i].tc);

	for ( int i = n ; i >=1  ; i--)
	{
	    int tmp = query(1,mx[i]-1,1,N-1,1);
	    //cout<<"tmp:"<<tmp<<endl;
		ans[a[i].id] = tmp + i-1;
	    update(a[i].tc,1,N-1,1);
	}

	
	for ( int i = n ; i >= 1 ; i--)
	{
	   // cout<<"i:"<<i<<" a[i].tc"<<a[i].tc<<endl;
	    int tmp = query(1,mx[i]-1,1,N-1,1);
//	    cout<<"tmp:"<<tmp<<endl;
	    ans[a[i].id] = tmp + i-1;
	    update(a[i].tc,1,N-1,1);
	}
	
	for ( int i = 1 ; i <= n ; i++) printf("%d\n",ans[i]);
    return 0;
*/
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
	scanf("%d%d",&p[i].cc,&p[i].tf);
	p[i].idx=i;
    }
    sort(p+1,p+n+1,cmpcc);
    for(int i=1;i<=n;i++)
	p[i].posc=i;
    sort(p+1,p+n+1,cmptf);
    for(int i=1;i<=n;i++){
	int cur=p[i].posc;
	for(int j=i;j<=cur;j++){
	    cur=max(cur,p[j].posc);
	    ans[p[j].idx]=n-i;
	}
	i=cur;
    }
    for(int i=1;i<=n;i++)
	printf("%d\n",ans[i]);
    return 0;
}

