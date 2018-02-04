/* ***********************************************
Author :111qqz
Created Time :2017年10月25日 星期三 13时05分34秒
File Name :D.cpp
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
const int N=2E5+7;
int a[N];
int cnt[N]={};
int appear[N]={};
set <int>se;
int n;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	cin>>n;
	se.clear();
	for ( int i = 1 ; i <= n ; i++)
	{
	    scanf("%d",&a[i]);
	    cnt[a[i]]++;
	}
	for ( int i = 1 ; i <= n ; i++)
	{
	    if (cnt[i]==0) se.insert(i);
	}
	

	int ans  = 0;
	for ( int i = 1 ; i <= n ; i++)
	{
	    appear[a[i]]++;
	    if (cnt[a[i]]>=2)
	    {
		auto it = se.begin();
		if (*it<a[i]||appear[a[i]]>=2)
		{
		    ans++;
		    appear[a[i]]--;
		    cnt[a[i]]--;
		    a[i] = * it;
		    se.erase(*it);
		}

	    }
	}
	cout<<ans<<endl;
	for ( int i = 1  ; i <= n ; i++) printf("%d%c",a[i],i==n?'\n':' ');

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
