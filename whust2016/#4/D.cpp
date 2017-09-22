/* ***********************************************
Author :111qqz
Created Time :2016年08月13日 星期六 12时37分53秒
File Name :code/whust2016/#4/D.cpp
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <deque>
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
int n ,m;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	int flag = false;
	while (~scanf("%d%d",&n,&m))
	{
	    if (flag) printf("\n");
	    flag = true;
	    int l = n+1;
	    int r = m+1;
	    if (l>r) swap(l,r);
	    for ( int i = l ; i <= r ; i++)
		printf("%d\n",i);

	}


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
