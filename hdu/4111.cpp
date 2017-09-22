/* ***********************************************
Author :111qqz
Created Time :2016年08月06日 星期六 19时03分38秒
File Name :code/hdu/4111.cpp
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
const int N=55;
int n;
int a[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	int cas = 0 ;
	while (T--)
	{
	    printf("Case #%d: ",++cas);
	    scanf("%d",&n);
	    int cnt1 = 0 ;
	    int sum = 0 ;
	    for ( int i = 1 ; i <= n ; i++)
	    {
		scanf("%d",&a[i]);
		sum+=a[i];
		if (a[i]==1) cnt1++;
	    }
	    sum+=n-1;
	    if (cnt1==0)
	    {
		if (sum%2==1)
		{
		    puts("Alice");
		}
		else
		{
		    puts("Bob");
		}
		continue;
	    }
	    if (cnt1==n)
	    {
		if (cnt1%3==0) puts("Bob");
		else puts("Alice");
		continue;
	    }
	    if (sum%2==1)
	    {
		if (cnt1%3>=1) puts("Alice");
		else puts("Bob");
	    }
	    else
	    {
		if (cnt1%3==1) puts("Alice");
		else puts("Bob");
	    }



	}

#ifndef ONLINE_JUDGE  
	fclose(stdin);
#endif
	return 0;
}
