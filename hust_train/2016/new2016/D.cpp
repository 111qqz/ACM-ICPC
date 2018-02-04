

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
LL n,q;
bool x[N],y[N];
LL sum;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	cin>>n>>q;
	ms(x,false);
	ms(y,false);
	sum = (1+n)*n/2;
	LL rpx=0,rpy=0;
	LL cntx=0,cnty=0;
	while (q--)
	{
	    char opt;
	    LL k;
	    cin>>opt>>k;
	    if (opt=='R')
	    {
		if (x[k])
		{
		    puts("0");
		}
		else
		{
		    x[k] = true;
		    cnty++;
		    rpy += k;
		    cout<<k*n+sum-k*cntx-rpx<<endl;
		}
	    }
	    else
	    {
		if (y[k])
		{
		    puts("0");
		}
		else
		{
		    y[k] = true;
		    cntx++;
		    rpx+=k;
		    cout<<k*n+sum-k*cnty-rpy<<endl;
		}
	    }
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}

