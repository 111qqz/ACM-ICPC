/*************************************************************************
	> File Name: code/2015summer/sea#2/B.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月28日 星期二 14时59分16秒
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
#define y0 abc111qqz
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define tm crazy111qqz
#define lr dying111qqz
using namespace std;
#define REP(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef unsigned long long ULL;
const int N=5E4+7;
int a[N];
bool vis[N],vis2[N];
int  u,v,n;
int dfs(int x)
{
    int res=0;
    vis2[x]=true;
    int tmp = a[x];
    if (!vis2[tmp])
    {
	  res = dfs(tmp)+1; //当前这个认能传的长度=他传的人能传的长度+1
    }
    vis[x] = true;
    vis2[x] = false;
    return res;

    


}
int main()
{
    int T;
    cin>>T;
    int cas = 0;
    while (T--)
    {
	  memset(vis,false,sizeof(vis));
	  cas++;
	  scanf("%d",&n);
	  for ( int  i = 0 ; i < n;  i++ )
	  {
		scanf("%d %d",&u,&v);
		a[u]=v;
	  }
	  int mx = - 1;
	  int ans;
	  for ( int i = 1 ; i <= n ; i++)
	  {
	//	memset(vis2,false,sizeof(vis2));
		if (vis[i]) continue;   //如果在上一次的dfs中经过了i,那么从i开始传播一定是之前标记i的那次开始传播的子链,一定不优.
		int tmp = dfs(i);
//		cout<<dfs(i,1)<<endl;
		if (tmp>mx)
		{
		    mx = tmp;
		    ans = i;
		}
	  }
	  printf("Case %d: %d\n",cas,ans);
	  
    }
  
	return 0;
}
