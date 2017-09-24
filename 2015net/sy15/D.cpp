/* ***********************************************
Author :111qqz
Created Time :Fri 14 Oct 2016 01:28:44 PM CST
File Name :code/sy15/D.cpp
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
int n,a,b;
int gcd( int a,int b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	int cas = 0 ;
	while (T--)
	{
	    scanf("%d%d%d",&n,&a,&b);
	    int GCD = gcd(a,b);
	    if ((n/GCD)%2==0)
	    {
		printf("Case #%d: Iaka\n",++cas);
	    }
	    else
	    {
		printf("Case #%d: Yuwgna\n",++cas);
	    }
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
