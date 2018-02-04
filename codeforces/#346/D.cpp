/* ***********************************************
Author :111qqz
Created Time :2016年03月31日 星期四 01时51分56秒
File Name :code/cf/#346/D.cpp
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
const int N=1005;
int n;
int dir[N];

struct node
{
    int x,y;
    int getdir( node b)
    {
	if (x==b.x)
	{
	    if (y>b.y) return 0;
	    else return 2;
	}
	else
	{
	    if (x>b.x) return 1;
	    else return 3;
	}
    }
}p[N];

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n;
	ms(dir,-1);
	for ( int i = 1 ; i <= n+1 ; i++) cin>>p[i].x>>p[i].y;
	for ( int i = 1 ; i <= n ; i++)
	{
	     dir[i] = p[i].getdir(p[i+1]);
	}

	int ans = 0 ;
	for ( int i = 1 ; i <= n-1 ; i++)
	{
	    if (dir[i]==(dir[i+1]+1)%4) ans++;
	}
	cout<<ans<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
