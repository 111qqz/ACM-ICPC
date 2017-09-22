/* ***********************************************
Author :111qqz
Created Time :2016年08月12日 星期五 00时41分19秒
File Name :code/hdu/3746.cpp
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
const int N=1E5+7;
char a[N];
int n;
int nxt[N];
void getnxt( char *s)
{
    int n = strlen(s);
    int i = 0;
    int j = -1;
    nxt[0] = -1;
    while (i<n)
	if (j==-1||s[i]==s[j]) nxt[++i]=++j;
	else j = nxt[j];
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	while (T--)
	{
	    scanf("%s",a);
	    getnxt(a);
	    int n =strlen(a);
	    int k = n - nxt[n];
	    if (k==n) printf("%d\n",n);
	    else if (n%k==0) printf("0\n");
		 else printf("%d\n",k-n%k);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
