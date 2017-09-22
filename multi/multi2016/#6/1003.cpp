/* ***********************************************
Author :111qqz
Created Time :2016年08月04日 星期四 12时07分55秒
File Name :code/multi2016/#6/1003.cpp
************************************************ */
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define fst first
#define sec second
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ms(a,x) memset(a,x,sizeof(a))
typedef long long LL;
#define pi pair < int ,int >
#define MP make_pair
using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int N=1E6+7;
int n;
map<int,bool>vis;
unsigned long long  a[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	while (T--)
	{
	    scanf("%d",&n);
	    unsigned long long  sum = 0 ;
	    for ( int i = 1 ; i <= n ; i++)
	    {
		scanf("%llu",&a[i]);
		unsigned long long m = a[i]%8;
		if (m==0) sum^=(a[i]-1);
		else if (m==7) sum^=(a[i]+1);
		else sum^=a[i];
	    }
		if (sum==0)
		    puts("Second player wins.");
		else puts("First player wins.");
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
