/* ***********************************************
Author :111qqz
Created Time :2016年02月21日 星期日 00时30分16秒
File Name :code/cf/#343/C.cpp
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
int n,m;
string s;

void solve()
{
    int a,b;
    if (n%2==1)
    {
	puts("0");
	return;
    }
    if (n==m)
    {
	for ( int i = 0 ; i < m ; i++)
	{
	    if (s[i]=='(') a++;
	    else b++;
	    if (a<b) 
	    {
		puts("0");
		return;
	    }
	}
	if (a!=b)
	{
	    puts("0");
	    return;
	}
	puts("1");
	return;
    }

    
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n>>m;
	cin>>s;
	solve();

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
