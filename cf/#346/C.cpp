/* ***********************************************
Author :111qqz
Created Time :2016年03月31日 星期四 00时00分03秒
File Name :code/cf/#346/C.cpp
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
const int N=3E5+7;
LL n,m;
LL a[N];
LL sum[N];
set<LL>se;
LL ans[N];
bool vis[N];
int main()
{
#ifndef  ONLINE_JUDGE 
    freopen("code/in.txt","r",stdin);
#endif
    ms(vis,false);
    //	ios::sync_with_stdio(false);  //注意这题可能会爆long long
    cin>>n>>m;
    sum[0] = 0LL;
    for ( int i = 1 ; i <= n  ;i++)
    {
	cin>>a[i];
	sum[i] = sum[i-1] + a[i];
	se.insert(a[i]);
    }
    sort(a+1,a+n+1);
    LL k;
    for ( LL i =1 ; ; i++)
    {
	LL tmp =i*(i+1)/2;
	if (tmp>m)
	{
	    k = i-1;
	    break;
	}
	vis[i] = true;
    }
    LL cost = k*(k+1)/2;
    for ( int i = 1 ; i <= n ; i++)
    {
	if (a[i]<=k)
	{
	    cost -= a[i];
	    vis[a[i]] = false;
	}
	else
	    break;
    }
    for ( LL i = k; ; i++)
    {
	if (se.count(i+1)) continue;
	cost = cost + i + 1;
	if (cost>m)
	{
	    k =  i;
	    break;
	}
	vis[i+1] =true;
    }
    ms(ans,0LL);
    //	cout<<"k:"<<k<<endl;
    int cnt = 0 ;
    for ( int i = 1 ; i <= k ; i++)
    {
	if (vis[i])
	{
	    cnt++;
	    ans[cnt] = i;
	}
    }
    cout<<cnt<<endl;	
    for (  int i = 1 ; i < cnt ; i++) cout<<ans[i]<<" ";
    if (cnt!=0)
	cout<<ans[cnt];
#ifndef ONLINE_JUDGE  
    fclose(stdin);
#endif
    return 0;
}
