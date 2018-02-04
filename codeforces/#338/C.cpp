/* ***********************************************
Author :111qqz
Created Time :2016年01月08日 星期五 21时55分35秒
File Name :code/cf/#338/C.cpp
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
const LL MOD =1E9+7;
const int N=2E5+7;
LL n;
LL p[N];
LL ans;
set<LL>se;
LL quickpow(LL a,LL b,LL k)
{
    LL res = 1LL;
    while (b>0LL)
    {
	if (b&1LL)
	{
	    res = (res*a)%k;
	}
	b = b >> 1LL;
	a = (a*a)%k;
    }
    return res;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n;
	LL x;
	ans = 1 ;
	LL q = 1LL<<(n-1);
//	cout<<"q:"<<q<<endl;
	se.clear();
	for ( int i = 0 ; i < n ; i++)
	{
	    cin>>p[i];
	    se.insert(p[i]);
	}
	LL siz = se.size();
	if (siz==1)
	{
	    ans = quickpow(p[0],(1+n)*n/2,MOD);
	    cout<<ans<<endl;
	    return 0;
	}
//	cout<<"siz:"<<siz<<endl;
	LL kk = n - siz;
//	cout<<"kk:"<<kk<<endl;
	LL xy;
	if (kk>0)
	{
	    
	     xy = 1LL<<(kk);
	    
	}
	else xy  = 0;
//	cout<<"xy:"<<xy<<endl;
	for ( int i = 0 ; i  < n ; i++)
	{
	    //scanf("%I64d",&
	    ans=ans*quickpow(p[i],q-xy,MOD);
	   ans = ans % MOD;
	}
	cout<<ans<<endl;


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
