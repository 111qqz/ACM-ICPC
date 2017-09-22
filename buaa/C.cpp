/* ***********************************************
Author :111qqz
Created Time :2015年12月20日 星期日 15时37分12秒
File Name :code/buaa/C.cpp
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
LL a[N];
LL b[N];
LL fenzi[N],fenmu[N];
int n ;

int dblcmp(double d)
{
    return d<-eps?-1:d>eps;
}

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (scanf("%d",&n)!=EOF){

	    for ( int i = 0 ; i <= n;  i++) scanf("%lld",&a[i]);
	    for ( int i = 0 ; i <= n ; i++) b[i] = 1;
	    fenzi[n] = a[n];
	    fenmu[n] = b[n];
	    for ( int i =  n-1 ; i >= 0 ; i--)
	    {
		fenzi[i] = b[i+1]+a[i]*a[i+1];
		fenmu[i] = a[i+1];

		b[i] = fenmu[i];
		a[i] = fenzi[i];

		 printf("%lld / %lld\n",fenzi[i],fenmu[i]);
	    }
	    double ans1 = fenzi[0]*1.0/fenmu[0];

	    
	 //   cout<<"fenzi:"<<fenzi[0]*1.0<<" fenmi:"<<fenmu[0]*1.0<<endl;
	    cin>>n;
	    for ( int i = 0 ; i <= n;  i++) scanf("%lld",&a[i]);
	    for ( int i = 0 ; i <= n ; i++) b[i] = 1;
	    fenzi[n] = a[n];
	    fenmu[n] = b[n];
	    for ( int i =  n-1 ; i >= 0 ; i--)
	{
	    fenzi[i] = b[i+1]+a[i]*a[i+1];
	    fenmu[i] = a[i+1];

	    b[i] = fenmu[i];
	    a[i] = fenzi[i];

	     printf("%lld / %lld\n",fenzi[i],fenmu[i]);
	}
	    double ans2 = fenzi[0]*1.0/fenmu[0];


	  //  cout<<"fenzi:"<<fenzi[0]*1.0<<" fenmi:"<<fenmu[0]*1.0<<endl;

	   // cout<<ans1<<" "<<ans2<<endl;

	    if (dblcmp(ans1-ans2)>0)
	    {
		puts(">");
	    }
	    if (dblcmp(ans1-ans2)==0)
	    {
		puts("=");
	    }
	    if (dblcmp(ans1-ans2)<0)
	    {
		puts("<");
	    }
	}





	



  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
