/* ***********************************************
Author :111qqz
Created Time :2016年03月21日 星期一 20时21分20秒
File Name :code/class/algorithm/line2.cpp
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
struct  node
{
    int val;
    int prex,prey;
}dp[3][15];
int t[3][15],a[3][15];
int e1,e2,x1,x2;


void print(int i,int j)
{
    if (dp[i][j].prex==-1&&dp[i][j].prey==-1) return ;
    else
    {
	print(dp[i][j].prex,dp[i][j].prey);
	printf("%d %d\n",i,j);
    }
}
node dfs( int k,int pos)
{
    if (dp[k][pos].val!=9999) return dp[k][pos];
    node tmp;
    tmp .val = a[k][pos]+(pos==0?0:min(dfs(1,pos-1)+(k==1?0:t[2][pos-1]),dfs(2,pos-1)+(k==2?0:t[1][pos-1])));
    tmp .prex = k;
    tmp. prey = pos;
    return tmp;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	cin>>e1>>e2>>x1>>x2;
	ms(a,0);
	ms(t,0);
	for ( int i = 1 ;i  <= 15 ; i++)
	{
	    dp[1][i].val=dp[2][i].val=9999;
	}
	dp[1][5].prex=-1;
	dp[1][5].prey=-1;
	dp[2][5].prex=-1;
	dp[2][5].prey=-1;

	for ( int i = 1 ; i <= 5 ; i++) cin>>a[1][i];
	for ( int i =1 ; i <= 5 ; i++) cin>>a[2][i];
	for ( int i =1 ; i <= 4 ; i++) cin>>t[1][i];
	for ( int i = 1 ;i  <= 4 ; i++) cin>>t[2][i];

	a[1][5]+=x1;
	a[2][5]+=x2;
	a[1][1]+=e1;
	a[2][1]+=e2;
	
	node res;
	res = dfs(0,5);
	
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
