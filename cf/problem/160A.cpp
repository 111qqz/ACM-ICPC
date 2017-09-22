/* ***********************************************
Author :111qqz
Created Time :2015年12月06日 星期日 21时04分02秒
File Name :code/cf/problem/160A.cpp
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



using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int N=105;
int n;
int a[N];

bool cmp( int a,int b)
{
    return a>b;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif 
	scanf("%d",&n);
	int sum = 0 ;
	for ( int i = 0 ; i < n ; i++)
	{
	    scanf("%d",&a[i]);
	    sum += a[i];
	}
	sort(a,a+n,cmp);
	int cnt = 0 ;
	for ( int i = 0 ; i < n ; i++)
	{
	    cnt += a[i];
	    if (2*cnt>sum)
	    {
		cout<<i+1<<endl;
		break;
	    }
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
