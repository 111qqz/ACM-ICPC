/* ***********************************************
Author :111qqz
Created Time :2015年12月27日 星期日 19时02分35秒
File Name :code/cf/#337/B.cpp
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
const int N=2E5+7;
int n ;
LL a[N];
LL b[N];
LL ans;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	scanf("%d",&n);
	for ( int i = 1 ; i <= n ; i++) cin>>a[i];

	LL mi = inf;
	for ( int i = n ; i >= 1 ; i--)
	{
	    if (a[i]<mi)
	    {
		mi = a[i];
	    }
	}
//	cout<<"min:"<<mi<<endl;

	int cnt = 0 ;
	for ( int i = 1 ; i <= n ; i++)
	{
	    if (a[i]==mi)
	    {
		cnt++;
		b[cnt] = i;
	    }
	}
	LL mxd = -1;

	if (cnt==1)
	{
	    ans = mi*n+n-1;
	    cout<<ans<<endl;
	    return 0;
	}

	for ( int i =1 ; i <=cnt-1 ; i++)
	{
	    mxd = max(mxd,b[i+1]-b[i]);
	}
	mxd = max(mxd,b[1]+n-b[cnt]);

//	cout<<"mxd:"<<mxd<<endl;

	ans = mi*n+mxd-1;
	cout<<ans<<endl;



  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
