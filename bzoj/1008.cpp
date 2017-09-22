/* ***********************************************
Author :111qqz
Created Time :2016年11月28日 星期一 16时23分38秒
File Name :code/bzoj/1008.cpp
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
const LL mod =100003;
LL ksm( LL a,LL b,LL k)
{
    LL res = 1;
    while (b>0)
    {
	if (b&1) res = (res * a)%k;
	b = b >> 1LL;
	a = (a*a)%k;
    }
    return res;
}
LL n,m;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>m>>n;
	LL ans =ksm(m,n,mod)-m%mod*ksm(m-1,n-1,mod)%mod;
	ans %=mod;
	ans +=mod;
	ans %=mod;
	cout<<ans<<endl;


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
