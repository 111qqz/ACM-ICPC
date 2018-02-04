/*************************************************************************
	> File Name: code/cf/#306/A.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年09月22日 星期二 18时11分04秒
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
int len;
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif
   while (cin>>st){
   len = st.length();
   int  p  = -1 ;
   int k[10]={};
   ms(k,-1);
   for ( int i = 0 ; i <len-1  ; i++)
    {
	if (st[i]=='A'&&st[i+1]=='B'&&k[0]==-1)
	{
	    k[0] = i;
	}
	if (st[i]=='B'&&st[i+1]=='A'&&k[2]==-1)
	{
	    k[2] = i;
	}
    }
   for ( int i = len - 1; i >= 1 ; i--)
    {
	if (st[i]=='A'&&st[i-1]=='B'&&k[1]==-1)
	{
	    k[1] = i;
	}
	if (st[i]=='B'&&st[i-1]=='A'&&k[3]==-1)
	{
	    k[3] = i;
	}
    }
   if ((k[0]>=0&&k[1]>=0&&abs(k[1]-k[0])>2)||(k[2]>=0&&k[3]>=0&&abs(k[3]-k[2])>2))
    {
	puts("YES");
    }
    else
    {
	puts("NO");
    }
   }
    
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
