/*************************************************************************
	> File Name: code/2015summer/searching/AA.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月17日 星期五 16时39分25秒
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
using namespace std;
#define REP(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef unsigned long long ULL;
int n,k,ans;
bool vis[15];
char mat[15][15];
void dfs(int cur,int num)
{

    if(num==k)
    {

	  ans++;
	  return;
    }
    for( int i = cur ; i < n ; i++)
	  for(int j = 0 ; j < n ; j++)
		if(mat[i][j]=='#' && !vis[j])
		{

		    vis[j]=true;
		    dfs(i+1,num+1);
		    vis[j]=false;
		}
}
int main()
{

      while(scanf("%d %d%*c",&n,&k)!=EOF)
	{

	    if (n==-1&&k==-1) break;
	    memset(vis,false,sizeof(vis));
	    int i;
	    for(i=0;i<n;i++)
		  scanf("%s",mat[i]);

	    ans=0;
	    dfs(0,0);
	    printf("%d\n",ans);
	}
	return 0;
}
