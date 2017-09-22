/* ***********************************************
Author :111qqz
Created Time :2016年04月08日 星期五 15时33分11秒
File Name :code/bzoj/1639.cpp
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
int n;
int m;
int a[N];
int sum;
int mx;
bool check ( int x)
{
    int cur = 0 ; 
    int cnt = 1 ; //初始占用一个
    for ( int i = 0 ; i < n ; i++)
    {
	cur +=a[i];
	if (cur>x)
	{
	    cur = 0 ;
	    cur += a[i];
	    cnt++;
	}
	if (cnt>m) return false;
    }
    return true;
}

int bin()
{
    int l = mx;
    int r = sum;
    int mid;

    while (l<=r)
    {
	mid = (l+r)/2;
	if (check(mid)) r = mid-1;
	else l = mid + 1;
    }
    return l;

}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	ios::sync_with_stdio(false);
	cin>>n>>m;
	mx = 0 ;
    	for ( int i = 0 ; i  < n ; i++)
	{
	    cin>>a[i];
	    sum += a[i];
	    mx = max(a[i],mx);
	}

	cout<<bin()<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
