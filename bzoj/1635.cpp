/* ***********************************************
Author :111qqz
Created Time :2016年04月07日 星期四 22时52分44秒
File Name :code/bzoj/1635.cpp
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
const int N=1E4+7;
int n,i,mxh,r;
int p[N];

struct node
{
    int a,b;

    bool operator < (node y)const
    {
	if (a==y.a) return b<y.b;
	return a<y.a;
    }
}q[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	ios::sync_with_stdio(false);
	cin>>n>>i>>mxh>>r;
	ms(p,0);
	for  ( int i = 1 ; i <= r ; i++) 
	{
	    cin>>q[i].a>>q[i].b;
	    if (q[i].a>q[i].b) swap(q[i].a,q[i].b);
	}
	sort(q+1,q+r+1);
	for ( int i = 1 ;i <= r; i++)
	{
	    int a = q[i].a;
	    int b = q[i].b;
	    if (a==q[i-1].a&&b==q[i-1].b) continue;  //判重
	    p[a+1]--;
	    p[b]++;

	}
	for ( int i = 1 ; i <= n ; i++) p[i] = p[i] + p[i-1];
	for ( int i = 1 ; i <= n ; i++) cout<<mxh+p[i]<<endl;
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
