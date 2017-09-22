/* ***********************************************
Author :111qqz
Created Time :2016年02月02日 星期二 05时17分24秒
File Name :code/cf/problem/453A.cpp
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
const int N=1E5+7;
double ans;
int n ,m;
double p1[N],p2[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	cin>>m>>n;
	ans =  0;
	for ( int i = 1 ; i <= m ; i++)
	{
	    ans +=i*(pow(i*1.0/m,n*1.0)-pow((i-1)*1.0/m,n*1.0));
	}
	printf("%.10f\n",ans);

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
