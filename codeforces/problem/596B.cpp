/* ***********************************************
Author :111qqz
Created Time :2015年12月08日 星期二 17时53分58秒
File Name :code/cf/problem/596B.cpp
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
const int N=2E5+7;
int n;
LL a[N],b[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	ms(a,0);
	cin>>n;
	for ( int i = 0 ; i < n ;i++) cin>>b[i];

	LL add = 0,minus = 0;
	LL cnt = 0 ;
	for ( int i = 0 ; i < n ;i++)
	{
	    a[i] = add-minus;
	    if (a[i]==b[i]) continue;
	    if (a[i]>b[i])
	    {
		minus += a[i]-b[i];
		cnt += a[i]-b[i];
	//	a[i] = b[i];
	    }
	    else
	    {
		add +=b[i]-a[i];
		//a[i] = b[i];
		cnt += b[i]-a[i];
	    }
	}
	cout<<cnt<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
