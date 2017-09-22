/* ***********************************************
Author :111qqz
Created Time :2016年02月29日 星期一 18时39分23秒
File Name :code/hdu/4336.cpp
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
const int N=25;
double p[N];
int n;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (~scanf("%d",&n))
	{
	    ms(p,0);
	    double ans = 0 ;
	    for ( int i = 0 ; i < n ; i++) scanf("%lf",&p[i]);

	    for ( int msk = 1 ; msk <(1<<n) ; msk++)
	    {
		double res = 0.0;
		int bits  = 0;
		for ( int i = 0 ; i < n ; i++)
		{
		    cout<<"msk:"<<msk<<" "<<(1<<i)<<endl;
		    if (msk&(1<<i))
		    {
			bits++;
			res +=p[i];
		    }
		}
		if (bits%2==1)
		{
		    ans += 1.0/res;
		}
		else
		{
		    ans -= 1.0/res;
		}
	    }

	    printf("%.8f\n",ans);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
