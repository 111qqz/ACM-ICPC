/* ***********************************************
Author :111qqz
Created Time :2016年02月03日 星期三 17时56分30秒
File Name :code/cf/problem/107B.cpp
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
const int M=1E3+7;
int n ,m,h;
int s[M];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	cin>>n>>m>>h;
	for ( int i = 1 ; i <= m ; i++) cin>>s[i];

	double total = 0;
	for ( int i =1 ; i <= m ; i++)
	{
	    total+=s[i];
	}
	if (total<n)
	{
	    puts("-1");
	    return 0;
	}
	total--;
	n--;
	s[h]--; //减去那个人。
//	if (s[h]==1)
//	{
//	    puts("0");
//	    return 0 ;
//	}
	double a = total - s[h];
	double ans = 1.0;
//	cout<<"total:"<<total<<" a:"<<a<<endl;
	if (a<n) //s[h]队外的人无法满足剩余的要求。
	{
	    puts("1");
	    return 0;
	}
	for ( int i = 1 ; i <= n ; i++)
	{
	    ans = ans *(a*1.0/total*1.0);
//	    cout<<"ans:"<<ans<<endl;
	    a--;
	    total--;
	}
	printf("%.10f",1-ans);

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
