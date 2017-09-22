/* ***********************************************
Author :111qqz
Created Time :Wed 12 Oct 2016 07:30:20 PM CST
File Name :code/hdu/2669.cpp
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
int a,b;
int exgcd( int a,int b,int &x,int &y)
{
    if (b==0)
    {
	x = 1;
	y = 0;
	return a;
    }
    int ret = exgcd(b,a%b,x,y);
    int tmp = x;
    x = y;
    y = tmp - a/b*y;
    return ret;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	while (~scanf("%d%d",&a,&b))
	{
	    int x,y;
	    if (exgcd(a,b,x,y)==1)
	    {
		while (x<0)
		{
		    x += b;
		    y -= a;
		}
		printf("%d %d\n",x,y);
	    }
	    else
	    {
		puts("sorry");
	    }
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
