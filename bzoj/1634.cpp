/* ***********************************************
Author :111qqz
Created Time :2016年04月07日 星期四 13时32分09秒
File Name :code/bzoj/1634.cpp
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
struct node
{
    LL t,d;


    bool operator < (node b)const
    {
	return t*2LL*b.d<b.t*2LL*d;
    }
}a[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	ios::sync_with_stdio(false);
	cin>>n ;
	LL total = 0LL ;
	for ( int i = 0 ; i < n ; i++) cin>>a[i].t>>a[i].d , total+=a[i].d;
	sort(a,a+n);

	LL ans = 0LL ;

	for ( int i = 0  ; i < n ; i++ )
	{
	    total-=a[i].d;
	    ans += total*2LL*a[i].t;
	}

	cout<< ans << endl ;
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
