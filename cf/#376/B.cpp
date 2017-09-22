/* ***********************************************
Author :111qqz
Created Time :Sun 16 Oct 2016 05:43:00 PM CST
File Name :code/cf/#376/B.cpp
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
int n;
int a[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n;
	for ( int i = 1 ; i <= n ; i++) 
	{
	    scanf("%d",&a[i]);
	}

	for ( int i = 1 ; i <= n-1 ; i++)
	{
	    int u = a[i];
	    int v = a[i+1];
	    if (u%2==0&&v%2==0) continue;
	    if (u%2==0&&v%2==1)
	    {
		int mn = min(u,v);
		u-=mn;
		v-=mn;
		a[i] = u;
		a[i+1] = v;
		continue;
	    }
	    if (u%2==1&&v%2==0)
	    {
		int mn = min(u,v);
		u-=mn;
		v-=mn;
		a[i] = u;
		a[i+1] = v;
		continue;
	    }
	    if (u%2==1&&v%2==1)
	    {
		int mn = min(u,v);
		v-=mn;
		u-=mn;
		a[i] = u;
		a[i+1] = v;
	    }
	    
	}
	for ( int i = 1 ; i <= n ; i++)
	{
	    if (a[i]%2)
	    {
		puts("NO");
		return 0;
	    }
	}
	puts("YES");
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
