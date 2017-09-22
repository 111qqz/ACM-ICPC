/*************************************************************************
	> File Name: code/cf/#328/A.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年11月01日 星期日 16时00分13秒
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
                 
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ms(a,x) memset(a,x,sizeof(a))
using namespace std;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;
int va[15],vb[15];
char maze[15][15];
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif
    ms(va,-1);
    ms(vb,0x3f);
   for (  int i = 0 ; i <8 ; i++) scanf("%s",maze[i]);
   for ( int j = 0 ; j < 8 ; j++)
    {
	for ( int i = 0 ; i < 8 ; i++)
	{
	    if (maze[i][j]=='B')
	    {
		vb[j] = i;
		break;
	    }
	}
    }
   for ( int j = 0 ; j < 8 ; j++)
    {
	for ( int i = 7 ; i >= 0 ; i--)
	{
	    if (maze[i][j]=='W')
	    {
		va[j] = i ;
		break;
	    }
	}
    }
   int p,q;
   bool ok = false;
    for ( int i = 0 ; i < 8 &&!ok ; i++)
	for ( int j =  0 ; j < 8; j++)
	{
	    if (vb[j]>=i&&maze[i][j]=='W')
	    {
		
		p = i;
		ok = true;
		break;
	    }
	}

    ok = false;
    for ( int i = 7 ; i >= 0&&!ok ; i--)
    {
	for ( int j = 0 ; j< 8  ; j++)
	{
	    if (va[j]<=i&&maze[i][j]=='B')
	    {
		q = 7-i;
		ok = true;
		break;
	    }
	}
    }
	cout<<"p:"<<p<<" q:"<<q<<endl;
	if (p<=q)
	{
	    puts("A");
	}
	else
	{
	    puts("B");
	}
    
  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
