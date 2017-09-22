/* ***********************************************
Author :111qqz
Created Time :Sun 02 Oct 2016 09:15:04 PM CST
File Name :code/cf/problem/675B.cpp
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
LL n,a,b,c,d;
LL x2,x3,x4,x5;
bool ok ( LL x)
{
    if (x>=1&&x<=n) return true;
    return false;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n>>a>>b>>c>>d;
	LL cnt = 0 ;
	for ( int x1 = 1 ; x1 <= n ; x1++)
	{
	    x2 = x1 + b - c;
	    x4 = x1 + a - d;
	    x5 = x4 + b - c;
	    if (ok(x2)&&ok(x4)&&ok(x5)&&x2+a==x5+d&&x4+b==x5+c&&x2+a+c==x4+b+d)
	    {
		cnt++;
		//printf("%d %d %d %d\n",x1,x2,x4,x5);
	    }
	}
	printf("%lld\n",cnt*n);

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
