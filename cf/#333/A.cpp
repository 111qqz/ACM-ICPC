/*************************************************************************
	> File Name: code/cf/#333/A.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年11月29日 星期日 10时38分48秒
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
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
typedef long long LL;
const int inf = 0x3f3f3f3f;
const int N=15;
LL n,m,bx,by;
int dblcmp(double d)
{
    return d<-eps?-1:d>eps;
}
LL power( LL a,LL b)
{
    LL res = 1;
    for ( LL i = 1 ; i <= b ;i++)
	res = res * a;
    return res;
}
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("code/in.txt","r",stdin);
  #endif
    cin>>n>>bx;
   LL sumx = 0;
   for ( LL i = n-1 ; i >= 0 ; i--)
    {
	LL x;
	cin>>x;
	sumx+= x*power(bx,i);
    }
   LL sumy = 0;
   cin>>m>>by;
   for ( LL i = m-1 ; i >= 0 ; i--)
    {
	LL x;
	cin>>x;
	sumy+=x*power(by,i);
    }
 //  cout<<"x:"<<sumx<<" y:"<<sumy<<endl;
    LL ret = sumx-sumy;
   if (ret<0)
    {
	puts("<");
    }
   if (ret==0)
    {
	puts("=");
    }
   if (ret>0)
    {
	puts(">");
    }
  
   
 #ifndef ONLINE_JUDGE  
  #endif
  fclose(stdin);
	return 0;
}
