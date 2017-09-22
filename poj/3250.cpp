/* ***********************************************
Author :111qqz
Created Time :2016年08月03日 星期三 05时12分47秒
File Name :code/poj/3250.cpp
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
const int N=8E4+7;
int a[N];
int c[N];
stack<int>stk;
int n;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	scanf("%d",&n);
	for ( int i = 1 ; i <= n ; i++) scanf("%d",&a[i]);
	
	a[n+1] = inf;
	stk.push(n+1);
	int x;
	for ( int i = n ; i >=1 ; i--)
	{
	    for ( x = stk.top() ; a[x]<a[i] ; x = stk.top()) stk.pop();//找到第一个大于等于a[i]的位置
	    c[i] = x-1; //第一个大于等于a[i]的位置的左边就是i号牛能看到的最远的牛，c[i]-i就是i号牛能看到的牛的个数。
	    stk.push(i);
	}
//	for ( int i = n; i >= 1 ; i--) cout<<"i:"<<i<<" c[i]:"<<c[i]<<endl;
	LL ans = 0 ;
	for ( int i = 1 ; i <= n ; i++) ans = ans + 1LL*(c[i]-i);
	printf("%lld\n",ans);


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
