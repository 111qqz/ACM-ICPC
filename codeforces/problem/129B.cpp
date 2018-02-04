/* ***********************************************
Author :111qqz
Created Time :2015年12月05日 星期六 10时55分46秒
File Name :code/cf/problem/129B.cpp
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
const int N=105;
int n,m;
vector<int>edge[N];
int deg[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	ms(deg,0);
	scanf("%d %d",&n,&m);
	for ( int i = 0 ; i < m ; i++)
	{
	    int u,v;
	    scanf("%d %d",&u,&v);
	    edge[u].push_back(v);
	    edge[v].push_back(u);
	    deg[u]++;
	    deg[v]++;
	}

	bool flag;
	int ans = 0 ;
	while (1)
	{
	    flag = false;
	    int tmp[N];
	    memcpy(tmp,deg,sizeof(deg));  //因为是先训斥，把当前所有的训斥完再一起T出去。
	    for ( int i = 1 ; i <= n ; i++)
	    {
		if (deg[i]==1)
		{
		    flag = true;
		    tmp[i]--;
		    for ( int j = 0 ; j < edge[i].size(); j++)
		    {
			int to = edge[i][j];
			tmp[to]--; //不需要知道断了和谁的联系，只需要知道连接的数目少了1就好了。
		    }

		}
	    }
	    if (!flag) break;
	    memcpy(deg,tmp,sizeof(tmp));
	    ans++;
	  //  puts("zzzzz");
	}
	printf("%d\n",ans);

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
