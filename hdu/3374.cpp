/* ***********************************************
Author :111qqz
Created Time :2016年08月13日 星期六 03时22分47秒
File Name :code/hdu/3374.cpp
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
char s[N],tmp[N];
int minRep(char *s)
{
    int n = strlen(s);
    int i = 0;
    int j = 1;
    int k = 0;
    while (i<n&&j<n&&k<n)
    {
	int t = s[(i+k)%n]-s[(j+k)%n];
	if (t==0) k++;
	else
	{
	    if (t>0)
		i+=k+1;
	    else j +=k+1;
	    if (i==j) j++;
	    k = 0 ;
	}
    }
    return i<j?i:j;
}
int maxRep(char *s)
{
    int n = strlen(s);
    int i = 0 ;
    int j = 1 ;
    int k = 0 ; 
    while (i<n&&j<n&&k<n)
    {
	int t = s[(i+k)%n]-s[(j+k)%n];
	if (t==0) k++;
	else
	{
	    if (t<0)
		i+=k+1;
	    else j+=k+1;
	    if (i==j) j++;
	    k = 0 ;
	}
    }
    return i<j?i:j;
}
int nxt[N];
void getnxt(char *s)
{
    int n = strlen(s);
    int i = 0 ;
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

	while (scanf("%s",s)!=EOF)
	{
	    int len = strlen(s);
	    int k = minRep(s);
	    int cnt = 0;
	    ms(tmp,0);
	    for ( int i = k ; cnt < len ; i++,cnt++)
		tmp[cnt] = s[i%len];

	    getnxt(tmp);
	    printf("%d %d ",k+1,len/(len-nxt[len]));

	    k = maxRep(s);
	    cnt = 0 ;
	    ms(tmp,0);
	    for ( int i = k ; cnt < len ; i++,cnt++)
		tmp[cnt] = s[i%len];

	    getnxt(tmp);
	    printf("%d %d\n",k+1,len/(len-nxt[len]));

	    
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
