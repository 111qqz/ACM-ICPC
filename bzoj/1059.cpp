/* ***********************************************
Author :111qqz
Created Time :2017年10月31日 星期二 21时54分23秒
File Name :1059.cpp
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
const int N=200*2+7;
int Link[N];
bool vis[N];
vector<int>edge[N];
int n;

bool Find( int u)
{
    int siz = edge[u].size();
    for ( int i = 0 ; i < siz ; i++)
    {
	int v = edge[u][i];
	if (vis[v]) continue;
	vis[v] = true;
	if (Link[v]==-1||Find(Link[v]))
	{
	    Link[v] = u;
	    return true;
	}
    }
    return false;
}
bool hungry( int n)
{
    int ret = 0;
    ms(Link,-1);
    for ( int i = 1 ; i <= n ; i++)
    {
	ms(vis,false);
	if (Find(i)) ret++;
	else break;
    }
    return ret==n;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	while (T--)
	{
	    cin>>n;
	    for ( int i = 1 ; i <= n ; i++) edge[i].clear();
	    int x;
	    for ( int i = 1 ; i <= n ; i++)
	    {
		for ( int j = 1 ; j <= n ; j++)
		{
		    scanf("%d",&x);
		    if (x==1)
		    {
			edge[i].PB(j);
		    }
		}
	    }
	    if (hungry(n))
		puts("Yes");
	    else puts("No");
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
