/* ***********************************************
Author :111qqz
Created Time :Sat 24 Sep 2016 07:01:51 PM CST
File Name :code/bc/#87/1001.cpp
************************************************ */
i
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
int gcd( int a,int b)
{
    if (a%b==0) return b;
    return gcd(b,a%b);
}
set<int>se;
int a[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	int T;
	cin>>T;
	while (T--)
	{
	    se.clear();
	    scanf("%d",&n);
	    for ( int i = 1;  i <= n ; i++) scanf("%d",&a[i]);
	    for ( int i = 1; i <= n ; i++)
		for ( int j = 1 ; j <= n ; j++)
		    se.insert(gcd(a[i],a[j]));

	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
