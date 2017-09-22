/* ***********************************************
Author :111qqz
Created Time :2016年08月11日 星期四 05时08分32秒
File Name :code/hdu/1867.cpp
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
char a[N],b[N];
int nxt[N];

void getnxt( char *s)
{
    int n = strlen(s);
    int i = 0 ;
    int j = -1;
    nxt[0] = -1;

    while (i<n)
	if (j==-1||s[i]==s[j]) nxt[++i] = ++j;
	else j = nxt[j];
}

int kmp(char *a,char *b)
{
    int n = strlen(a);
    int m = strlen(b);
    int i = 0;
    int j = 0;
    getnxt(b);
    while (i<n&&j<m)
    {
	if (j==-1||a[i]==b[j]) i++,j++;
	else j = nxt[j];
    }
    if (i==n)
	return j;  //为什么要判断i==n...?
    return 0;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (scanf("%s\n%s",a,b)!=EOF)
	{

	    int k1 = kmp(a,b);
	    int k2 = kmp(b,a);
	    cout<<"k1:"<<k1<<" k2:"<<k2<<endl;
	    if (k1==k2)
	    {
		if (strcmp(a,b)>0)
		{
		    printf("%s",b);
		    printf("%s\n",a+k1);
		}else
		{
		    printf("%s",a);
		    printf("%s\n",b+k1);
		}
	    }
	    else if (k1>k2)
	    {
		printf("%s",a);
		printf("%s\n",b+k1);
	    }
	    else
	    {
		printf("%s",b);
		printf("%s\n",a+k2);
	    }
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
