/*************************************************************************
	> File Name: code/cf/#328/C.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年11月01日 星期日 16时00分45秒
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
                 
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ms(a,x) memset(a,x,sizeof(a))
using namespace std;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;
LL t,w,b;

LL gcd(LL a,LL b)
{
//    if (a<b) return gcd(b,a);
    if (a%b==0) return b;
    return gcd(b,a%b);
}

void solve()
{
    LL res;
    if (w==b)
    {
	puts("1/1");
	return;
    }
    LL GCD = gcd(w,b);
  //  cout<<"GCD:"<<GCD<<endl;
    res = t /w/b*GCD;
 //   cout<<"res:"<<res<<endl;
    res = res*b+(b-1);
//    cout<<"res:"<<res<<endl;
    LL tmp = res /GCD*w*b;
    cout<<"tmp:"<<tmp<<endl;
    
    LL p,q,gc;
    p = res;
    q = t;
    gc = gcd(q,p);
    p /=gc;
    q/=gc;
    cout<<p<<"/"<<q<<endl;




}
int main()
{
  #ifndef  ONLINE_JUDGE 
  // freopen("in.txt","r",stdin);
  #endif

   scanf("%lld %lld %lld",&t,&w,&b);
   if (w<b) swap(w,b);
   solve();
  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
