/* ***********************************************
Author :111qqz
Created Time :2016年02月18日 星期四 03时03分48秒
File Name :code/hdu/4638.cpp
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
int n,m;
int pos[N];
int a[N];
int ans[N];
int sum;
bool vis[N];

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


void update( int x,int d)
{

   // cout<<"cnt1:"<<cnt1<<" cnt2:"<<cnt2<<endl;
    if (d>0)
    {
	if (vis[a[x]-1]&&vis[a[x]+1])
	    sum--;
	if (!vis[a[x]-1]&&!vis[a[x]+1])
	    sum++;

	vis[a[x]] = true;
    }
    else
    {
	if (vis[a[x]-1]&&vis[a[x]+1]) sum++;
	if (!vis[a[x]-1]&&!vis[a[x]+1])sum--;
	vis[a[x]] = false;
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	while (T--)
	{
	    ms(ans,0);
	    ms(vis,false);
	    scanf("%d %d",&n,&m);
	    int siz = 316; //sqrt(100000)
	    for ( int  i = 1 ; i  <= n ; i++)
	    {
		scanf("%d",&a[i]);
		pos[i] = (i-1)/siz;
	    }
	    
	    for ( int i =1 ; i <= m ; i++)
	    {
		scanf("%d %d",&q[i].l,&q[i].r);
		q[i].id = i;
	    }
	    sort(q+1,q+m+1);
//	    for ( int i = 1 ; i <= m ; i++) cout<<q[i].l<<" "<<q[i].r<<endl;


	    int pl=1,pr=0;
	    int id,l,r;
	    sum = 0 ;
	    for ( int i = 1 ; i <= m ; i++)
	    {
		id = q[i].id;
		l = q[i].l;
		r = q[i].r;

		if (pr<r)
		{
		    for ( int j = pr +1 ; j <= r ; j++) update(j,1);
		}
		else
		{
		    for ( int j = r + 1 ; j <= pr ; j++) update(j,-1);
		}
		pr = r;

		if (l<pl)
		{
		    for ( int j = l ; j <= pl-1 ; j++) update(j,1);
		}
		else
		{
		    for ( int j = pl ; j <= l-1 ; j++) update(j,-1);
		}
		pl = l;

		ans[id]=sum;
	    }
	    
	    for ( int i = 1 ; i  <= m ; i++) printf("%d\n",ans[i]);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
