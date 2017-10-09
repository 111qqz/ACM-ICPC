/* ***********************************************
Author :111qqz
Created Time :2017年10月09日 星期一 16时17分24秒
File Name :I.cpp
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
#define PB push_back
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
const int N=5E4+7;
const LL mod = 1000000007LL;
LL k;
char st[N];
int n;
LL sum;
LL kth[15];
LL ksm (LL a,LL b)
{
    LL res = 1LL;
    while (b>0)
    {
	if (b&1) res = (res * a)%mod;
	b = b >> 1LL;
	a = (a * a)%mod;
    }
    return res;
}
void init()
{
    ms(kth,0);  //预处理10个数字的k次方
    for ( LL i = 0 ; i <= 9 ; i++)
	kth[i] = ksm(i,k);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
//	freopen("./in.txt","r",stdin);
  #endif
    int T;
    cin>>T;
    while (T--)
    {
	sum = 0 ;
	scanf("%d %lld",&n,&k);
	scanf("%s",st);
	init();
	for ( int i = 0 ; i < n ; i++)
	{
	    LL val = st[i]-'0';
	    LL tmp = (1LL*(i+1)*kth[val])%mod;
	    sum = (sum + tmp)%mod;
	    printf("%lld%c",sum,i==n-1?'\n':' ');
	}
    }



  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
