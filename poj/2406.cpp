/* ***********************************************
Author :111qqz
Created Time :2016年08月02日 星期二 18时54分39秒
File Name :code/poj/2406.cpp
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
const int N=1E6+7;
int n,sa[N],t[N],t2[N],cnt[N];
int height[N];
char s[N];
int cmp( int *r,int a,int b,int l){return r[a]==r[b]&&r[a+l]==r[b+l];}
void getSa(int n,int m)
{
    int *x = t;
    int *y = t;
    ms(cnt,0);
    for ( int i = 0 ; i < n;  i++) cnt[x[i]=s[i]] ++;
    for ( int i = 1; i  < m ; i++) cnt[i]+=cnt[i-1];
    for ( int i = n-1 ; i >= 0 ; i--) sa[--cnt[x[i]]] = i ;
    for  ( int k = 1 ; k <= n ; k<<=1)
    {
	int p = 0 ;
	for ( int i = n-k ; i < n;  i++) y[p++] = i ;
	for ( int i = 0 ; i < n;  i++) if (sa[i]>=k) y[p++] = sa[i]-k;
	ms(cnt,0);
	for )_
    } 
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
