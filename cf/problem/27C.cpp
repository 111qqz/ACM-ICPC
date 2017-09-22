/* ***********************************************
Author :111qqz
Created Time :2015年12月29日 星期二 19时36分55秒
File Name :code/cf/problem/27C.cpp
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
const int N=1E5+7;
LL a[N];
int n;
int main()
{
	#ifndef  ONLINE_JUDGE 
//	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n;
	for ( int i = 1 ; i <= n ; i++) cin>>a[i];

	bool ok = true;
	for ( int i = 2 ; i <= n-1  ;i++)
	{
	    if ((a[i]-a[1])*(a[i+1]-a[i])<0) //注意long long 
	    {
		ok = false;
		printf("3\n1 %d %d\n",i,i+1);
		break;
	    }
	}
	if (ok)
	{
	    puts("0");
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
