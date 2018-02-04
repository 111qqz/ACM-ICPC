/*************************************************************************
	> File Name: code/cf/#319/A.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年09月14日 星期一 19时32分39秒
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
LL ans;
int main()
{

  int n,x;
  cin>>n>>x;
  int tmp;
  tmp = min((x+1)/2,(n+1)/2);
  for ( int i = 1 ; i <= tmp ; i++)
    {
	if (x%i==0&&x / i <= n){
	    ans++;
	}
    }
  
  ans = ans * 2;
  cout<<ans<<endl;
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
