/* ***********************************************
Author :111qqz
Created Time :2015年12月06日 星期日 20时51分07秒
File Name :code/cf/problem/339A.cpp
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



using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int N=1E3+5;
char st[N];
int len;
int a[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	scanf("%s",st);
	int cnt = 0 ;
	len = strlen(st);
	for ( int i = 0 ; i < len  ; i++)
	{
	    if (isdigit(st[i]))
	    {
		cnt++;
		a[cnt] = st[i]-'0';
	    }
	}
	sort(a+1,a+cnt+1);
	cnt = 0 ;
	for ( int i = 0 ; i < len ; i++)
	{
	    if (isdigit(st[i]))
	    {
		cnt++;
		st[i] = char (a[cnt]+'0');
	    }
	}
	printf("%s\n",st);
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
