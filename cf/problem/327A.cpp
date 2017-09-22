/* ***********************************************
Author :111qqz
Created Time :2015年12月25日 星期五 21时35分22秒
File Name :code/cf/problem/327A.cpp
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
int n ;
int a[N],b[N];
int ans;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	cin>>n;
	ans  = 0 ;
	for ( int i = 0 ; i < n ;  i++)
	{
	    cin>>a[i];
	    if (a[i] ==0) b[i] = 1;
		else b[i] = -1;
	    if (a[i]==1) ans++;
	}
	int sum=-inf,last=-inf;
	for ( int i = 0 ; i < n ; i++)
	{
	    last = max(last,0)+b[i];
	    sum = max(sum,last);
	}
	ans +=sum;
//	cout<<"sum:"<<sum<<endl;
	cout<<ans<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
