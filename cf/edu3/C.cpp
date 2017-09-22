/* ***********************************************
Author :111qqz
Created Time :2015年12月19日 星期六 23时26分42秒
File Name :code/cf/edu3/C.cpp
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
int tar[N];
int sum;
int ave;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	scanf("%d",&n);
	sum = 0 ;
	for ( int i = 1 ; i <= n ; i++)
	{
	    scanf("%d",&a[i]);
	    sum += a[i];
	}
	ave = sum / n ;
	int res = sum-ave*n;
	for ( int i = 1 ; i <= n ; i++)
	{
	    tar[i] = ave;
	    if (i>n-res) tar[i]++;
	}
	
	sort(a+1,a+n+1);
	sort(tar+1,tar+n+1);
	int ans=0  ;
	for ( int i = 1 ; i <= n ; i++)
	{
	    int tmp = a[i]-tar[i];
	    if (tmp>0)
		ans +=tmp;
	}
	cout<<ans<<endl;
 

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
