/* ***********************************************
Author :111qqz
Created Time :2015年12月17日 星期四 19时29分00秒
File Name :code/hdoj/3342.cpp
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
const int N=1E2+7;

int n,m;

bool v[N][N];
int in[N];

void topo()
{
    queue<int>q;

    for ( int i = 0 ; i < n ; i++)
    {
	if (in[i]==0) q.push(i);
    }

    int cnt = 0 ;
    while (!q.empty())
    {
	cnt++;
	int u = q.front(); q.pop();

	for ( int i = 0 ; i< n ; i++)
	{
	    if (!v[u][i]) continue;

	    in[i]--;
	    if (in[i]==0)
	    {
		q.push(i);
	    }
	}
    }
    if (cnt==n)
    {
	puts("YES");
    }
    else
    {
	puts("NO");
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (~scanf("%d %d",&n,&m)!=EOF)
	{
	    if (n==0) break;
	    ms(v,false);
	    ms(in,0);
	    while (m--)
	    {
		int x,y;
		scanf("%d %d",&x,&y);
		if (v[x][y]) continue ; //重边?
		v[x][y] = true;
		in[y]++;
	    }

	    topo();
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
