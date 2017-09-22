/* ***********************************************
Author :111qqz
Created Time :2016年05月28日 星期六 17时11分49秒
File Name :code/hust/2016/I.cpp
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
const int N=1E3+7;
bool conc[N][N];
int n,m,p;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	while (scanf("%d %d %d",&n,&m,&p)!=EOF)
	{
	    ms(conc,false);
	    for ( int i = 1 ; i <= m ; i++)
	    {
		int u,v;
		scanf("%d %d",&u,&v);
		conc[u][v] = true;
	    }

	    for ( int i = 1; i <= n ; i++)
	    {
		conc[i][p] = false;
		conc[p][i] = false;
	    }

	    int ans = 0 ;
	    for ( int i = 1 ; i <= n ; i++)
		for ( int j = 1 ; j <= n ; j++) if (conc[i][j]) cout<<"i:"<<i<<" J:"<<j<<endl;
	    for ( int i = 1 ; i <= n ; i++)
	    {
		for ( int j = 1 ; j <= n ; j++)
		{
		    if (i==j) continue;
		    if (!conc[i][j]&&!conc[j][i])
		    {
			ans++;
			cout<<i<<" "<<j<<endl;
		    }
		}
	    }
	    printf("%d\n",ans);
	}





  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
