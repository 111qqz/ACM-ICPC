/* ***********************************************
Author :111qqz
Created Time :2015年12月06日 星期日 16时19分00秒
File Name :code/bc/#64/1003.cpp
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



using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int N=105;
const LL M =1E16+5;
const int MAXK=55;
LL m;
LL a[N];
LL sum[N];
LL cal( LL x)
{
    LL res = 1;
    for ( LL i = 2 ; i <= x ; i++)
	res *= i;
    return res-1;
}

void pre()
{
    ms(sum,0);
    ms(a,0);
    a[1] = 1;
    sum[1] = 1;
    for ( LL i = 2 ;a[i-1]>M ;i++)
    {
	a[i] = cal(i);
//	s[i] = s[i-1]*2 + (a[i-1]+1);
	sum[i] = sum[i-1]*2 + (a[i-1]+1);

    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

//	LL res = LL(1)<<LL(55);
//	cout<<res<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
