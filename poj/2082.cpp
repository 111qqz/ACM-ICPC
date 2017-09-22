/* ***********************************************
Author :111qqz
Created Time :2016年08月03日 星期三 18时54分40秒
File Name :code/poj/2082.cpp
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
const int N=5E4+7;
pi a[N];
int l[N],r[N];
int sum[N];
int n;
stack<int>stk;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (~scanf("%d",&n))
	{
	    if (n==-1) break;
	    while (!stk.empty()) stk.pop();
	    sum[0] = 0 ;
	    for ( int i = 1 ; i <= n ; i++)
	    {
		scanf("%d %d",&a[i].fst,&a[i].sec);
		sum[i] = sum[i-1] + a[i].fst;
	    }

	    a[0].sec = -1;
	    a[n+1].sec = -1;
	    stk.push(0);
	    int x;
	    for ( int i = 1 ; i <= n ; i++)
	    {
		for (x=stk.top() ; a[x].sec>=a[i].sec ; x = stk.top()) stk.pop();
		l[i] = x+1;
		stk.push(i);
	    }

	    while (!stk.empty()) stk.pop();
	    stk.push(n+1);
	    for ( int i = n ; i >=1 ; i--)
	    {
		for (x=stk.top() ; a[x].sec>=a[i].sec ; x =stk.top()) stk.pop();
		r[i] = x-1;
		stk.push(i);
	    }
	    int ans = 0 ;
	    for ( int i = 1 ; i <= n ; i++) ans = max(ans,(sum[r[i]]-sum[l[i]-1])*a[i].sec);
	    printf("%d\n",ans);



	    
	}


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
