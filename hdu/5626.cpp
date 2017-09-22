/* ***********************************************
Author :111qqz
Created Time :2016年02月24日 星期三 23时42分15秒
File Name :code/hdu/5626.cpp
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
LL seed;
int n;
int x[N],y[N];

inline LL rand(LL l,LL r)
{
    static LL mo =1E9+7,g=78125;
    return l+((seed*=g)%=mo)%(r-l+1);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
	    cin>>n>>seed;
	    for ( int i = 0 ; i < n ; i++)
	    {
		int xx,yy;
		xx = rand(-1000000000,1000000000);
		yy = rand(-1000000000,1000000000);
		x[i] = xx-yy;
		y[i] = xx+yy;
	    }
	    sort(x,x+n);
	    sort(y,y+n);
	    int ans = -1;
	    ans = max(ans,y[n-1]-y[0]);
	    ans = max(ans,x[n-1]-x[0]);
	    cout<<ans<<endl;
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
