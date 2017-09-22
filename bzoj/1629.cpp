/* ***********************************************
Author :111qqz
Created Time :2016年04月04日 星期一 17时12分44秒
File Name :code/bzoj/1629.cpp
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
const int N=5E4+7;
int n;
struct node
{
    int s,w;

    bool operator < (node b)const
    {
	return w+s<b.w+b.s;
    }
}a[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	ios::sync_with_stdio(false);
	cin>>n;
	for ( int i = 1 ; i <= n ; i++) cin>>a[i].w>>a[i].s;

	sort(a+1,a+n+1);

	int ans = -inf;
	int total =  0;
	for ( int i = 1 ; i <= n ; i++)
	{
	    ans = max(ans,total-a[i].s);
	    total += a[i].w;
	}

	cout<<ans<<endl;


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
