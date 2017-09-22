/* ***********************************************
Author :111qqz
Created Time :2015年12月08日 星期二 21时11分20秒
File Name :code/hdu/2094.cpp
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
const int  N= 1E3+7;
int n;
set<string>all;
set<string>loser;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	
	    while (scanf("%d",&n)!=EOF)
	    {
		all.clear();
		loser.clear();
		if (n==0) break;
		for ( int i = 0 ; i < n ;i++)
		{
		    string win,lose;
		    cin>>win>>lose;
		    all.insert(win);
		    all.insert(lose);
		    loser.insert(lose);
		}
		if (all.size()-loser.size()==1)
		{
		    puts("Yes");
		}
		else
		{
		    puts("No");
		}
	    }

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
