/* ***********************************************
Author :111qqz
Created Time :2016年04月10日 星期日 01时50分11秒
File Name :code/bzoj/1642.cpp
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
const int N=1E3+7;
struct node
{
    int l,r;
    int val;

    bool operator < (node b)const
    {
	if (l==b.l) return r<b.r;
	return l<b.l;
    }	
}a[N];
int n,m,R;
int sum;
int dp[N];

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	scanf("%d %d %d",&n,&m,&R);   //有点LIS的感觉...
	for ( int i = 1 ; i <= m ; i++)
	{
	    scanf("%d %d %d",&a[i].l,&a[i].r,&a[i].val);
	    a[i].r += R;
	    a[i].r = min(a[i].r,n);
	}
	sort(a+1,a+m+1);

	ms(dp,0);
	for ( int i = 1 ;i  <= m ; i++) dp[i] =  a[i].val;

//	for ( int i = 1 ; i <= m ; i++) cout<<dp[i]<<" ";
//	cout<<endl;
	int ans = -1;
	for ( int i = 2 ; i <= m ; i++)
	{
	    for ( int j = 1 ; j < i ; j++)
	    {
		if (a[j].r<=a[i].l)
		{
		    dp[i] = max(dp[i],dp[j]+a[i].val);
		}
	    }
//	    for ( int j = 1 ; j <= m ; j++) cout<<dp[j]<<" ";
//	    cout<<endl;
	    ans = max(ans,dp[i]);
	}

	printf("%d\n",ans);


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
