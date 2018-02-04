/* ***********************************************
Author :111qqz
Created Time :2016年03月24日 星期四 14时56分15秒
File Name :code/cf/#344/C.cpp
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
int a[N];
struct node
{
    int x;
    int opt;

    
}p[N];

bool cmp ( int x,int y)
{
    return x>y;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for ( int i = 1 ; i <= n ; i++) cin>>a[i];

	for ( int i = 1 ; i <= m ; i++) cin>>p[i].opt>>p[i].x;

	int lst=0;
	for ( int i = 1 ; i <= n ; i++) 
	{
	    if (p[i].opt==1)
	    {
		if (p[i-1].opt==1)
		{
		    if (p[i-1].x<p[i].x)
		    {
			sort(a+lst+1,a+p[i].x+1);
			lst = p[i].x;
		    }
		}
		else
		{
		    sort(a+1,a+p[i].x+1);
		    lst = p[i].x;
		}
	    }
	    else
	    {
		if (p[i-1].opt==2)
		{
		    if (p[i-1].x<p[i].x)
		    {
			sort(a+lst+1,a+p[i].x+1,cmp);
			lst = p[i].x;
		    }
		}
		else
		{
		    sort(a+1,a+p[i].x+1,cmp);
		    lst = p[i].x;
		}
	    }
	}

	for ( int i = 1 ; i <= n ; i++) cout<<a[i]<<" ";

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
