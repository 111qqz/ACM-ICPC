/*************************************************************************
	> File Name: code/cf/#322/A.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年09月29日 星期二 00时14分24秒
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
int main()
{
  #ifndef  ONLINE_JUDGE 
  // freopen("in.txt","r",stdin);
  #endif
    int a,b;
    cin>>a>>b;
    int tmp = min(a,b);
    cout<<tmp<<" ";
    if (a>b)
    {
	cout<<(a-b)/2<<endl;
    }
    else
    {
	cout<<(b-a)/2<<endl;
    }

   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
