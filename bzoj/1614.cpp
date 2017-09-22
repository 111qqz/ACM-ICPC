/* ***********************************************
Author :111qqz
Created Time :2016年04月02日 星期六 17时50分13秒
File Name :code/bzoj/1614.cpp
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
const int N=1E3+7;
int n,m,k;
int d[N];
bool inq[N];
vector < pi >edge[N];

void init()
{
    for ( int i = 0 ; i <= n ; i++) edge[i].clear();

}

int spfa(int X) //X表示最大花费
{
    queue<int>q;
    ms(inq,false);
    ms(d,0x3f);
    q.push(1);
    inq[1] = true;
    d[1] = 0; // d[i]表示从1到i需要电信公司帮忙建的电话线杆的个数。
    

    while (!q.empty())
    {
	int u = q.front();
	q.pop();
	inq[u] = false;

	int siz = edge[u].size();

	for ( int i = 0 ; i < siz ; i++)
	{
	    int v = edge[u][i].fst;
	    int w = edge[u][i].sec>X?1:0;

	    if (d[v]>d[u]+w)
	    {
		d[v] = d[u] + w;
		if (inq[v]) continue;
		inq[v] = true;
		q.push(v);
	    }
	}
    }
    return d[n];
    
}

void bin()
{
    int l = 0 ;
    int r = 1000000;
    int mid;
    int ans;

    while (l<=r)
    {
	mid = (l+r)/2;
	if (spfa(mid)<=k) ans = mid,r=mid-1;
	else l = mid + 1;
    }
    printf("%d\n",ans);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	init();
	scanf("%d%d%d",&n,&m,&k);
	for ( int i = 1 ; i <= m ; i++)
	{
	    int u,v,w;
	    scanf("%d%d%d",&u,&v,&w);
	    edge[u].push_back(MP(v,w));//以电话线数目为第一关键字，长度为第二关键字。
	    edge[v].push_back(MP(u,w));
	}
	if (spfa(inf)==inf)
	{
	    puts("-1");
	    return 0;
	}
	bin();

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
