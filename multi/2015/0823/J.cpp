/*************************************************************************
	> File Name: code/2015summer/0823/J.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月23日 星期日 16时17分18秒
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
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define ms(a,x) memset(a,x,sizeof(a))
#define lr dying111qqz
using namespace std;
#define For(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;
const int N=1E6+7;
int a[N];
int x;
int n ;
int main()
{
 // #ifndef  ONLINE_JUDGE 
  
 // #endif
    while (scanf("%d",&x)!=EOF){
	x = x * 10000000;
	scanf("%d",&n);
	for ( int i = 0 ; i < n ; i++){
	    scanf("%d",&a[i]);
	}
	sort(a,a+n);
	int j = n-1;
	bool flag =false;
	for ( int i = 0 ; i < n-1 ; i++){
	    if (flag) break;
	    while (i<j&&a[i]+a[j]>x) j--;
	    if (a[i]+a[j]==x&&i!=j){
		printf("yes %d %d\n",a[i],a[j]);
		flag = true;
		break;
	    }
	}
	if (!flag){
	    puts("danger");
	}
    }
  
  
// #ifndef ONLINE_JUDGE  
 // fclose(stdin);
 // #endif
	return 0;
}
