/* ***********************************************
Author :111qqz
Created Time :2016年08月19日 星期五 22时20分18秒
File Name :code/uvalive/5886.cpp
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <deque>
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
const int N=1E3+7;
char table[N][N];
char txt[N][N];
int n ;
struct Hole
{
    int x,y;
    
    void turn()
    {
	int nx = y;
	int ny = n-1-x;
	x = nx;
	y = ny;
    }
    bool operator < (Hole b)const
    {
	if (x==b.x) return y<b.y;
	return x<b.x;
    }
}hole[N*N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (~scanf("%d",&n))
	{
	    if (n==0) break;
	    for ( int i = 0 ; i  < n;  i++) scanf("%s",table[i]);
	    int cnt = 0 ;
	    for ( int i = 0 ; i < n ; i++)
		for ( int j = 0 ; j < n; j ++)
		    if (table[i][j]!='#')
		    {
			cnt++;
			hole[cnt].x = i;
			hole[cnt].y = j;
		    }
	    for ( int i = 0 ; i < n ; i++) scanf("%s",txt[i]);
	    sort(hole+1,hole+cnt+1);
	    for ( int i = 1 ; i <= cnt ; i++) printf("%c",txt[hole[i].x][hole[i].y]);

	    for ( int i = 1 ; i <= cnt ; i++) hole[i].turn();
	    sort(hole+1,hole+cnt+1);
	    for ( int i = 1 ; i <= cnt ; i++) printf("%c",txt[hole[i].x][hole[i].y]);

	    for ( int i = 1 ; i <= cnt ; i++) hole[i].turn();
	    sort(hole+1,hole+cnt+1);
	    for ( int i = 1 ; i <= cnt ; i++) printf("%c",txt[hole[i].x][hole[i].y]);

	    for ( int i = 1 ; i <= cnt ; i++) hole[i].turn();
	    sort(hole+1,hole+cnt+1);
	    for ( int i = 1 ; i <= cnt ; i++) printf("%c",txt[hole[i].x][hole[i].y]);
	    printf("\n");

	}


#ifndef ONLINE_JUDGE  
	fclose(stdin);
#endif
	return 0;
}
