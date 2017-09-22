/* ***********************************************
Author :111qqz
Created Time :2016年04月16日 星期六 12时39分06秒
File Name :code/hust/20160416/1001.cpp
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
const int N=105;
const LL mod =1E9+7;
char maze[N][N];
int n,m;
bool vis[N][N];
LL ny[N*N];
LL fac[N*N];
LL cnt;
LL ksm(LL a,LL b)
{
    LL res = 1LL;
    while (b)
    {
	if (b%2==1) res = (res *a)%mod;
	b = b>>1;
	a = (a*a)%mod;
    }
    return res;
}

void getny()
{
    ms(ny,0);
    fac[0] = 1;
    for ( LL i = 1 ; i <= 10000 ; i++)
    {
	fac[i] = (fac[i-1]*i)%mod;
	ny[i] = ksm(fac[i],mod-2)%mod;
//	cout<<"i:"<<i<<" fac[i]:"<<fac[i]<<endl;
    }
}




void dfs( int x,int y)
{
  //  cout<<"x:"<<x<<" y:"<<y<<"cnt:"<<cnt<<endl;
    vis[x][y] = true;

    for ( int i = 0 ; i < 4 ; i++)
    {
	int nx = x + dx4[i];
	int ny = y + dy4[i];
	if (nx<0||ny<0||nx>=n||ny>=m) continue;
	if (vis[nx][ny]) continue;
	if (maze[nx][ny]=='N') continue;
	dfs(nx,ny);
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
//	freopen("code/in.txt","r",stdin);
  #endif
	getny();
	int T;
	scanf("%d",&T);
	while (T--)
	{
	    scanf("%d %d",&n,&m);
	    for ( int i = 0 ; i < n ; i++) scanf("%s",maze[i]);
	    
	    ms(vis,false);
	     cnt = 0 ;
	    for ( int i = 0 ; i < n ; i++)
	    {
		for  ( int j = 0 ; j < m ; j++)
		{
		    if (maze[i][j]=='N') continue;
		    if (vis[i][j]) continue;
		    dfs(i,j);
		    cnt++;
		}

	    }
	//    cout<<"cnt:"<<cnt<<endl;
	    LL ans = 0 ;

	  //  for ( int i = 1 ; i <= cnt ; i++) cout<<ny[i]<<endl;
	    for ( int i = 1 ; i <= cnt; i +=2)
	    {
		LL tmp;
	        if (i==cnt) tmp=1;
		else
		  tmp = ((fac[cnt]*ny[i])%mod*ny[cnt-i])%mod;
	//	cout<<"tmp:"<<tmp<<endl;
		ans = (ans + tmp)%mod;
	//	cout<<"ans:"<<ans<<endl;
	    }
	    printf("%lld\n",ans);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
