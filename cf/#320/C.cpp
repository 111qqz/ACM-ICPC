/*************************************************************************
	> File Name: code/cf/#320/C.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年11月10日 星期二 16时54分46秒
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<stack>
#include<cctype>
#define fst first              
#define sec second      
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ms(a,x) memset(a,x,sizeof(a))
using namespace std;
const double eps = 1E-10;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
typedef long long LL;
const int inf = 0x3f3f3f3f;
const LL linf =1LL<<60;
LL a,b;
int dblcmp(double d)
{
    return d<-eps?-1:d>eps;
}
LL bin(LL l,LL r)
{
    LL res = -1;
    while (l<=r)
    {
	LL mid = (l+r)>>1;
	 double x=(a+b)*1.0/(2*mid);
	if (dblcmp(x-b)>=0) 
	{
	    l = mid+1;
	    res = mid;
	}
	else
	    r = mid -1;
    }
    return res;
}
int main()
{
  #ifndef  ONLINE_JUDGE 
//   freopen("in.txt","r",stdin);
  #endif

   cin>>a>>b;
   LL k = bin(1LL,linf);
   if (a<b)
    {
	puts("-1");
    }
   else
    {
//	LL k = bin(1LL,linf);
	printf("%.12f\n",(a+b)*1.0/(2.0*k));
    }
  
   
 #ifndef ONLINE_JUDGE  
  #endif
  fclose(stdin);
	return 0;
}
