/* ***********************************************
Author :111qqz
Created Time :2016年02月17日 星期三 16时11分00秒
File Name :code/nbut/1457.cpp
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
const int N=1E5+7;
int a[N],b[N];
LL  cnt[N];
int pos[N];
LL ans[N];
LL sum;
int n,m;

struct node
{
    int l,r;
    int id;

    bool operator < (node b)const
    {
	if (pos[l]==pos[b.l]) return r<b.r;
	return pos[l]<pos[b.l];
    }
}q[N];



void update(int x,int d)
{
    
	sum-=cnt[a[x]]*cnt[a[x]]*cnt[a[x]];
	cnt[a[x]]+=d;
	sum +=cnt[a[x]]*cnt[a[x]]*cnt[a[x]];
    
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (scanf("%d",&n)!=EOF)
	{
	    ms(cnt,0);
	    ms(ans,0);
	    sum = 0LL;
	    
	    int siz = 330;//sqrt(100000);
	    for ( int i = 1 ; i <= n ; i++)
	    {
		scanf("%d",&b[i]);
		pos[i] = (i-1)/siz;
		a[i] = b[i];
	    }

	    sort(b+1,b+n+1);  //离散化
	    int t = unique(b+1,b+n+1)-b-1;
	    for ( int i = 1 ; i <= n ; i++) a[i]=lower_bound(b+1,b+t+1,a[i])-b;

	    scanf("%d",&m);
	    for ( int i = 1 ; i <= m ; i++)
	    {
		scanf("%d %d",&q[i].l,&q[i].r);
		q[i].id = i ;
	    }
	    sort(q+1,q+m+1);

	    int pl=1,pr=0;
	    int id,l,r;
	    for ( int i = 1 ; i <= m ; i++)
	    {
		id = q[i].id;
		r = q[i].r;
		l = q[i].l;

		if (pr<r)
		{
		    for ( int j = pr +1 ; j <= r ; j++) update(j,1);
		}
		else
		{
		    for (int j = r+1 ; j <= pr ; j++) update(j,-1);
		}
		pr = r;

		if (l<pl)
		{
		    for ( int j = l ; j <= pl-1 ; j++) update(j,1);
		}
		else
		{
		    for (int j = pl ; j <= l-1 ; j++) update(j,-1);
		}
		pl = l;

		ans[id] = sum;
	    }
	    
	    for ( int i = 1 ; i <= m ; i++) printf("%I64d\n",ans[i]); //用%lld会WA...也不给个警告
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
