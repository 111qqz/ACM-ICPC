/* ***********************************************
Author :111qqz
Created Time :2015年12月09日 星期三 21时33分28秒
File Name :code/cf/problem/574B.cpp
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
const int N=4E3+7;
int n ,m;
vector<int>edge[N];
int ans;

bool conc[N][N];
int d[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	cin>>n>>m;
	ms(conc,false);
	ms(d,0);
	for ( int i = 0 ; i < m ;i++)
	{
	    int x,y;
	    cin>>x>>y;
	    conc[x][y] = true;
	    conc[y][x] = true;
	    d[x]++;
	    d[y]++;
	}
	int ans = inf;
	for ( int i = 1 ; i <= n ; i++)
	    for ( int j = 1 ; j <= n ;j++)
		if (conc[i][j]&&d[i]+d[j]<ans)
		{
		    for ( int k = 1 ; k <= n ; k++)
			if (conc[i][k]&&conc[j][k])
			    ans = min(ans,d[i]+d[j]+d[k]);
		}
	if (ans!=inf)
	cout<<ans-6<<endl;
	else puts("-1");

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
