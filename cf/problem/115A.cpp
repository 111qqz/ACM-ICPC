/* ***********************************************
Author :111qqz
Created Time :2015年12月04日 星期五 21时31分38秒
File Name :code/cf/problem/115A.cpp
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

const int N=2E3+7;
int p[N];
int f[N];


int n;
int ans;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	scanf("%d",&n);
	for (  int i = 1 ; i <= n ; i++) scanf("%d",&p[i]);
	ans = -1;
	for ( int i = 1 ; i <= n ; i++)
	{
	    int depth = 1;
	    int id = i;
	    while (p[id]!=-1)
	    {
		depth++;
		id = p[id];
	    }
	    if (depth>ans) ans = depth; 
	}
	printf("%d\n",ans);


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
