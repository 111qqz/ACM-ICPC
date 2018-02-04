/* ***********************************************
Author :111qqz
Created Time :2016年04月22日 星期五 20时13分27秒
File Name :code/bc/#81/1004.cpp
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
const int N=1E6+7;
LL n;
LL a[N];
LL ksm( LL a,LL b)
{
    LL res = 1LL;
    while (b>0)
    {
	if (b%2==1) res = (res*a)%MOD;
	b /=2;
	a = (a*a)%MOD;
    }
    return res;
}
void init()
{
    a[1] = 1;
    a[2] = 2;
    a[3] = 9;
    for ( LL i = 3 ; i <= 1000000 ; i++)
    a[i]=(((2*i+1)*a[i-1]+3*(i-1)*a[i-2])%MOD*ksm(i+2,MOD-2))%MOD;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	init();
	int T;
	cin>>T;
	while (T--)
	{
	    scanf("%I64d",&n);
	    printf("%I64d\n",a[n]);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
