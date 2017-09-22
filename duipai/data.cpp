/* ***********************************************
Author :111qqz
Created Time :2016年11月30日 星期三 15时18分00秒
File Name :data.cpp
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
    srand(time(0));
    int n = 15;
    printf("%d ",n);
    int k = rand()%6 + 1;
    printf("%d\n",k);
    int mx = 1<<k;
    mx--;
    for ( int i = 1; i <= n ; i++)
    {
	int x;
	x = rand()%mx+1;
	printf("%d\n",x);
    }

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
