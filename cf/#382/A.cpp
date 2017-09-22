/* ***********************************************
Author :111qqz
Created Time :2016年11月29日 星期二 10时16分41秒
File Name :code/cf/#382/A.cpp
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
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int n,k;
	string st;
	cin>>n>>k;
	cin>>st;
	int x,y;
	for ( int i = 0 ; i < n ; i++)
	{
	    if (st[i]=='G') x = i ;
	    if (st[i]=='T') y = i;
	}
	bool die = false;
	if (x>y) swap(x,y);
	if ((y-x)%k==0)
	{
	    for ( int i = x ; i <= y; i+=k)
		if (st[i]=='#') die = true;
	}
	else die = true;
	if (die)
	{
	    puts("NO");
	}else puts("YES");

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
