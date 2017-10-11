/* ***********************************************
Author :111qqz
Created Time :2017年10月02日 星期一 12时34分38秒
File Name :A.cpp
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
LL w,h,ax,ay,bx,by;
int main()
{
	freopen("anniversary.in","r",stdin);
	freopen("anniversary.out","w",stdout);
	cin>>w>>h>>ax>>ay>>bx>>by;
	if (ax>bx)
	{
	    swap(ax,bx);
	    swap(ay,by);
	}
	if (ax!=bx)
	{
	    printf("%lld %lld %lld %lld\n",ax,0LL,ax+1,h);
	}
	else
	{
	    LL my = min(ay,by);
	    printf("%lld %lld %lld %lld\n",0LL,my,w,my+1);
	}

    return 0;
}
