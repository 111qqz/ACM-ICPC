/* ***********************************************
Author :111qqz
Created Time :2016年04月11日 星期一 19时04分50秒
File Name :code/bzoj/1650.cpp
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
const int N=5E4+7;
int L,n,m;
int d[N];

bool check( int k)
{
    int lst = 0 ;
    int cnt = 0 ;
    for ( int i = 1 ; i <= n+1 ; i++)
    {
	if (d[i]-d[lst]<k) cnt++;
	else lst = i;
	if (cnt>m) return false;

    }
    return true;
}
int bin()
{
    int l = 0 ;
    int r = L ;
    int mid;
    while (l<=r)
    {
	mid = (l+r)/2;
	if (check(mid)) l = mid + 1;
	else r = mid-1;
    }
    return r;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	scanf("%d %d %d",&L,&n,&m);
	for ( int i = 1 ; i <= n ; i++) scanf("%d",&d[i]);
	
	sort(d+1,d+n+1);
	d[0] = 0;
	d[n+1] = L;

	printf("%d\n",bin());
	
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
