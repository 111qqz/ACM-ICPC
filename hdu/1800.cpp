/* ***********************************************
Author :111qqz
Created Time :2016年11月22日 星期二 19时18分30秒
File Name :code/hdu/1800.cpp
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
unsigned int BKDHash(char *str)
{
    unsigned int seed = 251;
    unsigned int hash = 0 ;
    while (*str) hash = hash*seed+(*str++);
    return (hash&0x7fffffff);
}
int n;
map<int,int>mp;
char st[305];
int main()
{
	#ifndef  ONLINE_JUDGE 
//	freopen("code/in.txt","r",stdin);
  #endif
	while (~scanf("%d",&n))
	{
	    mp.clear();
	    for ( int i = 1; i <= n ; i++)
	    {
		scanf("%s",st);
		int id = BKDHash(st);
		if (!mp[id]) mp[id] = 1;
		else mp[id]++;
	    }
	    int ans = 0;
	    for ( auto it = mp.begin(); it !=mp.end();  it++)
	    {
		ans = max(ans,it->sec);
	    }
	    printf("%d\n",ans);
	}
	

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
