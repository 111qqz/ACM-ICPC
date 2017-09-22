/* ***********************************************
Author :111qqz
Created Time :2015年12月29日 星期二 13时32分52秒
File Name :code/cf/problem/9/C.cpp
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
LL n;

LL cal( LL x)
{
    return (1LL<<x)-1;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
//	freopen("code/in.txt","r",stdin);
  #endif

	cin>>n;
	LL p = 1;
	LL num;
	for ( int i = 2 ; i <= 11 ; i++)
	{
	    p =p*10;
	    if (p>n)
	    {
		num = i-1;
		break;
	    }
	}
	p/=10;
    cout<<"p:"<<p<<endl;
    
    LL ans  = 0;
    LL x;
    while (n)
    {
	x = n/p;
	if (x>=2)
	{
	    ans+=cal(num);
	    break;
	}
	if (x==1)
	{
	    ans+=cal(num-1)+1;
	}
	num--;
	n = n % p;
	p/=10;
    }
    cout<<ans<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
