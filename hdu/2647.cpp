/* ***********************************************
Author :111qqz
Created Time :2015年12月09日 星期三 19时27分04秒
File Name :code/hdu/2647.cpp
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
const int N=1E4+1;
int n,m;
set<int>conc[N];
set<int>::iterator it;
int in[N];
int val[N];

void topo()
{
    queue<int>q;
    for ( int i = 1 ; i <= n ; i++)
	if (in[i]==0) q.push(i);

    int cnt = 0 ;
    LL sum = 0 ;
    while (!q.empty())
    {
	int v = q.front();
	q.pop();
	cnt++;
	
	sum = sum + val[v];
	for (it=conc[v].begin() ;it!=conc[v].end() ;it++)
	{
	    if (val[*it]<val[v]+1)
	    {
		val[*it] = val[v] + 1;
	    }
	    in[*it]--;
	    if (in[*it]==0)
	    {
		q.push(*it);
	    }
	}
	//conc[v].clear();
	//	for ( int i = 1 ; i <= n ; i++)
//	{
//	   // if (!conc[v][i]) continue;
//	    if (conc[v].count(i)==0) continue;
//	    in[i]--;
//	    if (in[i]==0) q.push(i);
//	}
    }
    if (cnt<n)
    {
	puts("-1");
    }
    else
    {
	printf("%lld\n",sum);
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (scanf("%d %d",&n,&m)!=EOF)
	{
	    for ( int i = 0 ; i <= n ;i++) val[i] = 888;
	    for ( int i =  0 ; i <= n ; i++) conc[i].clear();
	    ms(in,0);
	    for ( int i = 0 ; i < m ; i++)
	    {
		int x,y;
		scanf("%d %d",&x,&y);
		if (conc[y].count(x)==1) continue;
		conc[y].insert(x);
		in[x]++;
	    }
	    topo();
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
