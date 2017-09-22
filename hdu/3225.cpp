/* ***********************************************
Author :111qqz
Created Time :2016年05月27日 星期五 00时42分16秒
File Name :code/hdu/3225.cpp
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
const int N=305;
bool lie[N][N];
bool hang[N];
int n,m,k;
int cnt;
//vector <int>ans[N]; //不用每个都存，只存第k个就好。。。前面的随便覆盖。。。
int cur[N];
int link[N],tmp[N];
bool vis[N];
bool g[N][N];


bool findgirl( int x,int limit)
{
    if (x<=limit) return false;//找到的匹配位置一定要在当前的后面。
    for ( int i = 1 ; i <= n ; i++)
    {
	if (g[x][i]&&!vis[i])
	{
	    vis[i] = true;
	    if (link[i]==-1||findgirl(link[i],limit))
	    {
		link[i] = x;
		return true;
	    }
	}
    }
    return false;
}
bool hungary()
{
    ms(link,-1);
    
    for ( int i = 1 ; i <= n ; i++)
    {
	ms(vis,false);
	if  (!findgirl(i,0))  return false; //最大匹配的话。。。必须每个都匹配。。。
    }
    return true;
}
bool check ( int pos,int id) //pos表示位置，id表示数字，也就是花的种类。
{
    if (link[id]==pos) return true;
    int kind;
    for ( int i  = 1 ; i <= n ; i++)
    {
	tmp[i] = link[i] ; //tmp[i]数组为了保护link.
	if (link[i]==pos) kind = i ;//kind记录了之前做二分图最大匹配的时候当前位置放的花的种类是哪个。
    }
    int t = link[id];//t表示id种花在做二分图最大匹配之后的位置。
    link[id] = pos; 
    link[kind] = -1; //把id种花放在了pos位置，那么原来在pos位置的花就要重新匹配，所以是未匹配。

    ms(vis,false);
    if (findgirl(t,pos)) return true;
    else for ( int i = 1 ; i <= n ; i++) link[i] = tmp[i];
    return false;


} 
bool dfs( int j) //j 表示第几列。
{
    if (j==n+1)
    {
	cnt++;
	if (cnt==k) return true; //只问了前k个。。所以搜到第k个就好。。。
	return false;
    }

    for ( int i = 1 ; i <= n ; i++)
    {
	if (hang[i]) continue ; //表示这一行已经出现了数字i.
	if (g[j][i]&&check(j,i))
	{
	//    cout<<"j:"<<j<<" i:"<<i<<endl;
	    hang[i] = true;
	    cur[j] = i ;
	    if (dfs(j+1)) return true;
	    hang[i] = false; //回溯。
	}
    }

    return false;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	scanf("%d",&T);
	int cas = 0 ;
	while (T--)
	{
	    ms(lie,false);
	    ms(hang,false);
	    ms(g,false);
	    ms(cur,0);
	    scanf("%d%d%d",&n,&m,&k);
//	    cout<<"n:"<<n<<" m:"<<m<<" k:"<<k<<endl;
	    for ( int i = 1 ; i <= m ; i++)
		for ( int j = 1 ; j <= n ;j++)
		{
		    int x;
		    scanf("%d",&x);
		    lie[j][x] = true;
//		    cout<<"j:"<<j<<" x:"<<x<<endl;

		}

	    for ( int i = 1 ; i <= n ; i++)       //n种花为左集合，n个位置为右集合。
		for ( int j = 1 ; j <= n ; j++)
		    if (!lie[i][j]) g[i][j] = true;

	    if (!hungary()) //必须是完全匹配。。。。
	    {
		
		printf("Case #%d: -1\n",++cas);	
		continue;
	    }

	    cnt = 0;
//	    cout<<"cnt:"<<cnt<<endl;
	    if (!dfs(1))
	    {
		printf("Case #%d: -1\n",++cas);
	    }
	    else
	    {
		printf("Case #%d: ",++cas);

		for ( int i = 1 ; i <= n-1 ; i++)
		    printf("%d ",cur[i]);
		printf("%d\n",cur[n]);
	    }
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
