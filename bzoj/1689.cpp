/* ***********************************************
Author :111qqz
Created Time :2016年05月10日 星期二 21时00分28秒
File Name :code/bzoj/1689.cpp
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
const int N=1E4+76;
int n;
pi a[N];
int L;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	scanf("%d%d",&n,&L);
	for ( int i = 1 ; i <= n ; i++) scanf("%d %d",&a[i].fst,&a[i].sec),a[i].sec--;
	sort(a+1,a+n+1);

	int ans = 0;
	int lst = a[1].fst-1;
	int num = (a[1].sec-lst+L-1)/L;
	
	ans +=num;
	lst = lst+num*L;
	for ( int i = 2 ; i <= n ; i++)
	{
	  //   cout<<"ans:"<<ans<<" lst:"<<lst<<endl;
	     if (a[i].sec<=lst) continue;
	     if (a[i].fst>lst) lst = a[i].fst-1;
	     num = (a[i].sec-lst+L-1)/L;
	     ans +=num;
	     lst = lst + num*L;
	}

	printf("%d\n",ans);


	

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
