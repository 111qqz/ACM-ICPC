/*************************************************************************
	> File Name: code/51nod/1046.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月11日 星期日 16时52分28秒
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
                 
#define yn hez111qqz
#define j1 cute111qqz
#define ms(a,x) memset(a,x,sizeof(a))
using namespace std;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;
LL qupow(LL a,LL b,LL k)
{
    LL res = 1 ;
    while (b>0)
    {
	if (b&1)
	    res = (res*a)%k;
	b = b>>1;
	a = (a*a)%k;
    }
    return res;
    
}
int main()
{
  #ifndef  ONLINE_JUDGE 
//   freopen("in.txt","r",stdin);
  #endif
   LL a,b,c;
   cin>>a>>b>>c;
   cout<<qupow(a,b,c)<<endl;
  
   
 #ifndef ONLINE_JUDGE  
//  fclose(stdin);
  #endif
	return 0;
}
