/* ***********************************************
Author :111qqz
Created Time :2016年04月04日 星期一 01时36分31秒
File Name :code/bzoj/1620.cpp
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
const int N=1E3+7;
pi a[N];
int n;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n;
	for ( int i = 1 ; i <= n ; i++)
	{
	    int x,y;
	    cin>>x>>y;
	    a[i]=make_pair(y,x);
	}

	sort(a+1,a+n+1);
	int sum = 0 ;
	int ans = inf;
	for ( int i = 1 ; i <= n ; i++)
	{
	    sum += a[i].sec;
	    ans = min(ans,a[i].fst-sum);
	}
	if (ans<0) ans=-1;
	cout<<ans<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
