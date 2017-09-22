/* ***********************************************
Author :111qqz
Created Time :Tue 20 Sep 2016 12:18:19 AM CST
File Name :code/poj/3579.cpp
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
LL n,m;
int x[N];
bool check( int k) 
{
    int cnt = 0 ; //cnt为绝对值小于k的对数,小于中位数的对数应该小于m个。
    int head = 1;
    int tail = 1;
    while (head<=n)
    {
	while (x[tail]-x[head]<k&&tail<=n) tail++;
	tail--;
	cnt+=(tail-head);
	head++;
    }
    return cnt>=m;
}
int bin()
{
    int l = 0 ;
    int r = x[n] - x[1];
    while (l<=r)
    {
//	cout<<"l:"<<l<<" r:"<<r<<endl;
	int mid = (l+r)>>1;
	if (check(mid)) r = mid-1;
	else l = mid+1;
    }
    return l-1;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	while (scanf("%lld",&n)!=EOF){
	    for ( int i = 1 ; i <= n ; i++	) scanf("%d",&x[i]);
	    sort(x+1,x+n+1);
	    m = n*(n-1)/2;
	    m = (m+1)/2;
	    int ans = bin();
	    printf("%d\n",ans);
	}
#ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
