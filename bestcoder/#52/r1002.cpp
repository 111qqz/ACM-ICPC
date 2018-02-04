/*************************************************************************
	> File Name: code/bc/#52/r1002.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月22日 星期六 20时03分35秒
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
int g[N][N],visit[N],n,count=1,sum=0;
int ans;
int m;
void dfs(int i,int count,int sum)
{
    int p;
    if(sum>=ans)return;
    if(count==n)
    {
        sum+=g[i][1];
        ans=ans>sum?sum:ans;
        return;
    }
    for(p=1;p<=n;p++)
    {
        if(!visit[p]&&p!=i)
        {
            visit[i]=1;
            dfs(p,count+1,sum+g[i][p]);
            visit[i]=0;
        }
    }
}
int main()
{
    int min;
    int T;
    cin>>T;
    while (T--){
	ans =  inf;
	memset(g,0x3f,sizeof(g));
	scanf("%d%d",&n,&m);
	int x,y,w;
	for ( int i = 1 ; i <= m ; i++){
	    scanf("%d %d %d",&x,&y,&w);
	    if (g[x][y]>w){
		g[x][y] = w;
		g[y][x] = w;
	    }
	}
	for ( int k = 1 ; k <= n ; k++){
	    for ( int  i = 1 ; i <= n ; i++){
		for ( int j = 1 ; j <= n ; j++){
		    if (g[i][j]>g[i][k]+g[k][j]){
			g[i][j] = g[i][k] + g[k][j];
		    }
		}
	    }
	}
	
 //   for ( int i  = 1 ; i <= n ; i++){
//	for ( int j = 1 ; j <= n ; j++){
//	    cout<<g[i][j]<<" ";
//	}
//	cout<<endl;
  //  }
    for(int i=1;i<=n;i++)
    {
        min=inf;
        for(int j=1;j<=n;j++)
        {
            if(j!=i&&min>g[i][j])min=g[i][j];
        }
        if(min!=inf)
        {
            sum+=min;
            for(int j=1;j<=n;j++)if(j!=i)g[i][j]-=min;
        }
    }
    for(int j=1;j<=n;j++)
    {
	    min=inf;
        for(int i=1;i<=n;i++)if(i!=j&&min>g[i][j])min=g[i][j];
        if(min!=inf)
        {
            sum+=min;
            for(int i=1;i<=n;i++)if(i!=j)g[i][j]-=min;
        }
    }
    visit[1]=1;
    dfs(1,1,sum);
    printf("%d\n",ans);
    }
    return 0;
}
