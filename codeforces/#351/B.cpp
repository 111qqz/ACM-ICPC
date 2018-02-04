/* ***********************************************
Author :111qqz
Created Time :2016年05月07日 星期六 23时01分24秒
File Name :code/cf/#351/B.cpp
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
const int N=1E5+7;
int n;
int m;
int a[N];
bool div1[N],div2[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	ios::sync_with_stdio(false);
	ms(div1,false);
	ms(div2,false);
	cin>>n>>m;
//	div2[1] = true;
//	div1[n] = true;
	if (m==0)
	{
	    cout<<n-1<<endl;
	    return 0;
	}
	int mx=-1;
	int mi=n+1;
	bool die = false;
	for ( int i = 0 ; i < m ; i++)
	{
	    int u,v;
	    cin>>u>>v;
	    if (u>v) swap(u,v);
	    div2[u] = true;
	    div1[v] = true;
	    mx = max(mx,u);
	    mi = min(mi,v);
	    if (mx>mi) die = true;
	}
	if (die)
	{
	    cout<<0<<endl;
	    return 0;
	}
	

	LL ans = 0LL;
	for ( int i = 1 ; i <= n ; i++)
	{
	    if (div1[i]&&div2[i])
	    {
		cout<<0<<endl;
		return 0;
	    }
	}

	LL cnt = 0LL;
//	cout<<"mi:"<<mi<<" mx:"<<mx<<endl;
	for ( int i = 1 ; i <= n ; i++)
	{
	    if (div1[i]) continue;
	    if (div2[i]) continue;
	    if (i<mx) continue;
	    if (i>mi) continue;
	    cnt++;
	}

//	cout<<"cnt:"<<cnt<<endl;
	ans = cnt+1;
	cout<<ans<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
