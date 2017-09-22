/* ***********************************************
Author :111qqz
Created Time :2016年12月07日 星期三 00时11分24秒
File Name :code/cf/#383/CC.cpp
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
const int N=105;
int n;
int a[N];
map<int,int>mp;
bool vis[N];
int main()
{
#ifndef  ONLINE_JUDGE 
    freopen("code/in.txt","r",stdin);
#endif
    ms(vis,false);
    int n;
    cin>>n;
    for ( int i = 1 ;i <= n ; i++) cin>>a[i];
    for ( int i = 1;  i <= n ; i++)
    {
	if (a[i]==i) vis[i] = true;
    }
    int ans = inf;

    bool die= false;
    for ( int i = 1 ; i <= n ; i++)
    {
	int x = i ;
	if (vis[x]) continue;
	if (x==a[x]) continue;
	int num = 0;
	while (!mp[x]&&!vis[a[x]])
	{
	    cout<<"x:"<<x<<endl;
	    mp[x] = a[x];
	    x = a[x];
	    vis[x] = true;
	    num++;
	}
	cout<<"num:"<<num<<endl;
	if (num%2==1) ans = min(ans,num);
	else ans = min(ans,num/2);
    }
    if (ans==inf||die) puts("-1");
    else cout<<ans<<endl;


#ifndef ONLINE_JUDGE  
	fclose(stdin);
#endif
	return 0;
    }
