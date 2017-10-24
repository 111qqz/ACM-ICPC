/* ***********************************************
Author :111qqz
Created Time :2017年10月24日 星期二 15时10分10秒
File Name :A.cpp
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
#define PB push_back
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
const int N=1E7+7;
int n;
int a[N],b[N];
bool vis[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
//	freopen("./in.txt","r",stdin);
  #endif
	ms(vis,false);
	cin>>n;
	for  ( int i = 1 ; i <= n ; i++) cin>>a[i],vis[a[i]] = true;
	for ( int i = 1 ; i <= n ; i++) cin>>b[i],vis[b[i]] = true;
	int cnt = 0 ;
	for ( int i = 1 ; i <= n ; i++)
	    for ( int j = 1 ; j <= n ; j++)
	    {
		int tmp = a[i] ^ b[j];
		if (tmp>2E6) continue;
		if (vis[tmp]) cnt++;
	    }

	//cout<<cnt<<endl;
	if (cnt%2==0)
	    cout<<"Karen"<<endl;
	else cout<<"Koyomi"<<endl;
    return 0;
}
