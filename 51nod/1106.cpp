/*************************************************************************
	> File Name: code/51nod/1106.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月19日 星期一 18时51分06秒
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
                 
#define yn hez111qqz
#define j1 cute111qqz
#define ms(a,x) memset(a,x,sizeof(a))
using namespace std;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;

bool witness(LL a,LL n)
 {
    LL t,d,x;
 d=1;
 int i=ceil(log(n-1.0)/log(2.0)) - 1;
 for(;i>=0;i--)
 {
 x=d; d=(d*d)%n;
 if(d==1 && x!=1 && x!=n-1) return true;
 if( ((n-1) & (1<<i)) > 0)
 d=(d*a)%n;
 }
 return d==1? false : true;
 }
bool miller_rabin(LL n)
 {
 if(n==2) return true;
 if(n==1 || ((n&1)==0)) return false;
 for(int i=0;i<50;i++){
 LL a=rand()*(n-2)/RAND_MAX +1;
 if(witness(a, n)) return false;
 }
 return true;
 }
int main()
 {
     
 int n,cnt;
 LL a;
 while(scanf("%d",&n)!=EOF)
 {
 cnt=0;
 while(n--)
 {
 scanf("%lld",&a);
 if(miller_rabin(a))
 puts("Yes");
 else 
     puts("No");
 }
// printf("%d\n",cnt);
 }
 return 0;
 }
