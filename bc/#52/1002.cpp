/*************************************************************************
	> File Name: code/bc/#52/1002.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月22日 星期六 18时52分52秒
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<stack>
#include<cctype>
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define ms(a,x) memset(a,x,sizeof(a))
#define lr dying111qqz
using namespace std;
#define For(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;
const int N=18;
int d[N][N];
int n,m;
bool vis[N];
int ans;

void dfs( int x,int step,int s){
    int cnt = n;
    if (step==cnt){
	if (s<ans)
	    ans = s;
	ans = ans + d[x][1];
	return;
    }
    if (s>ans) return;
    for ( int j = 1 ; j <= cnt ; j++){
	if (vis[j])
	    continue;
	vis[j] = true;
	dfs(j,step+1,s+d[x][j]);
	vis[j] = false;
    }
}
int main()
{
  #ifndef  ONLINE_JUDGE 
    freopen("in.txt","r",stdin);  
  #endif
    int T;
    cin>>T;
    while (T--){
	scanf("%d %d",&n,&m);
	memset(d,0x3f,sizeof(d));
	//cout<<d[1][2]<<" "<<inf<<endl;
	memset(vis,false,sizeof(vis));
	int x,y,w;
	for ( int  i = 0 ; i < m ; i++){
	    scanf("%d%d%d",&x,&y,&w);
	    if (d[x][y]>w){
		d[x][y] = w;
		d[y][x] = w;
	    }
	}
	for ( int k =  1  ; k <= n ; k++){    //floyd
	    for ( int i = 1 ; i <= n ; i++){
		for ( int j = 1 ; j <= n ; j++){
		    if (d[i][j]>d[i][k]+d[k][j]){
			d[i][j] = d[i][k]+d[k][j];
		    }
		}
	    }
	    }
	vis[1] = true;
	 ans = inf;
	dfs(1,1,0);
	printf("%d\n",ans);
    }
  
  
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
