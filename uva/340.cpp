/*************************************************************************
	> File Name: code/uva/340.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年09月15日 星期二 16时19分44秒
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
const int N=1E3+7;
int n;
int a[N],b[N];
int cnt1,cnt2,ans1,ans2,ans;

int main()
{
  #ifndef  ONLINE_JUDGE 
    freopen("in.txt","r",stdin); 
  #endif
    int cas = 0 ;
    while (scanf("%d",&n)!=EOF&&n)
    {
	cas++;
	printf("Game %d:\n",cas);
	for ( int i = 0 ; i < n ; i++)
	    scanf("%d",&a[i]);
    

	int x;
	while (scanf("%d",&x)!=EOF)
	{
	    ans1 = 0 ;
	    ans2 = 0 ;
	    ans = 0;
	    b[0] = x;
	    for ( int i = 1 ; i < n  ; i++)
		scanf("%d",&b[i]);
	    if (x==0) break; //注意要都读完再break掉．．．．傻逼错误多少次了
	    
	    for (int i = 0 ; i < n ; i++)
		if (a[i]==b[i])
		    ans1++;
		
		
	
	    
	    for ( int dig = 1 ; dig <= 9 ; dig++)
	    {
		cnt1 = 0 ;
		cnt2 = 0;
		for (int i = 0 ; i < n ; i++)
		{
		    if (a[i]==dig) cnt1++;
		    if (b[i]==dig) cnt2++;
		}
		int MIN = min(cnt1,cnt2);
		ans2 = ans2 + MIN;
	    }
	    printf("    (%d,%d)\n",ans1,ans2-ans1);
	    
	}
    }
  
  
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
