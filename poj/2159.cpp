/*************************************************************************
	> File Name: code/poj/2159.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年09月23日 星期三 19时04分34秒
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
const int N=30;
string st1,st2;
int len;
int a[N],b[N];


bool cmp( int a,int b)
{
    if (a>b) return true;
    return false;
}
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif
   ms(a,0);
   ms(b,0);
   cin>>st1>>st2;
   len = st1.length();
  // cout<<st1<<endl<<st2<<endl;
   for ( int i = 0 ; i < len ; i ++)
    {
	int tmp = st1[i]-'A';
	a[tmp]++;
	tmp = st2[i]-'A';
	b[tmp]++;
    }
   
   sort(a,a+26,cmp);
   sort(b,b+26,cmp);
  //  for ( int i = 0 ; i < 26 ; i++) cout<<"a[i]:"<<a[i]<<" b[i]"<<b[i]<<endl;

   bool flag = true;
   for ( int i = 0 ; i < 26 ; i++)
    {
	if (a[i]!=b[i])
	{
	    flag = false;
	    break;
	}
    }
   if (flag)
    {
	puts("YES");
    }
   else
    {
	puts("NO");
    }
    
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
