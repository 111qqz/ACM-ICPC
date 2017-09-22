/* ***********************************************
Author :111qqz
Created Time :2015年12月04日 星期五 16时50分13秒
File Name :code/cf/problem/500A.cpp
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

const int N=3E4+7;
int a[N];
int n;
int t;

void dfs(int x)
{
   // cout<<"x:"<<x<<endl;
    if (x==t)
    {
	puts("YES");
	return ;
    }
    if (a[x]==0)
    {
	puts("NO");
	return ;
    }
    dfs(x+a[x]);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	scanf("%d",&n);
	scanf("%d",&t);
	a[n] = 0;
	for ( int i = 1 ;  i<= n-1 ; i++) scanf("%d",&a[i]);
	dfs(1);


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
