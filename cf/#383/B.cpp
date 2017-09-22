/* ***********************************************
Author :111qqz
Created Time :2016年12月06日 星期二 22时43分00秒
File Name :code/cf/#383/B.cpp
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
int a[N];
int x;
int n;
map<int,int>mp;
int cnt[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	//freopen("code/in.txt","r",stdin);
  #endif
	cin>>n>>x;
	mp.clear();
	for ( int i = 1 ; i <= n ; i++)
	    scanf("%d",&a[i]);
	if (x==0)
	{
	    for ( int i = 1 ;i  <= n ; i++) cnt[a[i]]++;
	    LL sum = 0 ;
	    for ( int i = 1 ; i <= 1E5 ; i++)
	    {
		if (cnt[i]>=2)
		    sum = sum + 1LL*cnt[i]*(cnt[i]-1)/2;

	    }
	    cout<<sum<<endl;
	    return 0;
	}
	for ( int i = 1; i <= n ; i++)
	{
	    int tmp = x^a[i];
	 //   cout<<"tmp:"<<tmp<<endl;
	    mp[tmp]++;
	}
	LL ans = 0;
	for ( int i = 1 ; i <= n ;i++)
	{

	    ans = ans + 1LL*mp[a[i]];
	}
	cout<<ans/2<<endl;
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
