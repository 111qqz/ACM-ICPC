/* ***********************************************
Author :111qqz
Created Time :Sun 16 Oct 2016 04:56:44 PM CST
File Name :code/15shanghai/E.cpp
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
const LL mod = 1e9+7;
LL dp[51][51][51][51],sumj[51][51][51], suma[51][51][51],sumb[51][51][51];
LL Ci2[60],Ten[60];
char s[51];
int K,n;
void init(){
    for(int i = 0; i <= 59; i++)Ci2[i] = 1LL*i*(i-1)/2;
    Ten[0] = 1;
    for(int i = 1; i <= 59; i++)Ten[i] = Ten[i-1] * 10LL % mod;
}
void refresh_DP(int i,int j,int a,int b,LL val){
    sumj[i][a][b] += val;
    suma[i][j][b] += val;
    sumb[i][j][a] += val;
}
void print_DP(int i,int j,int a,int b){
    printf("DP %d %d %d %d = %lld\n",i,j,a,b,dp[i][j][a][b]);
}
void cal(){
    for(int i = 1; i <= K; i++){
	for(int j = 1; j <= n; j++){
	    for(int a = 1; a <= n; a++){
		for(int b = 1; b <= n; b++){
		    if(a==j || b==j){
			dp[i][j][a][b] = 0;
			refresh_DP(i,j,a,b,0);
			continue;
		    }
		    if(a==b){
			//Situation 9
			dp[i][j][a][b] += (Ci2[n-2] * dp[i-1][j][a][b]) % mod;
			dp[i][j][a][b] %= mod;
			//Situation 10
			dp[i][j][a][b] += (sumj[i-1][a][b] - dp[i-1][j][a][b] + mod) % mod;
			dp[i][j][a][b] += (mod - dp[i-1][a][a][b]) % mod;
			dp[i][j][a][b] %= mod;
			//Situation 11
			dp[i][j][a][b] += dp[i-1][a][j][j];
			dp[i][j][a][b] %= mod;
		    }
		    else{
			//Situation 1 & 2
			dp[i][j][a][b] += (Ci2[n-3] + 1) * dp[i-1][j][a][b] % mod;
			dp[i][j][a][b] %= mod;
			//Situation 3
			dp[i][j][a][b] += (suma[i-1][j][b] - dp[i-1][j][j][b] - dp[i-1][j][a][b] - dp[i-1][j][b][b] + 3*mod) % mod;
			dp[i][j][a][b] %= mod;
			//Situation 4
			dp[i][j][a][b] += (sumb[i-1][j][a] - dp[i-1][j][a][j] - dp[i-1][j][a][b] - dp[i-1][j][a][a] + 3*mod) % mod;
			dp[i][j][a][b] %= mod;
			//Situation 5
			dp[i][j][a][b] += (sumj[i-1][a][b] - dp[i-1][j][a][b] - dp[i-1][a][a][b] - dp[i-1][b][a][b] + 3*mod) % mod;
			dp[i][j][a][b] %= mod;
			//Situation 6
			dp[i][j][a][b] += dp[i-1][a][j][b];
			dp[i][j][a][b] %= mod;
			//Situation 7
			dp[i][j][a][b] += dp[i-1][b][a][j];
			dp[i][j][a][b] %= mod;
		    }
		    refresh_DP(i,j,a,b,dp[i][j][a][b]);
		}
	    }
	}
    }
}
LL solve(){
    memset(dp,0,sizeof(dp));
    memset(sumj,0,sizeof(sumj));
    memset(suma,0,sizeof(suma));
    memset(sumb,0,sizeof(sumb));
    scanf("%d\n",&K);
    scanf("%s",s+1);
    n = strlen(s+1);
    if(n < 3)return 0;
    int ch;
    for(int i = 1; i <= n; i++){
	if(s[i] == '*'){
	    ch = i;
	    break;
	}
    }
    
	for(int a = 1; a <= n; a++){
	    for(int b = 1; b <= n; b++){
		if(a==ch || b==ch){
		    dp[0][ch][a][b] = 0;
		}
		else{
		    dp[0][ch][a][b] = (s[a]-'0') * (s[b]-'0');
		}
		refresh_DP(0,ch,a,b,dp[0][ch][a][b]);
	    }
	}

    cal();
    LL res = 0,tmp;
    for(int j = 2; j <= n-1; j++){
	for(int a = 1; a < j; a++){
	    for(int b = j+1; b <= n; b++){
//		printf("DP %d %d %d %d = %lld\n",K,j,a,b,dp[K][j][a][b]);
//		printf("ZS = %d\n",n-b+j-1-a);
		res += dp[K][j][a][b] * Ten[n-b+j-1-a] % mod;	
		res %= mod;
	    }
	}
    }
    return res;
}
int main()
{
#ifndef  ONLINE_JUDGE 
    freopen("code/in.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    init();
    for(int ci = 1; ci <= T; ci++){
	printf("Case #%d: %lld\n",ci,solve());
    }
#ifndef ONLINE_JUDGE  
    fclose(stdin);
#endif
    return 0;
}
