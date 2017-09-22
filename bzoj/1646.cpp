/* ***********************************************
Author :111qqz
Created Time :2016年04月10日 星期日 21时00分01秒
File Name :code/bzoj/1646.cpp
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
int n,k;
bool vis[N];
int d[N];
void bfs()
{
    ms(d,-1);
    queue<int>q;
    q.push(n);
    vis[n] = true;
    d[n] = 0 ;

    while (!q.empty())
    {
	int px = q.front () ; q.pop();
	if (px==k)
	{
	    return ;
	}
	int nxt[3];
	nxt[0] = px-1;
	nxt[1] = px+1;
	nxt[2] = 2*px;
	for ( int i = 0 ; i < 3 ; i++)
	{
	    if (nxt[i]>=0&&nxt[i]<=100000&&!vis[nxt[i]])
	    {
		q.push(nxt[i]);
		vis[nxt[i]] = true;
		d[nxt[i]] = d[px] + 1;
	    }
	}
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	
	scanf("%d %d",&n,&k);
	bfs();
	printf("%d\n",d[k]);

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
