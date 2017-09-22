/* ***********************************************
Author :111qqz
Created Time :2016年03月07日 星期一 17时06分48秒
File Name :code/cf/#345/B.cpp
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
const int N=1E3+7;
int n ;
int a[N];
int cnt[N];
int num[N];
int sum[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

    cin>>n;
    ms(cnt,0);
    ms(num,0);
    ms(sum,0);
    for ( int i = 1 ; i <= n ; i++)
    {
	cin>>a[i];
	cnt[a[i]]++;
    }
    if (n==1)
    {
	puts("0");
	return 0 ;
    }
    if (n==2)
    {
	if (a[1]==a[2])
	{
	    puts("0");
	}
	else
	{
	    puts("1");
	}
	return 0;
    }

    int mx = -1;
    for ( int i = 1 ; i <= 1000 ; i++)
    {
	num[cnt[i]]++;
	mx = max(mx,cnt[i]);
    }

    for ( int i = mx ; i >= 1 ; i --)
    {
	sum[i] = sum[i+1]+num[i];
    }

    int ans = 0 ;
    for ( int i = 1 ; i <= mx ; i++)
    {
	ans +=sum[i]-1;
//	cout<<"sum[i]:"<<sum[i]<<endl;
    }
    cout<<ans<<endl;



  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
