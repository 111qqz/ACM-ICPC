/* ***********************************************
Author :111qqz
Created Time :2016年02月13日 星期六 23时17分58秒
File Name :code/cf/problem/86D.cpp
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
int t,n;
int a[N];
int pos[N];
LL sum;
LL ans[N];
struct node
{
    int l,r;
    int id;

    bool operator <(node b)const
    {
	if (pos[l]==pos[b.l]) return r<b.r;
	return pos[l]<pos[b.l];
    }
    
}q[N];

int cnt[N*5];


void update(int x,int d)
{
    sum -= 1LL*cnt[a[x]]*cnt[a[x]]*a[x];
    cnt[a[x]]+=d;
    sum += 1LL*cnt[a[x]]*cnt[a[x]]*a[x];
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);   //TLE #54....WHY?
  #endif

	cin>>n>>t;
	int bk = 470;
	for ( int i =  1 ; i <= n ; i++)
	{
	    scanf("%d",&a[i]);
	    pos[i]=(i-1)/bk;
	}

	for ( int i = 1 ; i <= t ; i++) scanf("%d %d",&q[i].l,&q[i].r),q[i].id = i ;
	sort(q+1,q+t+1);

	int pl = 1;
	int pr = 0;
	int id;
	int l;
	int r;
	ms(cnt,0);
	sum = 0;
	for ( int i = 1 ; i <= t ; i++)
	{
	 //   cout<<"sum:"<<sum<<endl;
	    id = q[i].id;
	    l = q[i].l;
	    r = q[i].r;

	    if (pr<r)
	    {
		for ( int j = pr+1 ; j <= r ; j++)
		    update(j,1);
	    }
	    else
	    {
		for ( int j = r+1 ; j <= pr ; j++)
		    update(j,-1);
	    }
	    pr = r;

	    if (pl<l)
	    {
		for ( int j = pl ; j <=l-1 ; j++)
		    update(j,-1);
	    }
	    else
	    {
		for ( int j = l ; j <= pl-1 ; j++)
		    update(j,1);
	    }

	    pl = l;

	    ans[id] = sum;
	}

	for ( int i = 1 ;i <= t ; i++) printf("%lld\n",ans[i]);

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
