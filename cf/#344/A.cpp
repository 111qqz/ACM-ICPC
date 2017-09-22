/* ***********************************************
Author :111qqz
Created Time :2016年03月24日 星期四 14时56分05秒
File Name :code/cf/#344/A.cpp
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
int n;
LL a[N],b[N];
LL sum1[N],sum2[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n;
	sum1[0]=sum2[0]=0;
	for ( int i = 1 ; i <= n ; i++)
	{
	    cin>>a[i];
	    sum1[i] = sum1[i-1] |a[i];
	}
	for ( int i = 1 ; i <= n ; i++)
	{
	    cin>>b[i];
	    sum2[i] = sum2[i-1] | b[i];
	}
//	for ( int i = 1 ; i <= n ; i++)
//	{
//	    cout<<sum1[i]<<" "<<sum2[i]<<" "<<sum1[i]+sum2[i]<<endl;
//	}
	LL ans = -1;
	LL cur;
	for ( int i = 1 ; i <= n ; i++)
	{
	    for ( int j = i ; j <= n ; j++)
	    {
		LL tmp1 = sum1[j]^sum1[i-1];
		LL tmp2 = sum2[j]^sum2[i-1];
		cur = tmp1+tmp2;
//		cout<<"tmp1:"<<tmp1<<" tmp2:"<<tmp2<<" "<<tmp1+tmp2<<endl;
		if (cur>ans) ans = cur;
	    }
	}
	cout<<ans<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
