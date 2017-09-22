/* ***********************************************
Author :111qqz
Created Time :2016年11月24日 星期四 08时09分32秒
File Name :code/cf/#381/A.cpp
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
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	LL n,a,b,c;
	cin>>n>>a>>b>>c;
	LL mn = 0 ;
	if (n%4==0)
	{
	    mn = 0 ;
	}
	else if (n%4==1)
	{
	    mn = min(3LL*a,a+b);
	    mn = min(mn,c);
	    mn = min(mn,2*c+a)
	}else if (n%4==2)
	{
	    mn = min(2LL*a,b);
	    mn = min(mn,2*c);
	    mn = min(mn,3LL*c+a);
	    mn = min(mn,c+b+a);
	    mn = min(mn,c+3LL*a);
	}else if (n%4==3)
	{
	    mn = a;
	    mn = min(mn,b+c);
	    mn = min(mn,3LL*c);
	}
	printf("%lld\n",mn);

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
