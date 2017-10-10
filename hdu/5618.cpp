/* ***********************************************
Author :111qqz
Created Time :2017年10月10日 星期二 19时53分38秒
File Name :5618.cpp
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
int n;
struct point
{
    int x,y,z;
    int id;
    int cnt,sum;
    void input( int _id)
    {
	scanf("%d %d %d",&x,&y,&z);
	id=_id;
    }
    bool operator < (const point &b)const
    {
	if (x!=b.x) return x<b.x;
	if (y!=b.y) return y<b.y;
	return z<b.z;
    }
    bool operator !=(const point &b)const
    {
	return x!=b.x||y!=b.y||z!=b.z;
    }
}p[N];
struct BIT
{
    int n,t[N];
    void init( int _n)
    {
	n = _n;
	ms(t,0);
    }
    inline int lowbit(int x){ return x&(-x);}
    void update( int x,int delta)
    {
	for ( int i = x ; i <= n ; i+=lowbit(i)) t[i] +=delta;
    }
    int Sum( int x)
    {
	int ret = 0 ;
	for ( int i = x ; i >=1 ;  i-=lowbit(i)) ret+=t[i];
	return ret;
    }
}bit;
bool cmpcdq(point a,point b){return a.y<b.y;}
bool cmpid(point a,point b){return a.id < b.id;}
void cdq( int l,int r)
{
    if (l==r) return;
    int mid = (l+r)>>1;
    cdq(l,mid);
    cdq(mid+1,r);
    sort(p+l,p+mid+1,cmpcdq);
    sort(p+mid+1,p+r+1,cmpcdq);
    int j = l;
    for ( int i = mid + 1 ; i <= r ; i++)
    {
	for ( ; j <= mid && p[j].y <= p[i].y ; j++) bit.update(p[j].z,p[j].cnt);
	p[i].sum+=bit.Sum(p[i].z);
    }
    for ( int i = l ; i < j ; i++) bit.update(p[i].z,-p[i].cnt);
}
int tot;
int ans[N];
int id[N]; //记录原id对应到了哪个新id
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	int T;
	scanf("%d",&T);
	while (T--)
	{
	    tot=0;
	    ms(p,0); //多组数据orz
	    scanf("%d",&n);
	    bit.init(N-1);
	    for ( int i = 1 ; i <= n ; i++) p[i].input(i);
	    int cnt = 0;
	    sort(p+1,p+n+1);
	    for ( int i = 1 ; i <= n ; i++)
	    {
		cnt++;
		if (p[i]!=p[i+1])
		{
		    p[i].cnt = cnt;
		    id[p[i].id]=tot+1;
		    p[++tot]=p[i];
		    p[tot].id = tot;
		    cnt=0;
		}
		else
		{
		    id[p[i].id] = tot+1;
		}

	    }
	    cdq(1,tot);
	    //for ( int i = 1 ; i <= n ; i++)  ans[id[p[i].id]] = p[i].sum ;
	    //for ( int i = 1 ; i <= n ; i++) printf("%d\n",ans[i]);
	    
	    sort(p+1,p+tot+1,cmpid);
	    for ( int i = 1 ; i <= n ; i++) printf("%d\n",p[id[i]].sum+p[id[i]].cnt-1);
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
