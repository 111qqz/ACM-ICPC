/*************************************************************************
	> File Name: code/poj/2356.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月21日 星期五 13时43分41秒
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
const int N=2E4+7;
int a[N];
int sum[N];
int n;
int p[N];
int main()
{
    scanf("%d",&n);
    sum[0]= 0;
    for ( int i = 1  ; i <= n ; i++){
	scanf("%d",&a[i]);
	a[i] = a[i] % n;
	sum[i] = (sum[i-1] + a[i])%n;
    }
    memset(p,0,sizeof(p));
    for ( int i = 1 ; i <= n ; i++){
	if (sum[i]==0){
	    printf("%d\n",i);
	    for ( int j = 1 ; j <= i ; j++){
		printf("%d\n",a[j]);
	    }
	    break;
	}
	if (p[sum[i]]){
	   // cout<<"111qqz"<<endl;
	    printf("%d\n",i-p[sum[i]]);
	    for ( int j = p[sum[i]]+1 ; j <= i ; j++){
		printf("%d\n",a[j]);
	    }
	    break;
	}
	    p[sum[i]] =  i;
	
    }
  
	return 0;
}
