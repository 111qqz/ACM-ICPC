/* ***********************************************
Author :111qqz
Created Time :2015年12月19日 星期六 23时18分13秒
File Name :code/cf/edu3/B.cpp
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
const int N=2E5+7;
int n;
int m;
int cnt[15];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	
	ms(cnt,0);
	scanf("%d%d",&n,&m);
	for ( int i = 1 ; i <= n ; i++)
	{
	    int x;
	    scanf("%d",&x);
	    cnt[x]++;
	}

	int ans= 0  ;
	for ( int i = 1 ; i <= 9 ; i++)
	{
	    for ( int j = i+1 ; j <= 10 ; j++)
	    {
		ans+=cnt[i]*cnt[j];
	    }
	    
	}
	cout<<ans<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
