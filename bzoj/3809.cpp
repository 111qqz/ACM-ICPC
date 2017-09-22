/* ***********************************************
Author :111qqz
Created Time :2016年02月21日 星期日 21时50分34秒
File Name :code/bzoj/3809.cpp
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
int siz = 313; //sqrt(1E5)
int cnt[N];
int a[N];
int pos[N];
struct node
{
    int l,r,x,y
    inr id;

    bool operator <(node b)const
    {
	if (pos[l]==pos[b.l]) return r<b.r;
	return pos[l]<pos[b.l];
    }
}q[N];


int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	scanf("%d %d",&n,&m);
	for ( int i = 1 ; i <= n ; i++)
	{
	    scanf("%d",&a[i]);
	    pos[i] = (i-1)/siz;
	}

	for ( int i = 1 ; i <= m ; i++)
	{
	    scanf("%d%d%d%d",&q[i].l,&q[i].r,&q[i].x,&q[i].y);
	    q[i].id = i ;
	}
	sort(q+1,q+m+1);


	int pl=1,pr=0;
	int id,l,r;
	int x,y;
	int ans = 0 ;
	for ( int i = 1 ; i <= n ; i++)
	{
	    id = q[i].id;
	    l = q[i].l;
	    r = q[i].r;
	    x = q[i].x;
	    y = q[i].y;

	    if (pr<r)
	    {
		for ( int  j = pr +1 ; j <= r ; j++)
		{
		    if (x<=a[j]&&a[j]<=y)
			ans++;
		}
	    }
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
