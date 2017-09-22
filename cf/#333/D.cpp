/* ***********************************************
Author :111qqz
Created Time :2015年12月22日 星期二 22时58分35秒
File Name :code/cf/#333/D.cpp
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
#define left lllllxy
#define right rrrrrxy
using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int N=1E5+7;
int n ; 
int q;
LL a[N],b[N];
int left[N];
int right[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	cin>>n;
	cin>>q;
	for ( int i = 1 ; i <= n ; i++)
	{
	    cin>>a[i];
 
	}
	for ( int i = 2 ;i  <= n ; i++)
	{
	    b[i] = abs(a[i]-a[i-1]);
	}

	while (q--)
	{
	    int l,r;
	    scanf("%d %d",&l,&r);
	    l++;

	    for ( int i = l ; i <= r ; i++)        //以b[i]为最大值，最左能到达多远。
	    {
		left[i] = i ;
		while (left[i]>l&&b[i]>b[left[i]-1])
		    left[i] = left[left[i]-1];
	    }
	    for ( int i = r ; i >= l ; i--)         //最右能到达多远。
	    {
		right[i] = i;
		while (right[i] < r &&b[i]>=b[right[i]+1])
		    right[i] = right[right[i] + 1];
    	    }
	    LL ans= 0 ;
	    for ( int i = l ; i <= r ; i++)
		ans +=(LL)(right[i]-i+1)*(LL)(i-left[i]+1)*b[i];
	    cout<<ans<<endl;

	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
