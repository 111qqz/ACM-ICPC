/*************************************************************************
	> File Name: code/uva/1583.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年09月15日 星期二 16时47分20秒
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
int n ;
bool judge(int x,int y)
{
    int r;
    int sum = 0;
    int tmp = y-x;
    while (x)
    {
           
	r = x % 10;
	x = x/10;
	sum = sum + r;
    }
    
    if (sum==tmp) return true;
    return false;
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
	scanf("%d",&n);

	int ans = 0 ;
	int st = n-54;
	for ( int i = st ; i <= n ;i++)
	{
	    if (judge(i,n))
	    {
		ans =  i;
		break;
	    }
	}
	printf("%d\n",ans);
    }
  
  
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
