/* ***********************************************
Author :111qqz
Created Time :2015年12月05日 星期六 15时00分14秒
File Name :code/cf/problem/500B.cpp
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
const int N=305;
char ok[N][N];
int p[N];
int n;
int a[N][N];
void print()
{
    for ( int i = 0 ; i < n ;i++) printf("%d ",p[i]);
}
void floyd()
{
    for ( int k = 0 ; k < n ;k ++)
	for ( int i = 0 ; i < n ; i++)
	    for ( int j = 0 ; j < n ; j++)
		if (a[i][j]==-1&&a[i][k]==1&&a[k][j]==1)
		    a[i][j] = 1;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	scanf("%d",&n);
	ms(a,-1);
	for ( int i = 0 ; i < n ; i++) scanf("%d",&p[i]);
	for ( int i = 0 ; i < n ; i++) scanf("%s",ok[i]);

	for ( int i = 0 ; i < n ; i ++)
	{
	    for ( int j = 0 ; j < n ; j++)
	    {
		if (ok[i][j]=='1')
		{
		    a[i][j] = 1;
		//    a[j][i] = 1;
		}
	    }
	}
	floyd();
	for ( int i = 0 ; i < n-1 ; i++)
	    for ( int j = i+1 ; j < n ;j++)
		if (p[i]>p[j]&&a[i][j]==1)
		{
		    swap(p[i],p[j]);
		}
	print();

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
