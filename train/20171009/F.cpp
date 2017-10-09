/* ***********************************************
Author :111qqz
Created Time :2017年10月09日 星期一 14时34分25秒
File Name :F.cpp
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
#define PB push_back
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
const int N=25;
int n,m;
char maze[N][N];
struct Node
{
    int tot;
    int id;
    bool operator < ( Node b)
    {
	if (tot==b.tot) return id <b.id;
	return tot>b.tot;
    }
}a[50];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	while (~scanf("%d %d",&n,&m))
	{
	    if (n==0&&m==0) break;
	    ms(a,0);
	    for ( int i = 0 ; i < n ; i++) scanf("%s",maze[i]);
	    for ( int i = 0 ; i < n ; i++)
	    {
		for ( int j = 0 ; j < m ; j++)
		{
		    int val = maze[i][j]-'A';
		    a[val].tot++;
		    a[val].id = val;
		}
	    }
	    sort(a,a+26);
	    vector < pair <char,int> >ret;
	    for ( int i = 0 ; i < 26 ; i++)
	    {
		if (a[i].tot==0) continue;
		ret.PB(MP(char(a[i].id+'A'),a[i].tot));
	    }
	    int siz = ret.size();
	    for ( int i = 0 ; i < siz ;i++)
		printf("%c %d%c",ret[i].fst,ret[i].sec,i==siz-1?'\n':' ');
	}

		    


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
