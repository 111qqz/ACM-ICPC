/* ***********************************************
Author :111qqz
Created Time :2016年11月16日 星期三 14时13分28秒
File Name :code/hdu/1864.cpp
 ************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
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
const int N=3E6+7;
double P;
int n;
int dp[N], value[35];

void solve( int value,int cost )
{
    for ( int i = int(P) ; i >= cost ; i--)
	dp[i] = max(dp[i],dp[i-cost]+value);
}
int main()
{
#ifndef  ONLINE_JUDGE 
    freopen("code/in.txt","r",stdin);
#endif

    while (~scanf("%lf%d",&P,&n)){
//	puts("miao?");
	if (n==0) break;
	P*=100;
	ms(dp,0);
	int cnt = 0 ;
	for ( int i = 1 ; i <= n ; i++){
	    int m;
	    scanf("%d",&m);
	    double tmp;
	    double sum = 0 ;
	    double sa=0,sb=0,sc=0;
	    char no;
	    bool die = false;
	    while (m--){
		scanf(" %c:%lf",&no,&tmp);
		if (no=='A'&&sa+tmp<=600) sa += tmp;
		else if (no=='B'&&sb+tmp<=600) sb += tmp;
		else if (no=='C'&&sc+tmp<=600) sc += tmp;
		else die = true;
		sum = sum + tmp;
		if (sum>1000) die = true;
	    }
	    sum*=100;
	    if (!die) value[++cnt] = sum;
	}

	for ( int i = 1 ; i <= cnt ; i++) solve(value[i],value[i]);
	int ans = 0 ;
	for ( int i = 1 ; i <= P ; i++) ans = max(ans,dp[i]);
	printf("%.2lf\n",ans*1.0/100);
    }

#ifndef ONLINE_JUDGE  
    fclose(stdin);
#endif
    return 0;
}
