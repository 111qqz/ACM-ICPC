/* ***********************************************
Author :111qqz
Created Time :2015年12月19日 星期六 16时32分59秒
File Name :code/poj/3687.cpp
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
const int N=203;
int n,m;
bool conc[N][N];
bool ok;
int in[N];
int ans[N];
void topo()
{
    priority_queue<int >q;

    for ( int i = 1 ; i <= n ; i++)
	if (in[i]==0) q.push(i);

    int cnt = n ;
    while (!q.empty())
    {
	int v = q.top(); q.pop();
	
	ans[v] = cnt--;

	for ( int i =1 ; i <= n ; i++)
	{
	    if (!conc[i][v]) continue;

	    in[i]--;
	    if (in[i]==0) q.push(i);
	}
    }
//    cout<<"cnt:"<<cnt<<endl;
    if (cnt!=0)
    {
	puts("-1");
    }
    else
    {
	for ( int i =1 ; i <= n-1 ; i++) printf("%d ",ans[i]);
	printf("%d\n",ans[n]);
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
	    scanf("%d %d",&n,&m);
	    ok  = true;
	    ms(conc,false);
	    ms(in,0);
	    while (m--)
	    {
		int x,y;
		scanf("%d %d",&x,&y);
		if (x==y) ok = false;
		if (conc[x][y]) continue;  //重边.
		conc[x][y] = true;
		in[x]++;
	    }
	    if (ok)
	    {
		topo();
	    }
	    else
	    {
		puts("-1");
	    }
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
