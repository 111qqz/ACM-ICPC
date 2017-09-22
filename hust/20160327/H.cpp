/* ***********************************************
Author :111qqz
Created Time :2016年03月27日 星期日 13时56分21秒
File Name :code/hust/20160327/H.cpp
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
struct node
{
    int x,y;
}p,q;
int n,m;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n>>m>>p.x>>p.y>>q.x>>q.y;
	int x = abs(p.x-q.x);
	int y = abs(p.y-q.y);
	if (x==0&&y<=4)
	{
	    puts("First");
	    return 0;
	}
	if (y==0&&x<=4)
	{
	    puts("First");
	    return 0;
	}
	if (x<=3&&y<=3)
	{
	    puts("First");
	    
	    return 0; 
	}
	if ((x<=2&&y==4)||(x==4&&y<=2))
	{
	    puts("First");
	    return 0;
	}

	puts("Second");
	



  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
