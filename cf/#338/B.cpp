/* ***********************************************
Author :111qqz
Created Time :2016年01月08日 星期五 21时55分26秒
File Name :code/cf/#338/B.cpp
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
const int N=2E5+7;
int n,m;
vector<int>edge[N];
LL ans;
LL cur;
LL dp[N];


int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n>>m;
	for ( int i = 0 ; i < m ; i ++)
	{
	    int x,y;
	    scanf("%d %d",&x,&y);
	    edge[x].push_back(y);
	    edge[y].push_back(x);
	}

	for ( int i = 1 ; i <= n ; i++)
	{
	    dp[i] = 1;
	    for (int j = 0 ; j < int(edge[i].size()) ; j++)
	    {
		int v = edge[i][j];
		dp[i] = max(dp[i],dp[v]+1);	
	    }
	    ans = max(ans,LL(edge[i].size())*dp[i]);
	}
	cout<<ans<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
