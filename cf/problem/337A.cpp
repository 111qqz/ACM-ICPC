/* ***********************************************
Author :111qqz
Created Time :2015年12月06日 星期日 21时13分59秒
File Name :code/problem/337/A.cpp
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
const int N=55;
int n,m;
int f[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	scanf("%d %d",&n,&m);
	for ( int i = 0 ; i < m ; i++) scanf("%d",&f[i]);
	sort(f,f+m);
	int ans = inf;
	for ( int i  = 0 ; i+n-1<m ; i++)
	{
	    ans = min(ans,f[i+n-1]-f[i]);
	}
	cout<<ans<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
