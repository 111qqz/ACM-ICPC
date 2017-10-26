/* ***********************************************
Author :111qqz
Created Time :2017年10月26日 星期四 12时53分06秒
File Name :A.cpp
************************************************ */

#include <bits/stdc++.h>
#define PB push_back
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
const int N=1005;
const int M=1E4+7;
int n,m,a,b;
vector <int>edge[N];
int col[N];
set<int>se;
bool dfs( int u,int x)
{
    col[u] = x;
    int siz = edge[u].size();
    for ( int i = 0 ;i  < siz ; i++)
    {
	int v  = edge[u][i];
	if (col[v]==1-x) continue;
	if (col[v]==x) return false;
	if (!dfs(v,1-x)) return false;
    }
    return true;
}
void pr(int a[])
{
    for ( int i = 1 ; i <= n ; i++) printf("%d%c",a[i],i==n?'\n':' ');
}
vector <int> A,B;
bool appear[N];
bool ran[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	while (~scanf("%d %d %d %d",&n,&m,&a,&b))
	{

	    bool die = false;
	    ms(col,-1);
	    A.clear();
	    B.clear();
	    ms(appear,false);
	    ms(ran,false);
	    for ( int i = 0 ; i <= n ; i++) edge[i].clear();
	    for ( int i = 1 ; i <= m ; i++)
	    {
		int u,v;
		scanf("%d %d",&u,&v);
		appear[u]=appear[v] = true;
		edge[u].PB(v);
		edge[v].PB(u);
	    }
	    for ( int i = 1 ; i <= a ; i++)
	    {
		int x;
		scanf("%d",&x);
		appear[x] = true;
		A.PB(x);
		col[x] = 0 ;  //0 for good player
	    }
	    for ( int i =1 ; i <= b ; i++)
	    {
		int x;
		scanf("%d",&x);
		appear[x] = true;
		B.PB(x);
		col[x] = 1;
	    }

	    for ( int i = 1 ; i <= n ; i++) if (!appear[i])
	    {
		die = true;
		break;
	    }
	    if (die)
	    {
		puts("NO");
		continue;
	    }

	    //可能有多个联通块
	    //
	    int siz = A.size();
	    for ( int i = 0 ; i < siz; i++)
	    {
		int v = A[i];
		if (!dfs(v,0))
		{
		    die = true;
		    break;
		}
	    }
	    if (die)
	    {
		puts("NO");
		continue;
	    }
	    
	    siz = B.size();
	    for ( int i = 0 ; i < siz; i++)
	    {
		int v = B[i];
		if (!dfs(v,1))
		{
		    die = true;
		    break;
		}
	    }
	    if (die)
	    {
		puts("NO");
		continue;
	    }

	    for ( int i = 1 ; i <= n ; i++ )
	    {
		if (col[i]==-1)
		{
		    if (!dfs(i,0))
		    {
			die = true;
			break;
		    }
		}
	    }

	    if (die)
	    {
		puts("NO");
		continue;
	    }
	    puts("YES");
	}


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
