/* ***********************************************
Author :111qqz
Created Time :2016年11月24日 星期四 08时09分46秒
File Name :code/cf/#381/B.cpp
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
const int N=105;
int n,m;
int a[N];
int sum[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	ms(sum,0);
	cin>>n>>m;
	for ( int i = 1 ; i <= n ; i++) cin>>a[i];
	for ( int i = 1;  i <= m ; i++)
	{
	    int l,r;
	    scanf("%d%d",&l,&r);
	    for ( int j = l ; j <= r ; j++) sum[i] = sum[i] + a[j];
	}
	int ret = 0 ;
	for ( int i =1 ; i <= m ; i++) if (sum[i]>0) ret = ret + sum[i];
	cout<<ret<<endl;


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}