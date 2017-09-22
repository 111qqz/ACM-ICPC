/* ***********************************************
Author :111qqz
Created Time :2016年08月03日 星期三 19时14分42秒
File Name :code/poj/2796.cpp
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
LL sum[N];
int l[N],r[N];
stack<int>stk;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	scanf("%d",&n);
	sum[0] = 0 ;
	for ( int i = 1 ; i <= n ; i++) scanf("%d",&a[i]),sum[i] = sum[i-1] + 1LL*a[i];
	
	a[0]=a[n+1]=-1; //哨兵
	
	int x;
	stk.push(0);
	for ( int i = 1 ; i <= n ; i++)
	{
	    for (x=stk.top(); a[x]>=a[i] ; x=stk.top()) stk.pop();
	    l[i] = x + 1;
	    stk.push(i);
	}
	
	while (!stk.empty()) stk.pop();
	stk.push(n+1);
	for ( int i = n ; i >=1 ; i--)
	{
	    for (x=stk.top() ; a[x]>=a[i] ; x=stk.top()) stk.pop();
	    r[i] = x-1;
	    stk.push(i);
	}
	LL ans = -1LL;
	int L,R;
	for ( int i = 1 ; i <= n ; i++)
	{
	    LL cur = 1LL*(sum[r[i]]-sum[l[i]-1])*a[i];
	    if (cur>ans)
	    {
		ans = cur;
		L = l[i];
		R = r[i];
	    }
	}
	printf("%lld\n%d %d\n",ans,L,R);


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
