/* ***********************************************
Author :111qqz
Created Time :2016年03月30日 星期三 16时53分57秒
File Name :code/cf/problem/538C.cpp
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
const int M=1E9; //上界并不是h的最大值。。因为还可以继续往上走啊。。
int n,m;
int h[N],d[N];



bool check (int x)
{
  //  cout<<"x:"<<x<<endl;
    
    for ( int i = 1 ; i <= m-1 ; i++)
    {
	if (x<h[i]||x<h[i+1]) return  true;
	int cost = abs(x-h[i]) + abs(h[i+1]-x);
//	cout<<"cost:"<<cost<<endl;
	if (cost<=d[i+1]-d[i]) return  true;
    }
    return false;
}
int bin()
{
    int l = 0 ;
    int r = M ;
    int mid;
    while (l<=r)
    {
	mid = (l+r)/2;
	if (check(mid))
	    l = mid + 1;
	else r = mid -1;
    }
    if (r>M) return -1;
    return r;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	cin>>n>>m;
	m++;
	for ( int i = 2 ; i <= m ; i++) cin>>d[i]>>h[i];
	
	d[1] = 1;
	h[1] = h[2] + abs(d[2]-1);
	m++;
	d[m] = n;
	h[m] = h[m-1] + abs(n-d[m-1]);


	
	if (m==1) //如果只有一天的话，是没有任何限制的。。？ 
	{
	    int mx = max(abs(n-d[1]),abs(d[1]-1));
	    cout<<h[1]+mx<<endl;
	    return 0;
	}
	
	for ( int i = 1 ; i <= m-1 ; i++)
	{
	    int tmp = abs(h[i+1]-h[i]);
	    if (d[i+1]-d[i]<tmp)
	    {
		puts("IMPOSSIBLE");
		return 0;
	    }
	}
	int ans = bin();
	if (ans==-1)
	{
	    puts("IMPOSSIBLE");
	}
	else
	cout<<ans<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
