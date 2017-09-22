/* ***********************************************
Author :111qqz
Created Time :2016年11月24日 星期四 09时00分04秒
File Name :code/cf/#381/C.cpp
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
int n,m;
struct node
{
    int l,r;
    int len;
    bool operator < ( node b)const
    {
	if (r==b.r) return l<b.l;
	return r<b.r;
    }
}a[N];
int ans[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	scanf("%d%d",&n,&m);
	int mx = inf ;
	for ( int i = 1; i <= m ; i++)
	{
	    scanf("%d%d",&a[i].l,&a[i].r);
	    a[i].len = a[i].r-a[i].l+1;
	    mx = min(mx,a[i].len);
	}
	printf("%d\n",mx);
	int cur = 0 ;
	for ( int i = 1 ; i <= n ; i++)
	{
//	    cout<<"miao"<<endl;
	    ans[i] = cur;
	    cur++;
	    cur = cur % mx;
	}
	for ( int i = 1;  i <= n ; i++) printf("%d ",ans[i]);
	printf("\n");


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
