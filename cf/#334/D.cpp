/* ***********************************************
Author :111qqz
Created Time :2015年12月22日 星期二 12时31分09秒
File Name :code/cf/#334/D.cpp
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
const int MOD =1E9+7;
const int N=1E6+7;
LL p,k;
LL ans;
bool v[N];

void dfs( int x)
{
//    cout<<"x:"<<x<<endl;
    v[x] = true;
    int y = (k*x)%p;
    if (!v[y]) dfs(y);
}

int main()
{
	#ifndef  ONLINE_JUDGE 
//	freopen("code/in.txt","r",stdin);
  #endif    
	ms(v,false);
	cin>>p>>k;
	if (k==1) ans = p;
	    else ans = 1;
	
	for ( int i = 1 ; i <= p-1 ; i++)
	{
	    if (v[i]) continue;
	    ans = (ans *p)%MOD;
	    dfs(i);
	}
	cout<<ans<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
