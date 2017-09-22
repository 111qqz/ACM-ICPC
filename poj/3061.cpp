/*************************************************************************
	> File Name: code/poj/3061.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年09月25日 星期五 16时31分28秒
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<stack>
#include<cctype>
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define ms(a,x) memset(a,x,sizeof(a))
#define lr dying111qqz
using namespace std;
#define For(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;
const int N=1E5+7;
int a[N];
int S;
int n;

void solve()
{
    int ans = n+1;
    int head = 0;
    int tail = 0;
    int sum = 0 ;
    
    while (1)
    {
	while (sum<S&&tail<n)
	{
	    sum = sum + a[tail];
	    tail++;
	}
	if (sum<S) break;
	ans = min (ans,tail-head);
//	cout<<"sum:"<<sum<<" ans:"<<ans<<" head:"<<head<<" tail:"<<tail<<endl;
	sum = sum - a[head];
	head++;
    }
    if (ans==n+1)
    {
	puts("0");
    }
    else 
    printf("%d\n",ans);
}
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif
    int T;
    cin>>T;
    while (T--)
    {
	scanf("%d %d",&n,&S);
	for ( int i = 0 ; i < n ; i ++)
	{
	    scanf("%d",&a[i]);
	}
	solve();
    }
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
