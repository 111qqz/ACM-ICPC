/* ***********************************************
Author :111qqz
Created Time :2015年12月16日 星期三 16时50分56秒
File Name :code/cf/problem/496A.cpp
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
const  int N=1E2+7;
 int n ;
 int h[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	cin>>n;
	for ( int i =  1; i  <= n ; i++) cin>>h[i];

	int ans = inf;
	//暴力枚举删掉的点吧...
	for ( int i = 2 ; i <= n-1 ; i++)
	{
	    int mx = -1;
	    for ( int j = 1 ; j <= n ; j++)
	    {
		if (j+1==i) mx = max(h[j+2]-h[j],mx);
			    else mx = max(h[j+1]-h[j],mx);
	    }
	    ans = min(ans,mx);
	}
	cout<<ans<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
