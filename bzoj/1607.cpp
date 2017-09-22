/* ***********************************************
Author :111qqz
Created Time :2016年02月28日 星期日 01时06分35秒
File Name :code/bzoj/1607.cpp
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
int n;
int a[N];
int cnt[N*10];
int ans[N*10];
int main()
{
	#ifndef  ONLINE_JUDGE 
//	freopen("code/in.txt","r",stdin);
  #endif

	ms(cnt,0);

	cin>>n;
	int mx = -1;
	for ( int i = 0 ; i < n ; i++)
	{
	    scanf("%d",&a[i]);
	    cnt[a[i]]++;
	    mx = max(mx,a[i]);
	}

	for ( int i = 1 ; i <= mx; i++)
	    if (cnt[i])
		for ( int j = 1 ; j*i <= mx ; j++)
		    ans[j*i]+=cnt[i];

	for ( int i = 0  ;i < n ; i++)
	    printf("%d\n",ans[a[i]]);

	



  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
