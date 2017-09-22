/* ***********************************************
Author :111qqz
Created Time :2015年12月05日 星期六 10时17分01秒
File Name :580C.cpp
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



using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int N=1E5+7;

int m,n;
bool vis[N];
vector<int>edge[N];
int hascat[N];
int ans;

void dfs( int cur,int num)
{
    vis[cur] = true;
    if (hascat[cur])
	num++;
    else num = 0 ;
    
 //   cout<<"cur:"<<cur<<" num:"<<num<<endl;

    if (num>m) return;

    int leafnum = 0;
    for ( int i = 0 ; i <edge[cur].size(); i++ )
    {
	int v = edge[cur][i];
//	cout<<"cur:"<<cur<<" v:"<<v<<endl;
	if (!vis[v])
	{
	    dfs(v,num);
	    leafnum++;
	}
    }
    if (leafnum==0) ans++;

}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
	#endif
    ms(vis,false);
    ms(hascat,0);
    scanf("%d %d",&n,&m);
    for ( int i =  1 ; i <= n ; i++) scanf("%d",&hascat[i]);
    for ( int i = 1  ; i <= n-1 ; i++)
    {
	int u,v;
	scanf("%d %d",&u,&v);
	edge[u].push_back(v);
	edge[v].push_back(u);
    }

    ans = 0 ;
    dfs(1,0);
    printf("%d\n",ans);

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
