/* ***********************************************
Author :111qqz
Created Time :2016年08月25日 星期四 20时44分08秒
File Name :code/uvalive/6862.cpp
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
int n,m;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	while (~scanf("%d%d",&m,&n))
	{
	    int ans = (n-1)*(m+1);
	    cout<<"ans:"<<ans<<endl; 
	    for ( int i = 1 ; i <= m ; i++)
		for ( int j = i ; j <= m ; j++)
		    for ( int k = j ; k <= m ; k++)
			if (i*i+j*j==k*k) ans++;

	    printf("%d\n",ans);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
