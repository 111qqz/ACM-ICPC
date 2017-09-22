/* ***********************************************
Author :111qqz
Created Time :2016年01月29日 星期五 16时15分14秒
File Name :code/uva/10790.cpp
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
LL a,b ;
LL ans;

LL cal( LL x)
{
    return x*(x-1)/2;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	
	int cas = 0  ;
	while (scanf("%lld %lld",&a,&b)!=EOF)
	{
	    if (a==0&&b==0) break;

	    ans = cal(a)*cal(b);
	    printf("Case %d: %lld\n",++cas,ans);

	}



  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
