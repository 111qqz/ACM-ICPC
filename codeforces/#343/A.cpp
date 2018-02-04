/* ***********************************************
Author :111qqz
Created Time :2016年02月21日 星期日 00时30分03秒
File Name :code/cf/#343/A.cpp
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
char maze[N][N];
int x[N],y[N];
int n;

int cal(int x)
{
    return x*(x-1)/2;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n;
	for ( int i = 0 ; i < n ;i++) scanf("%s",maze[i]);

	ms(x,0);
	ms(y,0);
	for ( int i = 0 ; i < n ; i++)
	{
	    for ( int j = 0 ; j < n ;j++)
	    {
		if (maze[i][j]=='C')
		{
		    x[i]++;
		    y[j]++;
		}
	    }
	}
	int ans = 0 ;
	for ( int i = 0 ; i < n ;i++)
	{
	    ans +=cal(x[i]);
	    ans +=cal(y[i]);
	}
	cout<<ans<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
