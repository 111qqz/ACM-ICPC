/* ***********************************************
Author :111qqz
Created Time :2016年08月03日 星期三 04时27分31秒
File Name :code/poj/2559.cpp
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
#include <stack>
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
int l[N],r[N];
stack<int>stk;
int a[N];
int n;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	while(scanf("%d",&n)!=EOF)
	{
	    if (n==0) break;
	    for ( int i = 1 ; i <= n ; i++) scanf("%d",&a[i]);
	    a[0]=-1;
	    a[n+1]=-1;
	    while (!stk.empty()) stk.pop();
	    stk.push(0);
	    int x;
	    for ( int i = 1 ; i <= n ; i++)
	    {
		for ( x = stk.top() ; a[x]>=a[i] ; x = stk.top()) stk.pop(); //找到栈中第一个（离a[i]最近的）小于a[i]的位置
		l[i] = x+1;//第一个小于a[i]的位置的右边就是i位置往左最远能达到的不减的位置。
		stk.push(i); //栈已经处理成单调了，此时可以入栈。
	    }
	    
	    //再反向做一次。
	    while (!stk.empty()) stk.pop();

	    stk.push(n+1);
	    for ( int i = n ; i >=1 ; i--)
	    {
		for ( x=  stk.top() ; a[x]>=a[i] ; x = stk.top()) stk.pop();
		r[i] = x-1;// 第一个小于a[i]的位置的左边就是i位置往右最远能达到的不减的位置。
		stk.push(i);
	    }

	    LL ans = 0LL;
	    for ( int i = 1; i <= n ; i++) printf("i:%d l[i]:%d r[i]:%d\n",i,l[i],r[i]);
	    for ( int i = 1 ; i <= n ; i++)
		ans = max(ans,1LL*(r[i]-l[i]+1)*a[i]);

	    printf("%lld\n",ans);

	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
