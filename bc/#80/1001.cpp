/* ***********************************************
Author :111qqz
Created Time :2016年04月16日 星期六 18时55分30秒
File Name :code/bc/#80/1001.cpp
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
//	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	int n;
	scanf("%d",&T);
	while (T--)
	{
	    scanf("%d",&n);
	    bool flag = false;
	    bool zero = false;
	    int x;
	    for ( int i = 0 ; i < n ; i++)
	    {
		scanf("%d",&x);
		if (x==1) flag = true;
		if (x==0) zero = true;
	    }
	    if (flag&&zero)
	    {
		printf("YES\n");
	    }
	    else
	    {
		printf("NO\n");
	    }
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
