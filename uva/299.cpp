/* ***********************************************
Author :111qqz
Created Time :2016年01月22日 星期五 19时00分49秒
File Name :code/uva/299.cpp
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
const int N=55;
int n;
int a[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	int T;
	scanf("%d",&T);
	while (T--)
	{
	    scanf("%d",&n);
	    for ( int i = 1 ; i <= n ; i++) scanf("%d",&a[i]);

	    int cnt = 0 ;
	    for ( int i = 1 ; i <= n-1 ; i++) 
	    {
		for ( int j = i+1 ; j <= n ;j++)
		{
		    if (a[i]>a[j]) cnt++;
		}
	    }
	    printf("Optimal train swapping takes %d swaps.\n",cnt);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
