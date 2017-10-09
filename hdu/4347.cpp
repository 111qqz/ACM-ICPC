/* ***********************************************
Author :111qqz
Created Time :2017年10月08日 星期日 23时18分42秒
File Name :4347.cpp
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
const int N=5E4+7;
const int M = 10;
int n,m,k,t;
int idx;
struct Point
{
    LL coor[M];
    int id;
    void print()
    {
	for ( int i = 1 ; i <= k ; i++)
	    printf("%lld%c",coor[i],i==k?'\n':' ');
    }
    bool operator < (const Point &u)const
    {
	return coor[idx]<u.coor[idx];
    }
}po[N];
typedef pair< LL,Point >PI;
priority_queue< PI >pq; //用优先队列一定要定义小于关系啊orz...我怎么这么傻
struct KdTree
{
    Point p[N<<2];
    bool leaf[N<<2];
    void build ( int l,int r, int rt = 1,int dep=0)
    {
	if (l>r) return;
	leaf[rt] = false;
	leaf[rt<<1] = leaf[rt<<1|1] = true;
	idx = dep % k;
	int mid = (l+r)>>1;
	nth_element(po+l,po+mid,po+r+1);
	p[rt] = po[mid];
	build(l,mid-1, rt<<1,dep+1);
	build(mid+1,r,rt<<1|1,dep+1);
    }
    void query(Point tar,int rt=1,int dep=0)
    {
	if (leaf[rt]) return;
	PI cur(0,p[rt]);
	for ( int i = 1 ; i <= k ; i++) cur.fst += (p[rt].coor[i]-tar.coor[i])*(p[rt].coor[i]-tar.coor[i]);
	int idx = dep%k;
	int x=rt<<1,y=rt<<1|1,flag=0;
	LL d = tar.coor[idx]-p[rt].coor[idx];
	if (d>0) swap(x,y);
	if (!leaf[x]) query(tar,x,dep+1);
	if (pq.size()<m) pq.push(cur),flag=1;
	else
	{
	    if (cur.fst < pq.top().fst) pq.pop(),pq.push(cur);
	    if (d*d<pq.top().fst) flag = 1;
	}
	//cout<<pq.top().second.coor[0]<<" "<<pq.top().second.coor[1]<<endl;
	if (!leaf[y]&&flag) query(tar,y,dep+1);
    }
}kd;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	while (~scanf("%d %d",&n,&k))
	{
	    for ( int i = 1 ;  i <= n ; i++)
	    {
		for ( int j = 1 ; j <= k ; j++) scanf("%lld",&po[i].coor[j]);
	    }
	    scanf("%d",&t);
	    kd.build(1,n);
	    while (t--)
	    {
		Point ask;
		for ( int i = 1 ; i <= k ; i++) scanf("%lld",&ask.coor[i]);
		scanf("%d",&m);
		kd.query(ask);
		printf("the closest %d points are:\n",m);
		Point ret[20];
		//cout<<"pq_siz:"<<pq.size()<<" pq.top()"<<pq.top().sec.coor[1]<<endl;
		for ( int i = 1 ; !pq.empty() ; i++) ret[i] = pq.top().second,pq.pop();
		for ( int i = m ; i >= 1 ; i--)  ret[i].print();
	    }
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
