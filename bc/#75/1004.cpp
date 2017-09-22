/* ***********************************************
Author :111qqz
Created Time :2016年03月12日 星期六 19时46分59秒
File Name :code/bc/#75/1004.cpp
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
const int N=5E3+7;
int n;
int f[N];
int ans[N];
void pre()
{
    ms(ans,0);
    for ( int n = 1 ; n <  10;  n++)
    {
    
	int lst = 0 ;
	for ( int m = 1 ; m <= n ; m++)
	{
	   // ms(f,0);	    
	    for ( int i = 2 ; i <= n ; i++)
	    {
		f[i] = (f[i-1] + m)%i;	
	    }

	}
	int cur = (lst + f[n])%n;
	printf("%d %d\n",n,cur+1);
	ans[n] = cur;
	lst = cur;
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	pre();
	int T;
	cin>>T;
	while (T--)
	{
	    scanf("%d",&n);
	    for ( int m = 1; m <= n ; m++)
	    {
		for ( int i = 2 ; i <= n ; i++)
		{
		    f[i] = (f[i-1] +m)%i;
		}
	    }
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
