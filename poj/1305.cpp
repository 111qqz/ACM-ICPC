/*************************************************************************
	> File Name: code/poj/1305.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月22日 星期六 13时49分30秒
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
const int inf = 0x3f3f3f3f;
const int N= 1E6+7;
bool v[N];
int n;
int gcd(int a,int b){
    if (a<b) return gcd(b,a);
    if (a%b==0) return b;
    return gcd(b,a%b);
}
int main()
{
    while (scanf("%d",&n)!=EOF){
	memset(v,false,sizeof(v));
	int ans = 0 ;
	int cnt = 0 ;
	for ( int t = 1 ; t <= n ;t = t + 2){
	    for ( int s = t+2 ; s*t<= n; s = s + 2){
		if (gcd(s,t)==1){
		    int a = s*t;
		    int b = (s*s-t*t)/2;
		    int c = (s*s+t*t)/2;
		    if (a<=n&&b<=n&&c<=n){
			ans++;
			for ( int i = 1 ; i*a<=n&&i*b<=n&&i*c<=n;i++){
			    v[i*a] = true;	
			    v[i*b] = true;
			    v[i*c] = true;
			}
		    }
		}
	    }
	}
	for ( int i = 1 ; i <= n ; i++){
	    if (!v[i]) cnt++;
	}
	printf("%d %d\n",ans,cnt);
    }
	return 0;
}
