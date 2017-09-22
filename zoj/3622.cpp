/*************************************************************************
	> File Name: code/zoj/3622.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月19日 星期一 00时04分30秒
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
LL m,n;
double s[10];
LL ans;
double eqs = 1E-6;
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif
   while (scanf("%lld %lld",&m,&n)!=EOF)
    {

   s[1] = 1;
   s[2] = 1.25;
   s[3] = 2;
   s[4] = 2.5;
   s[5] = 5;
   ans = 0;
   bool flag = false;
   int cnt = 0 ;
   while(!flag)
    {
	cnt++;
	for ( int i =1 ; i <= 5 ; i++)
	{
	    
	    if (s[i]>=m&&s[i]<=n&&fabs(s[i]-1.25)>eqs&&fabs(s[i]-12.5)>eqs&&fabs(s[i]-2.5)>eqs)
	    {
		ans++;
		cout<<"s[i] :"<<int(s[i])<<endl;
	    }
	    cout<<"s[i]:"<<int(s[i])<<endl;
	    if (s[i]>n ) 
	    {
		flag = true;
		break;
	    }
	    s[i] = s[i] * 10;
	}
	if (flag) break;
    }
   printf("%lld\n",ans);
    }
   
  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
