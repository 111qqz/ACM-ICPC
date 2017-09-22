/*************************************************************************
	> File Name: code/uva/1586.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年09月16日 星期三 10时04分47秒
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
double a[30];
int main()
{
  #ifndef  ONLINE_JUDGE 
    freopen("in.txt","r",stdin);  
  #endif
    a[2] = 12.01;
    a[7] = 1.008;
    a[13] = 14.01;
    a[14] = 16.00;
    int T;
    cin>>T;
    while (T--)
    {
	cin>>st;
	int len = st.length();
	double ans =  0;
	for ( int i = 0 ; i < len ; i++)
	{
	    char tmp = st[i];
	    if (isalpha(tmp))
	    {
		int num = 1;
		if (isdigit(st[i+1]))
		{
		    num = st[i+1]-'0';
		    i++;
		    if (isdigit(st[i+1]))
		    {
			num = num * 10;
			num = num + st[i+1] - '0';
			i++;
		    }
		}
	//	cout<<"num:"<<num<<endl;
		ans = ans + num * a[tmp-'A'];
	//	cout<<"ans:"<<ans<<endl;

	    }
	}
	printf("%.3f\n",ans);

    }
  
  
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
