/* ***********************************************
Author :111qqz
Created Time :2015年12月08日 星期二 20时43分24秒
File Name :code/hdu/1285.cpp
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
const int N=5E2+7;
int n,m;
int in[N];
bool con[N][N];
priority_queue<int,vector<int>,greater<int> > q;
void toporder()
{
    for ( int i = 1 ; i <= n ; i++)
	if (in[i]==0) q.push(i);
    
    int c = 1;
    while (!q.empty())
    {
	int v =q.top();
	q.pop();
	if (c!=n)
	{
	    printf("%d ",v);
	    c++;
	}
	else
	    printf("%d\n",v);
	for ( int i = 1 ; i <= n ; i++)
	{
	    if (!con[v][i])
		continue;
	    in[i]--;
	    if (!in[i])
		q.push(i);
	}
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (scanf("%d %d",&n,&m)!=EOF)
	{
	    ms(con,false);
	    for ( int i = 0 ; i < m ; i++)
	    {
		int x,y;
		scanf("%d %d",&x,&y);
	//	if (con[x][y])
	//	    continue;
		con[x][y] = true;
		in[y]++;

	    }
	    toporder();
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
