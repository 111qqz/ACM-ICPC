/* ***********************************************
Author :111qqz
Created Time :2016年08月11日 星期四 02时30分23秒
File Name :code/hdu/1711.cpp
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <deque>
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
const int M=1E4+7;
int a[N];
int b[M];
int nxt[M];
int n,m;
void getnxt(int n)
{
    int i = 0;
    int j = -1;
    nxt[0] = -1;
    while (i<n)
	if (j==-1||b[i]==b[j]) nxt[++i]=++j;
	else j = nxt[j];
}
int kmp( int n,int m)
{
    getnxt(m);
    int i = 0;
    int j = 0;
    while (i<n)
    {
	if (j==-1||a[i]==b[j]) i++,j++;
	else j = nxt[j];
	if (j==m) return i+1-m;
	
    }
    
    return -1;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	scanf("%d",&T);
	while (T--)
	{
	    scanf("%d%d",&n,&m);
	    for ( int i = 0 ; i < n ; i++) scanf("%d",&a[i]);
	    for ( int i = 0 ; i < m ; i++) scanf("%d",&b[i]);

	    int ans = kmp(n,m);
	    printf("%d\n",ans);
	    

	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
