/* ***********************************************
Author :111qqz
Created Time :2015年12月15日 星期二 19时47分47秒
File Name :code/cf/problem/474B.cpp
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
const int N=1E6+7;
int n,m;
int ans[N];


int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	ms(ans,-1);
	cin>>n;
	int cur = 1;
	for ( int i = 0 ; i < n ; i++)
	{
	    int x;
	    scanf("%d",&x);
	    for ( int j = cur ; j <= cur+x-1 ; j++)
		ans[j] = i+1;
	    cur +=x;
	}
	cin>>m;
	while (m--)
	{
	    int x;
	    scanf("%d",&x);
	    printf("%d\n",ans[x]);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
