/* ***********************************************
Author :111qqz
Created Time :2016年04月11日 星期一 20时15分13秒
File Name :code/bzoj/1651.cpp
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
const int N=1E6+7;
int n;
int p[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	scanf("%d",&n);
	ms(p,0);
	for ( int i = 1 ; i <= n ; i++)
	{
	    int l,r;
	    scanf("%d %d",&l,&r);
	    p[l]++;
	    p[r+1]--;
	}
	for ( int i = 1 ; i <= 1000000 ; i++)
	{
	    p[i] = p[i]+p[i-1];
	}

	int ans = 0 ;
	for ( int i = 1 ; i <= 1000000 ; i++) ans = max(ans,p[i]);

	printf("%d\n",ans);

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
