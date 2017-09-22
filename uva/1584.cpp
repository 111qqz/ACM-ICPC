/*************************************************************************
	> File Name: code/uva/1584.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年09月15日 星期二 17时04分52秒
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
const int N=1E2+7;
string st;
string ans;
int len;
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
	len = st.length();
	 ans = st;
	for (int i = 0 ; i < len ; i++)
	{
	    string tmp =st.substr(i+1)+st.substr(0,i+1);
	    if (tmp<ans) ans = tmp;
	}
	cout<<ans<<endl;

	
    }
  
  
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
