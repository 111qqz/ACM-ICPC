/* ***********************************************
Author :111qqz
Created Time :Sat 17 Sep 2016 10:08:07 PM CST
File Name :code/cf/#372/A.cpp
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
int n;
int c;
int a[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n>>c;
	for ( int i = 1 ; i <= n ; i++)
	{
	    scanf("%d",&a[i]);
	}

	int cnt = 1 ;
	for ( int i = 2 ; i <= n ; i++)
	{
	    if (a[i]-a[i-1]<=c) cnt++;
	    else cnt =  1;
	}
	cout<<cnt<<endl;
	

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
