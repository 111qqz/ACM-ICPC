/* ***********************************************
Author :111qqz
Created Time :Thu 13 Oct 2016 08:00:04 PM CST
File Name :code/poj/1006.cpp
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
int p,e,i,d;
int a[5],m[5];
void exgcd(int a,int b,int &x,int &y)
{
    if (b==0)
    {
	x = 1;
	y = 0;
	return;
    }
    exgcd(b,a%b,x,y);
    int tmp = x;
    x = y;
    y = tmp - a/b*y;
}
int crt(int a[],int m[],int n)
{
    int M = 1;
    int ans = 0 ;
    for ( int i = 1 ; i <=  n; i++) M*=m[i];
    
    for ( int i = 1 ; i <= n ; i++)
    {
	int x,y;
	int Mi = M/m[i];
	exgcd(Mi,m[i],x,y);
	ans = ( ans + Mi * x * a[i])%M;
    }
    if (ans<0) ans+=M;
    return ans;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	int cas = 0 ;
	m[1] = 23;
	m[2] = 28;
	m[3] = 33;
	int T = 21252;
	while (~scanf("%d%d%d%d",&p,&e,&i,&d))
	{
	    if (p==-1&&e==-1&&i==-1&&d==-1) break;
	    a[1] = p;
	    a[2] = e;
	    a[3] = i;
	    int ans = crt(a,m,3);
	    if (ans-d<=0) ans += T; 
	    printf("Case %d: the next triple peak occurs in %d days.\n",++cas,ans-d);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
