/* ***********************************************
Author :111qqz
Created Time :2015年12月28日 星期一 22时50分23秒
File Name :code/cf/problem/16C.cpp
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
LL a,b,x,y;
LL ax=0,ay=0;
LL ans = -1;
LL GCD;
LL gcd(LL a,LL b)
{
    if (a<b) return gcd(b,a);
    if (a%b==0) return b;
    return gcd(b,a%b);
   // return b?gcd(b,a%b):a;
}


int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>a>>b>>x>>y;
	GCD = gcd(x,y);
	x /=GCD;
	y /=GCD;
	cout<<x*min(a/x,b/y)<<" "<<y*min(a/x,b/y)<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
