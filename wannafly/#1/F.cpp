/* ***********************************************
Author :111qqz
Created Time :2016年11月19日 星期六 20时21分42秒
File Name :code/wfly/#1/F.cpp
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
int n;
char opt[3];
int x;
char cmd[3];
int main()
{
#ifndef  ONLINE_JUDGE 
    freopen("code/in.txt","r",stdin);
#endif
    scanf("%d",&n);
    int L,R;
    L = -2E9;
    R = 2E9;
    for ( int i = 1; i <= n ; i++)
    {
	scanf("%s %d %s",opt,&x,cmd);
	if (opt[0]=='>')
	{
	    if (opt[1]=='=')
	    {
		if (cmd[0]=='Y')
		{
		    L = max(L,x);		    
		}
		else
		{
		    R = min(R,x-1);
		}
	    }
	    else
	    {
		if (cmd[0]=='Y')
		{
		    L = max(L,x+1);
		}
		else
		{
		    R = min(R,x);
		}
	    }
	}else
	{
	    if (opt[1]=='=')
	    {
		if (cmd[0]=='Y')
		{
		    R = min(R,x);
		}
		else
		{
		    L = max(L,x+1);
		}
	    }
	    else
	    {
		if (cmd[0]=='Y')
		{
		    R = min(R,x-1);
		}
		else
		{
		    L =max(L,x);
		}
	    }
	}
    }
    if (L<=R)
    {
	printf("%d\n",L);
    }
    else
    {
	puts("Impossible");
    }


#ifndef ONLINE_JUDGE  
    fclose(stdin);
#endif
    return 0;
}
