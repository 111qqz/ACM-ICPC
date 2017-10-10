/* ***********************************************
Author :111qqz
Created Time :2017年10月10日 星期二 18时35分53秒
File Name :3262.cpp
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
const int N=1E5+7;
const int M=2E5+7;
int n,k;
int ans[N];
struct Point
{
    int x,y,z;
    int cnt,sum;
    bool operator < ( const Point &b)const
    {
	if (x!=b.x) return x<b.x;
	if (y!=b.y) return y<b.y;
	return z<b.z;
    }
    bool operator == (const Point &p)const
    {
	return x==p.x&&y==p.y&&z==p.z;
    }
}p[N];
struct BIT
{
    int n,t[M];
    void init(int _n)
    {
	n=_n;
	ms(t,0);
    }
    int lowbit( int x){ return x&(-x);}
    void update( int x,int delta)
    {
	for ( int i = x ; i <= n ; i+=lowbit(i))
	    t[i]+=delta;
    }
    int Sum( int x)
    {
	int ret = 0;
	for ( int i = x ; i >=1 ; i-=lowbit(i)) ret+=t[i];
	return ret;
    }
}bit;
bool cmpcdq(Point a,Point b) { return a.y<b.y;}
void cdq( int l,int r)
{
    if (l==r) return;
    int mid = (l+r)>>1;
    cdq(l,mid);
    cdq(mid+1,r);
    sort(p+l,p+mid+1,cmpcdq);
    sort(p+mid+1,p+r+1,cmpcdq);
    int j = l;
    for ( int i = mid+1 ; i <= r ; i++)
    {
	for ( ; j <= mid && p[j].y<=p[i].y ; j++) bit.update(p[j].z,p[j].cnt);
	p[i].sum+=bit.Sum(p[i].z);
    }
    for ( int i = l ; i < j ; i++) bit.update(p[i].z,-p[i].cnt);
}
int tot=0;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	scanf("%d%d",&n,&k);
	bit.init(k);
	for ( int i = 1; i  <= n ; i++) scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z);
	sort(p+1,p+n+1);//先去重
	int cnt = 0 ;
	for (  int i = 1 ; i <= n ; i++)
	{
	    cnt++;
	    if ( !(p[i]==p[i+1]))
	    {
		p[++tot]=p[i];
		p[tot].cnt = cnt;
		cnt = 0;
	    }
	}
	cdq(1,tot);
	for ( int i = 1;  i <= tot ; i++) ans[p[i].sum+p[i].cnt-1]+=p[i].cnt; //因为全相等也算大于，-1是减去自己
	for ( int i = 0 ; i < n ; i++) printf("%d\n",ans[i]);
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
