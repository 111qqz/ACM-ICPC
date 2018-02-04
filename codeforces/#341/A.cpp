/* ***********************************************
Author :111qqz
Created Time :2016年01月31日 星期日 22时02分34秒
File Name :code/cf/#341/A.cpp
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

LL n;
LL a[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n;
	int cnt = 0 ;
	LL minodd = inf;
	LL ans = 0 ;
	for ( int i = 0 ; i < n ; i++)
	{
	    scanf("%lld",&a[i]);
	    if (a[i]%2==1)
	    {
		cnt++;
		minodd = min(minodd,a[i]);
	    }
	    ans +=a[i];
	}
	if (cnt%2==1) ans-=minodd;
	cout<<ans<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
