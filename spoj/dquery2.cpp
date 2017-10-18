/* ***********************************************
Author :111qqz
Created Time :Fri 16 Sep 2016 11:34:32 PM CST
File Name :code/spoj/dquery.cpp
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
const int MAXN = 1E6+7;
const int N=3E4+7;
const int M=2E5+7;
int n,Q;
int a[N];
int pos[N];
int sum;
int cnt[MAXN]={0};
struct node
{
    int l,r;
    int id;
    bool operator < (node b)const
    {
	if (pos[l]==pos[b.l]) return r<b.r;
	return pos[l] < pos[b.l];
    }
}q[M];

int ans[M];
void update ( int x,int d)
{
    cnt[a[x]]+=d;
    if (d==1&&cnt[a[x]]==1) sum++;
    if (d==-1&&cnt[a[x]]==0) sum--;
}

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	int bk = 173;// sqrt(30000)
	cin>>n;
	for ( int i = 1 ; i <= n ; i++) 
	{
	    scanf("%d",&a[i]);
	    pos[i] = (i-1)/bk;
	}
	cin>>Q;
	for ( int i = 1 ; i <= Q ; i++) scanf("%d %d",&q[i].l,&q[i].r),q[i].id = i ;
	sort(q+1,q+Q+1);
	int pl=1,pr=0,id,l,r;
	ms(cnt,0);
	sum = 0 ;
	for ( int i = 1 ; i <= Q ; i++)
	{
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
		for ( int j = pl ; j <= l-1 ; j++)
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
	for ( int i = 1 ; i <= Q ; i++) printf("%d\n",ans[i]);
	

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
