/* ***********************************************
Author :111qqz
Created Time :2016年03月06日 星期日 15时56分36秒
File Name :L_new.cpp
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
#include <assert.h>
#define fst first
#define sec second
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ms(a,x) memset(a,x,sizeof(a))
typedef long long LL;
using namespace std;
#define pi pair < int ,int >
#define MP make_pair
unsigned long long dp[65][2][65];
void cal(){
    memset(dp,0,sizeof(dp));
    dp[0][0][0] = 1;
    dp[1][0][0] = 1;
    dp[1][1][1] = 1;
    for(int i = 2; i <= 64; i++){
	for(int k = 0; k <= i; k++){
	    dp[i][0][k] = dp[i-1][0][k] + dp[i-1][1][k];
	    if(k>0)dp[i][1][k] = dp[i-1][0][k-1] + dp[i-1][1][k-1];
	    //cout << i << ' ' << k << ' ' << dp[i][0][k] << ' ' << dp[i][1][k] << endl;
	}
    }
}
unsigned long long _count(unsigned long long n,int du){
    int bina[65];
    if(du == 0)return 1;
    unsigned long long ans = 0;
    for(int i = 1; i <= 64; i++){
	bina[i] = n%2;
	//cout << "bina " << i << " = " << bina[i] << endl;
	n>>=1;
    }
    for(int i = 64; i >= 1; i--){
	if(bina[i]){
	    ans+=dp[i][0][du];
	    du--;
	    //assert(ans>=0);
	    //cout << "ans = " << ans << endl;
	}
    }
    return ans;
}
//using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
int main()
{
	#ifndef  ONLINE_JUDGE 
	//freopen("code/in.txt","r",stdin);
  #endif
    cal();
    unsigned long long s,t;
    int hhh,_111qqz[65];
    _111qqz[1] = 0;
    for(int i = 2; i <= 64; i++){
	int ocnt = 0,tmp =i;
	while(tmp)ocnt += tmp&1 , tmp >>= 1;
	_111qqz[i] = _111qqz[ocnt] + 1;
	//cout << "_111qqz " << i  << ' ' << _111qqz[i] << endl;
    }
    while(scanf("%I64u %I64u %d",&s,&t,&hhh)!= EOF){
	if(s == 0 && t == 0 && hhh == 0)break;
	/*if(hhh > 4){
	    puts("0");
	    continue;
	}*/
	unsigned long long answer = 0;
	if(t <= 64){
	    for(unsigned long long i = s; i <= t; i++){
		if(_111qqz[i] == hhh)answer++;
	    }
	}
	else{
	    if(s <= 64){
		for(unsigned long long i = s; i <= 64; i++){
		    if(_111qqz[i] == hhh)answer++;
		}
		for(int i = 1; i <= 64; i++){
		    if(_111qqz[i] + 1 == hhh){
			//cout << "Pdffddsfsd " << _count(t+1,i) - _count(33,i) << endl;
			answer += _count(t+1,i) - _count(33,i);
			//assert(answer>0);
		    }
		}
	    }
	    else{
		for(int i = 1; i <= 64; i++){
		    if(_111qqz[i] + 1 == hhh){
			//cout << "Psdfsd " << _count(t+1,i) - _count(s,i) << endl;
			answer += _count(t+1,i) - _count(s,i);
			//assert(answer>0);
		    }
		}
	    }
	}
	printf("%I64u\n",answer);
    }
  #ifndef ONLINE_JUDGE  
  //fclose(stdin);
  #endif
    return 0;
}
