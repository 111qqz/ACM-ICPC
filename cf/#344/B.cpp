/* ***********************************************
Author :111qqz
Created Time :2016年03月24日 星期四 14时56分10秒
File Name :code/cf/#344/B.cpp
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
const int N=1E5+7;
int ans[5005][5005];
int n,m,k;
struct node
{
    int col;
    int tim;
}cx[5005],cy[5006];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	ios::sync_with_stdio(false);
	ms(cx,-1);
	ms(cy,-1);

	cin>>n>>m>>k;
	while (k--)
	{
	    int opt,x,a;
	    cin>>opt;
	    cin>>x;
	    cin>>a;
	    if (opt==1)
	    {
		cx[x].col = a;
		cx[x].tim = k;
	    }
	    else
	    {
		cy[x].col = a;
		cy[x].tim = k ;
	    }
	}

	ms(ans,0);
	for ( int i = 1 ; i<= n ; i++)
	{
	    for ( int j = 1 ; j <= m ; j++)
	    {
		if (cx[i].col==-1&&cy[j].col==-1) continue;
		if (cx[i].col==-1)
		{
		    ans[i][j]=cy[j].col;
		    continue;
		}
		if (cy[j].col==-1)
		{
		    ans[i][j] = cx[i].col;
		    continue;
		}
		if (cx[i].tim<cy[j].tim)
		{
		    ans[i][j] = cx[i].col;
		}
		else
		{
		    ans[i][j] = cy[j].col;
		}
		
	    }
	}

	for ( int i = 1 ; i <= n ; i ++)
	{
	    for ( int j = 1 ; j <= m ; j++)
	    {
		printf("%d ",ans[i][j]);
	    }
	    printf("\n");
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
