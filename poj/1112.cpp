/* ***********************************************
Author :111qqz
Created Time :2016年09月01日 星期四 00时26分50秒
File Name :code/poj/1112.cpp
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
bool know[N][N];
int col[N];
int n;
vector<int>edge[N];
vector<int>ans1,ans2,ans0;
bool dfs(int u,int color)
{
    col[u] = color;
    int siz = edge[u].size();
    for ( int i = 0 ; i < siz ; i++)
    {	
	int v = edge[u][i];
	if (col[v]==1-color) continue;
	if (col[v]==color) return false;
	dfs(v,1-color);
    }
    return true;
}

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	 scanf("%d",&n);

	    ms(col,-1);
	    for ( int i = 0 ; i <= n ; i++) edge[i].clear();
	    ans1.clear();
	    ans2.clear();
	    ans0.clear();
	    for ( int i = 1 ; i <= n ; i++)
	    {
		int x;
		while (~scanf("%d",&x)&&x!=0)
		{
		    know[i][x] = true;
		}
	    }

	    for ( int i = 1 ; i <= n ; i++)
		for ( int j = i+1 ; j <= n ; j++)
		{
		    if (!know[i][j]||!know[j][i]) edge[i].push_back(j),edge[j].push_back(i);
		}
	    
/*	    for ( int i = 1 ; i <= n ; i++)
	    {
		cout<<i<<" ";
		int siz = edge[i].size();
		for ( int j = 0 ;j < siz; j++)
		    cout<<edge[i][j]<<" ";
		cout<<endl;
	    }  */
	    if(!dfs(1,0))
		puts("No solution");
	    else 
	    {
//		for ( int i = 1 ; i <= n ; i++) cout<<"col[i]:"<<col[i]<<endl;
		for ( int i = 1 ; i <= n ; i++) if (col[i]==1) ans1.push_back(i);else if(col[i]==0 )ans2.push_back(i); else ans0.push_back(i);
		int siz1 = ans1.size();
		int siz2 = ans2.size();
		int siz0 = ans0.size();
		while (siz0>0)
		{
		    if (siz1<siz2)
		    {
			siz1++;
			ans1.push_back(ans0[siz0-1]);
			siz0--;
		    }
		    else
		    {
			siz2++;
			ans2.push_back(ans0[siz0-1]);
			siz0--;
		    }
		}
		printf("%d",siz1);
		for ( int i = 0 ; i < siz1 ; i++)
		    printf(" %d",ans1[i]);
		printf("\n");
		printf("%d",siz2);
		for ( int i = 0 ; i < siz2 ; i++)
		    printf(" %d",ans2[i]);
		printf("\n");
	    }




  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
