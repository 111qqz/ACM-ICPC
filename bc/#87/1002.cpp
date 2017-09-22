/* ***********************************************
Author :111qqz
Created Time :Sat 24 Sep 2016 07:01:56 PM CST
File Name :code/bc/#87/1002.cpp
************************************************ */

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
using namespace std;
const int N = 1E3+7;
char s[N],res[N],dif[N][3];
bool dp[N][N];
int Next[N][3][N];
int n,m;
void init(){
	memset(dif,0,sizeof(dif));
	for(int i = 0; i < n/2; i++){
		if(s[i]==s[i+n/2]){
			dif[i][0] = s[i];
			for(int j = 0; j < 26; j++){
				if(j+'a' != s[i]){
					dif[i][2] = j+'a';
					break;
				}
			}
		}
		else{
			dif[i][1] = min(s[i],s[i+n/2]);
			for(int j = 0; j < 26; j++){
				if(j+'a' != s[i] && j+'a' != s[i+n/2]){
					dif[i][2] = j+'a';
					break;
				}
			}
		}
	}
}	
void calc2(){
	memset(dp,false,sizeof(dp));
	dp[n/2][0] = true;
	for(int i = n/2-1; i >= 0; i--){
		for(int j = 0; j <= 2*(n/2-i); j++){
			if(dif[i][0])dp[i][j] = dp[i][j] || dp[i+1][j];
			if(dif[i][1] && j >= 1)dp[i][j] = dp[i][j] || dp[i+1][j-1];
			if(dif[i][2] && j >= 2)dp[i][j] = dp[i][j] || dp[i+1][j-2];
		}
	}
}
			
bool dfs(int p,string prev,int rem){
	if(rem<0 || rem>n-p*2)return false;
	if(!dp[p][rem])return false;
	if(p==n/2&&rem==0){
		printf("%s%s\n",prev.c_str(),prev.c_str());
		return true;
	}
	int dig[3]={0,1,2};
	char ch[3];
	for(int i = 0; i <= 1; i++){
		for(int j = i+1; j <= 2; j++){
			if(dif[p][i] > dif[p][j]){
				swap(dig[i],dig[j]);
			}
		}
	}
	for(int i = 0; i < 3; i++)ch[i]=dif[p][dig[i]];
	for(int i = 0; i < 3; i++){
		if(dif[p][dig[i]]==0)continue;
		if(dfs(p+1,prev+ch[i],rem-dig[i]))return true;
	}
	return false;
}
void solve(){
	scanf("%d%d\n",&n,&m);
	scanf("%s",s);
	init();
	calc2();
	if(!dp[0][m]){
		puts("Impossible");
	}
	else if(!dfs(0,"",m))puts("Impossible");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)solve();

	return 0;
}	

