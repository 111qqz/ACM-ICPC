/* ***********************************************
Author :111qqz
Created Time :Tue 01 Nov 2016 08:00:49 PM CST
File Name :code/hdu/2522.cpp
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
int vis[N];
int n;
int cnt = 0;
void solve( int n)
{
    if (n<0)
    {
	printf("-");
	n = -n;
    }
    if (n==1)
    {
	printf("1");
	return;
    }
    int x;
    printf("0.");
    for ( x = 10; x ;x*=10)
    {
	if (vis[x]==cnt) break;
	vis[x] = cnt;
	printf("%d",x/n);
	x%=n;
    }
    puts("");
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
	    scanf("%d",&n);
	    cnt++;
	    solve(n);
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
