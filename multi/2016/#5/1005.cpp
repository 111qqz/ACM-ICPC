/*************************************************************************
	> File Name: code/multi/#5/1005.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月04日 星期二 13时27分07秒
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
#define y0 abc111qqz
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define tm crazy111qqz
#define lr dying111qqz
using namespace std;
#define REP(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef unsigned long long ULL;
const int inf = 0x7fffffff;

 bool cmp (int x,int y)
{
    int p[3],g[3];
    int a[3];
    a[1]=x;
    a[2]=y;
    for ( int i = 1;  i <= 2 ; i++)
    {
	if (a[i]>=1&&a[i]<=2)
	{
	    p[i] = 1;
	}
	if (a[i]>=3&&a[i]<=10)
	{
	    p[i] = 2;
	}
	if (a[i]>=11&&a[i]<=18)
	{
	    p[i] = 3;
	}
	if (a[i]>=35&&a[i]<=36)
	{
	    p[i]=4;
	}
	if (a[i]>=53&&a[i]<=54)
	{
	    p[i] = 5;
	}
	if (a[i]>=85&&a[i]<=86)
	{
	    p[i] = 6;
	}

    }
    if (p[1]==p[2])
    {
	if (x==4&&y==5)
	{
	    return true;
	}
	if (x==5&&y==4)
	{
	    return false;
	}
	if (x==12&&y==13)
	{
	    return true;
	}
	if (x==13&&y==12)
	{
	    return false;
	}
	if (x==7&&y==8)
	{
	    return true;
	}
	if (x==8&&y==7)
	{
	    return false;
	}
	if (x==15&&y==16)
	{
	    return true;
	}
	if (x==16&&y==15)
	{
	    return false;
	}
	return x>y;
    }
    else
    {
	return x<y;
    }
}

int main()
{
    int  u,v;
    while (~scanf("%d %d",&u,&v))
    {

    
	if (cmp(u,v))
	{
	    printf("FIRST BIGGER\n");
	}
	else
	{
	    printf("SECOND BIGGER\n");
	}
    }
  
	return 0;
}
