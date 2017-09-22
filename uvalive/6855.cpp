/* ***********************************************
Author :111qqz
Created Time :2016年08月25日 星期四 20时21分45秒
File Name :code/uvalive/6855.cpp
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
const int N=10005;
int a[N];
int n;
bool check()
{
    for ( int i = 0 ; i < n ; i++) if (a[i]<0) return false;
    return true;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (~scanf("%d",&n))
	{
	    for ( int i = 0 ; i  < n ; i++) scanf("%d",&a[i]);
	    
	    int cnt = 0 ;
	    while (!check())
	    {
		for ( int i = 0 ; i < n ; i++)
		    if (a[i]<0)
		    {
			int x =(i-1+n)%n;
			int y =(i+1+n)%n;
			a[x]+=a[i];
			a[y]+=a[i];
			a[i]=-a[i];
			cnt++;
		    }

		//for ( int i = 0 ; i < n ; i++) cout<<a[i]<<" ";
		//cout<<endl;
	    }
	    printf("%d\n",cnt);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
