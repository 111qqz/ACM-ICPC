/*************************************************************************
	> File Name: code/51nod/1011.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月11日 星期日 16时22分16秒
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

int gcd( int a,int b)
{
    if (a<b) return gcd(b,a);
    if (a%b==0) return b;
	else return gcd(b,a%b);
}
int main()
{
//  #ifndef  ONLINE_JUDGE 
//   freopen("in.txt","r",stdin);
//  #endif
	int a,b;
	scanf("%d %d",&a,&b);
	printf("%d\n",gcd(a,b));
   
// #ifndef ONLINE_JUDGE  
//  fclose(stdin);
//  #endif
	return 0;
}
