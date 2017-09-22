/*************************************************************************
	> File Name: code/uva/1585.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年09月16日 星期三 09时58分25秒
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
string st;
int main()
{
  #ifndef  ONLINE_JUDGE 
    freopen("in.txt","r",stdin);  
  #endif
    int T;
    cin>>T;
    while (T--)
    {
	cin>>st;
	int len = st.length();
	int p = 0 ;
	int ans = 0 ;
	for ( int i = 0 ; i < len ; i++)
	{
	    if (st[i]=='O')
	    {
		p++;
		ans = ans + p;
	    }
	    else
	    {
		p = 0 ;
	    }
	}
	printf("%d\n",ans);
    }
  
  
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
