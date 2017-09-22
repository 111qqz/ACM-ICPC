/* ***********************************************
Author :111qqz
Created Time :Wed 19 Oct 2016 08:07:19 PM CST
File Name :code/hdu/1905.cpp
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
bool check( int n)
{
    if (n<=3) return true;
    for ( int i = 2 ; i * i  <= n ; i++)
	if (n%i==0) return false;

    return true;
}
LL p,a;

LL ksm(LL a,LL b,LL k)
{
    LL res = 1LL;
    while (b>0)
    {
	if (b&1) res = (res * a)%k;
	b = b >> 1;
	a = (a * a)%k;
    }
    return res;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (~scanf("%lld %lld",&p,&a))
	{
	    if (p==0&&a==0) break;
	    if (ksm(a,p,p)==a&&!check(p)) puts("yes");
	    else puts("no");
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
