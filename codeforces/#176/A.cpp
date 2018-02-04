/* ***********************************************
Author :111qqz
Created Time :2015年12月16日 星期三 19时56分57秒
File Name :code/cf/#176/A.cpp
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
char maze[10][10];

bool ok ( int x,int y)
{
    char a,b,c,d;
    int res = 0 ;
    a = maze[x][y];
    b = maze[x+1][y];
    c = maze[x][y+1];
    d = maze[x+1][y+1];

    if (a==b&&b==c&&c==d&&d==a) return true;
    if (a==b&&a==c&&b==c) return true;
    if (a==c&&c==d&&a==d) return true;
    if (a==b&&b==d&&a==d) return true;
    if (b==c&&b==d&&c==d) return true;
    return false;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	for ( int i = 0 ; i < 4 ; i++) scanf("%s",maze[i]);

	for ( int i =  0 ; i < 3 ; i++)
	{
	    for ( int j = 0 ; j < 3 ; j++)
	    {
		if (ok(i,j))
		{
		    puts("YES");
		    return 0;
		}
	    }
	}
	puts("NO");

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
