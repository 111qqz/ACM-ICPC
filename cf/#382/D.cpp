/* ***********************************************
Author :111qqz
Created Time :2016年11月29日 星期二 11时36分56秒
File Name :code/cf/#382/D.cpp
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
bool prime( LL x)
{
    for ( LL i = 2 ; i*i <= x ; i++)
    {
	if (x%i==0) return false;
    }
    return true;
}
LL solve( LL x)
{
    if (prime(x)) return 1;
    if (x%2==0) return 2;
    if (x%2==1)
    {
	if (prime(x-2)) return 2;
	else return 3;
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n;
	LL ans = solve(n);
	cout<<ans<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
