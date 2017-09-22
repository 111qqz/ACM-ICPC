/*************************************************************************
	> File Name: code/uva/227.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年09月17日 星期四 18时53分33秒
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<stack>
#include<cctype>
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define ms(a,x) memset(a,x,sizeof(a))
#define lr dying111qqz
using namespace std;
#define For(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;
char maze[30][30];
int sx,sy;
bool hasres;



void stop()
{
    hasres = false;
}
void solve (int x,int y,char dir)
{
    if (dir=='A')
    {
	if (x==0)
	{
	    stop();
	    return;
	}
	else
	{
	    maze[x][y]=maze[x-1][y];
	    sx = x-1;
	    sy = y;
	    return ;
	}
    }
    if (dir=='B')
    {
	if (x==4)
	{
	    stop();
	    return ;
	}
	else
	{
	    maze[x][y] = maze[x+1][y];
	    sx = x + 1;
	    sy = y;
	    return ;
	}
    }
    if (dir=='L')
    {
	if (y==0)
	{
	    stop();
	    return ;
	}
	else
	{
	    maze[x][y] = maze[x][y-1];
	    sx = x;
	    sy = y-1;
	    return;
	}
    }
    if (dir=='R')
    {
	if (y==4)
	{
	    stop();
	    return ;
	}
	else
	{
	    maze[x][y] = maze[x][y+1];
	    sx = x;
	    sy = y + 1;
	    return ;
	}
    }
}


int main()
{
  #ifndef  ONLINE_JUDGE 
    freopen("in.txt","r",stdin); 
  #endif
    int cas = 0 ;
    while (gets(maze[0]))
    {
	if (maze[0][0]=='Z') break;
	cas++;
	hasres = true;
//	getchar();
	
	for ( int i  = 1 ; i < 5 ; i++)
	{
	    for ( int j = 0  ; j < 5 ; j++)
	    {
		gets(maze[i]);
	    }
	  //  getchar();
	}
	
	for ( int i = 0 ; i < 5 ; i++)
	{
	    for ( int j = 0 ; j < 5 ; j++)
	    {
		cout<<maze[i][j];
		if (maze[i][j]==' ')
		{
		    sx = i ;
		    sy = j;
		}
	    }
	    cout<<endl;
	}
	char opt;
	while (scanf("%c",&opt)!=EOF&&opt!='0')
	{
	   // cout<<opt;
	    solve (sx,sy,opt);
	}


//	printf("Puzzle #%d:\n",cas);
	if (!hasres)
	{
//	    printf("This puzzle has no final configuration.\n");
//	    continue;
	}
/*	for ( int i = 0 ; i < 5  ; i++)
	{
	    for ( int j = 0 ; j < 5 ; j ++)
	    {
		cout<<maze[i][j];
		if (j!=4)
		    cout<<" ";
	    }
	    cout<<endl;
	}
		*/
	printf("\n"); 
	

    }
  
  
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
