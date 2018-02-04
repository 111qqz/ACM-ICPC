/*************************************************************************
	> File Name: code/2015summer/#5/A.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月30日 星期四 12时37分51秒
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
#define y0 abc111qqz
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define tm crazy111qqz
#define lr dying111qqz
using namespace std;
#define REP(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef unsigned long long ULL;
const int inf = 0x7fffffff;
LL l,v1,v2,t;

double ans;
int main()
{
    cin>>l>>v1>>v2>>t;
    LL mxv = max(v1,v2);
    LL miv = min (v1,v2);
    double dis;
    double dout;
    ans = t*1.0/(l*1.0/mxv);                   
    dis = (l*1.0/mxv)*miv;
    LL ians = LL (floor(ans));
    dout = t*1.0-ians*(l*1.0/mxv);
   // cout<<"t:"<<dout<<endl;
   

    
    if (ians%2==0)
    {
	dis = l*1.0;
	 if (dout*v1+dout*v2>=dis)      //要分机偶
		ians++;
    }
    else
    {
	if (dout*v1+dout*v2>=dis)
	    ians++;

    }
    cout<<ians<<endl;
  
	return 0;
}
