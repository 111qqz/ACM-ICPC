/* ***********************************************
Author :111qqz
Created Time :2016年02月21日 星期日 01时14分43秒
File Name :code/cf/#343/BBB.cpp
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
const int N=5E3+7;
int n;
int p[4][N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n;
	ms(p,0);
	for ( int i = 1 ; i <= n ; i++)
	{
	    char gen[2];
	    scanf("%s",gen);
	    int x,y;
	    cin>>x>>y;
	    if (gen[0]=='M')
	    {
		p[0][x]++;
		p[0][y+1]--;
	    }
	    else
	    {
		p[1][x]++;
		p[1][y+1]--;
	    }
	}
	for ( int i = 1 ; i <= 366 ; i++) 
	{
	    p[0][i]+=p[0][i-1];
	    p[1][i]+=p[1][i-1];
	}

	int ans = 0 ;
	for ( int i = 1 ; i <=366 ; i++)
	{
	    ans = max(ans,min(p[0][i],p[1][i])*2);
	}
	cout<<ans<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
