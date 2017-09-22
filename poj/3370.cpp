/*************************************************************************
	> File Name: code/poj/3370.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月21日 星期五 13时06分34秒
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
const int N=1E5+7;
int a[N];
LL sum[N];
int p[N];
int n,c;
int main()
{
    while (~scanf("%d %d",&c,&n)){
	if (c==0&&n==0) break;
	sum[0]  = 0;
	for ( int i  = 1 ; i <= n ;i++){
		scanf("%d",&a[i]);
	    a[i] = a[i] % c;
	    sum[i] = (sum[i-1] + a[i])%c;
	}
	memset(p,0,sizeof(p));
	for ( int i = 1 ; i <= n ; i++ ){
	    if (sum[i]==0){
		for ( int  j = 1 ;  j <= i ; j++){
		    cout<<j<<" ";
		   // cout<<"wang wang wang !"<<endl;
		}
		cout<<endl;
		break;
	    }
	    if (p[sum[i]]){
		for ( int  j = p[sum[i]]+1 ; j <= i ; j++){
		    cout<<j<<" ";
	//	    cout<<"111qqz"<<endl;
		}
		cout<<endl;
		break;
	    }
	    p[sum[i]] = i ;
	}
    }
  
	return 0;
}
