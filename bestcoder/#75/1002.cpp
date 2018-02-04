/* ***********************************************
Author :111qqz
Created Time :2016年03月12日 星期六 18时14分55秒
File Name :code/bc/#75/1002.cpp
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
int k;
bool vis[15];
int a[15];

bool ok ( int x)
{
    if (a[x]==1)
    {
	if (a[x+1]==7&&!vis[4]) return false;
	if (a[x+1]==3&&!vis[2]) return false;
	if (a[x+1]==9&&!vis[5]) return false;
    }
    if (a[x]==2)
    {
	if (a[x+1]==8&&!vis[5]) return false;
    }
    if (a[x]==3)
    {
	if (a[x+1]==1&&!vis[2]) return false;
	if (a[x+1]==9&&!vis[6]) return false;
	if (a[x+1]==7&&!vis[5]) return false;
    }
    if (a[x]==4)
    {
	if (a[x+1]==6&&!vis[5]) return false;
    }

    if (a[x]==6)
    {
	if (a[x+1]==4&&!vis[5]) return false;
    }

    if (a[x]==7)
    {
	if (a[x+1]==1&&!vis[4]) return false;
	if (a[x+1]==9&&!vis[8]) return false;
	if (a[x+1]==3&&!vis[5]) return false;
    }

    if (a[x]==8)
    {
	if (a[x+1]==2&&!vis[5]) return false;
    }

    if (a[x]==9)
    {
	if (a[x+1]==7&&!vis[8]) return false;
	if (a[x+1]==3&&!vis[6]) return false;
	if (a[x+1]==1&&!vis[5]) return false;
    }

    vis[a[x]] = true;
    return true;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	while (T--)
	{
	    scanf("%d",&k);
	    for ( int i = 1 ; i <= k ; i++) scanf("%d",&a[i]);
	    ms(vis,false);

	    if (k<=3)
	    {
		puts("invalid");
		continue;
	    }

	    bool sad = false;
	    for ( int i = 1 ; i <= k ; i++)
	    {
		if (a[i]<=0||a[i]>9)
		{
		    sad = true;
		    break;
		}
	    }
	    if (sad)
	    {
		puts("invalid");
		continue;
	    }

	    
	    for ( int i = 1 ; i <= k ; i++)
	    {
		if (!vis[a[i]])
		{
		    vis[a[i]] = true;
		}
		else
		{
		    sad = true;
		    break;
		}
	    }
	    if (sad)
	    {
		puts("invalid");
		continue;
	    }
	    bool happy = true;
	    ms(vis,false);
	    for ( int i = 1  ; i <= k-1 ; i++)
	    {
		if (!ok(i))
		{
		    happy = false;
		    break;
		}
		
	
	    }
	    if (happy)
	    {
		puts("valid");
	    }
	    else
	    {
		puts("invalid");
	    }
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
