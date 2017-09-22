/* ***********************************************
Author :111qqz
Created Time :Sat 29 Oct 2016 01:04:47 PM CST
File Name :code/1003.cpp
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
const int N=1E5+7;
int n;
double a[N];
int dblcmp( double d)
{
    return d<-eps?-1:d>eps;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
//	freopen("code/in.txt","r",stdin);
  #endif

	int T;
	cin>>T;
	int cas =0 ;
	while (T--)
	{
	    scanf("%d",&n);
	    a[0] = 0 ;
	    for ( int i = 1 ;i  <= n ; i++) scanf("%lf",&a[i]);
	    printf("Case #%d: ",++cas);
	    LL ans = 0;
	    //int mn = inf;
	    double ave = 2000000000;
	//    cout<<"n:"<<n<<endl;
	    //for ( int i = 1 ; i<= n ; i++) cout<<"a[i]:"<<a[i]<<endl;
	    for ( int i = n ; i >=1 ; i--)
	    {
		//mn = min(mn,a[i]-a[i-1]);
		double dis = a[i]-a[i-1];
		int res = ceil(dis*1.0/ave);
		if (dblcmp(dis/res-ave)<0)
		    ave = dis/res;
		//ave = min(dis*1.0/res,ave);
		ans = ans + res;

	//	cout<<"i:"<<i<<"a[i]:"<<a[i]<<" a[i-1]:"<<a[i-1]<<" dis:"<<dis<<" res:"<<res<<" ave:"<<ave<<" ans:"<<ans<<endl;
	    }
	    printf("%lld\n",ans);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}

