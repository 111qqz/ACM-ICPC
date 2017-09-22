/* ***********************************************
Author :111qqz
Created Time :2016年03月24日 星期四 12时24分27秒
File Name :code/cf/#120/A.cpp
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
int n,m;
int mx,mi;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	cin>>n>>m;
	if (n==0&&m>0)
	{
	    puts("Impossible");
	    return 0;
	}
	if (n==0&&m==0)
	{
	    cout<<0<<" "<<0<<endl;
	    return 0;
	}
	if (m==0&&n>0)
	{
	    cout<<n<<" "<<n<<endl;
	    return 0 ;
	}
	if (n>=m)
	{
	    mi = n ;
	    mx = n-1+m;
	}
	else
	{
	    mi = n + m-n;
	    mx = n-1+m;
	}
	cout<<mi<<" "<<mx<<endl;


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
