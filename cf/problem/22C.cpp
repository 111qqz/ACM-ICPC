/* ***********************************************
Author :111qqz
Created Time :2015年12月30日 星期三 20时36分06秒
File Name :code/cf/problem/22C.cpp
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
int n,m,v;
int a[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n>>m>>v;
	if (m<n-1||m>((n-1)*(n-2)/2+1))
	{
	    puts("-1");
	    return 0;
	}

	for ( int i = 1 ; i <= n ; i++)
	{
	    a[i] = i ;
	    if (i==2)
	    {
		a[i]=v;
	    }
	    if (i==v)
	    {
		a[i]=2;
	    }
	}
	for ( int i = 1 ; i <= n-1 ; i++)
	{
	    printf("%d %d\n",a[i],a[i+1]);
	}
	m-=n-1;

	int cnt =  0 ;
	for ( int i = 2 ; i <= n-2 ; i ++)
	{
	    if (cnt>m) break;
	    for ( int j = i+2 ; j <= n ; j++)
	    {
		cnt++;
		if (cnt>m) break;
		printf("%d %d\n",a[i],a[j]);
	    }
	}


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
