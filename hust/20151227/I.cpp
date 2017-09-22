/* ***********************************************
Author :111qqz
Created Time :2016年01月19日 星期二 20时46分10秒
File Name :code/hust/20151227/I.cpp
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
int ans;

int cal( int x,int y)
{
    int res = 0 ;
    int val = x^y;
    while (val)
    {
	res++;
	val&=val-1;
    }
    return res;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	while (T--){
	    cin>>n;
	    for ( int i = 0 ; i < n ; i++) cin>>a[i];

	    ans = -1;
	    for ( int i = 0 ; i < n-1 ; i++)
	    {
		for ( int j = i + 1 ; j < n ; j++)
		{
		    int cur =cal(a[i],a[j]);
		ans = max(cur,ans);
		}
	    }
	    cout<<ans<<endl;
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
