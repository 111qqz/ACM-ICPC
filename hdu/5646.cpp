/* ***********************************************
Author :111qqz
Created Time :2016年03月22日 星期二 19时54分42秒
File Name :code/hdu/5646.cpp
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
const LL MOD =1E9+7;
const int N=1E5+7;
LL n,k;
LL a[N]; //k很有限。。

bool cmp(LL x,LL y)
{
    return x>y;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
	    ms(a,0);
	    cin>>n>>k;
	    LL sum = k*(k+1)/2;
	    if (sum>n)
	    {
		puts("-1");
		continue;
	    }
	    LL x = (n-sum)/k;
//	    cout<<"x:"<<x<<endl;
	    sum = 0 ;
	    for ( int i = 1 ; i <= k ; i++)
	    {
		a[i]= i+x;
		sum+=a[i];
	    }
//	    for ( int i = 1 ; i <= k ; i++) cout<<"a[i]:"<<a[i]<<endl;
	    LL r = n-sum;
//	    cout<<"r:"<<r<<" mx:"<<mx<<endl;
	    sort(a+1,a+k+1,cmp);
	    for ( int i = 1 ; i <= r ; i++) a[i]++;

	    LL ans = 1LL;
	    for ( int i = 1; i <= k ; i++)
	    {
		ans = (ans * a[i])%MOD;
	    }

	    cout<<ans%MOD<<endl;

	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
