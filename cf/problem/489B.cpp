/* ***********************************************
Author :111qqz
Created Time :2015年12月04日 星期五 17时09分49秒
File Name :code/cf/problem/489B.cpp
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
const int N=105;
int a[N],b[N];
int m,n;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	
	scanf("%d",&n);
	for ( int i = 0 ; i < n ; i++) scanf("%d",&a[i]);
	scanf("%d",&m);
	for ( int i = 0 ; i < m ; i++) scanf("%d",&b[i]);
	
	sort(a,a+n);
	sort(b,b+m);
	int cnt = 0 ;
	int p = 0;
	for ( int i =  0 ; i< n ;i++)
	{

	    for ( int j = p ; j < m ; j++)
	    {
		int tmp = abs(a[i]-b[j]);
		if (tmp<=1)
		{
		    cnt++;
		    p = j+1;
		    break;
		}
	    }
	}
	printf("%d\n",cnt);

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
