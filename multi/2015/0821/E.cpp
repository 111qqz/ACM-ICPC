/*************************************************************************
	> File Name: code/2015summer/0821/E.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月21日 星期五 01时28分23秒
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
const int inf = 0x7fffffff;
const int N=2E2+7;
int dp[N][N][2];
int cntA,cntB;

struct Q{
    int beg,t;
    char dir;
}q[N],a[N],b[N];
void init(){
    int n;
    int beg,time;
    char dir;
    scanf("%d",&n);
     cntA = 0 ;
     cntB = 0 ;
    for ( int i = 0 ; i < n ;i++){
	cin>>q[i].dir>>q[i].beg>>q[i].t;
    }
    for ( int  i = 0 ; i < n ; i ++){
	if (q[i].dir=='A'){
	    cntA++;
	    a[cntA].beg = q[i].beg;
	    a[cntA].t = q[i].t;
	}
	else{
	    cntB++;
	    b[cntB].beg = q[i].beg;
	    b[cntB].t = q[i].t;
	    
	}
    }
    for ( int i = 0 ; i <= cntA ; i ++){
	for ( int j = 0 ; j <= cntB ; j++){
	    dp[i][j][0]=dp[i][j][1]=inf/2; //正无穷溢出了....调了三个小时..妈蛋
	}
    }
    dp[0][0][0]=dp[0][0][1]=0;
}

void solve(){
    int l,r;
    l = r = 0 ;
    for ( int i = 0 ; i<= cntA ; i++){
	for ( int j = 0 ; j <= cntB ; j++){
	    l = dp[i][j][1]-10;
	    r = dp[i][j][1]-10;
	    for ( int k = i+1 ; k<=cntA ; k++){
 		l = max(l+10,a[k].beg);
		r = max(r+10,l+a[k].t);
		dp[k][j][0] = min (r,dp[k][j][0]);
	    }
	    l = dp[i][j][0]-10;
	    r = dp[i][j][0]-10;
	    for ( int k = j+1 ; k<=cntB ; k++){
	 	l = max(l+10,b[k].beg);
		r = max(r+10,l+b[k].t);
		dp[i][k][1] = min (r,dp[i][k][1]);
	    }
	}
    }
}
int main(){

    int T;
    cin>>T;
    while (T--){
	init();
	solve();
	int ans = 0 ;
	ans =  min (dp[cntA][cntB][0],dp[cntA][cntB][1]);
	//	printf("%d\n",ans);
	cout<<ans<<endl;
    }
  
	return 0;
}
