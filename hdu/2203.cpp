/* ***********************************************
Author :111qqz
Created Time :2016年08月12日 星期五 00时56分28秒
File Name :code/hdu/2203.cpp
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
const int  N=1E5+7;
char a[N],b[N];
int n;
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

bool kmp(char *a,char *b)
{
    int n = strlen(a);
    int m = strlen(b);
    getnxt(b);
    int i = 0;
    int j = 0 ;
    while (i<n)
    {
	if (j==-1||a[i]==b[j]) i++,j++;
	else j = nxt[j];

	if (j==m) return true;
    }

    return false;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	while (~scanf("%s %s",a,b))
	{
	    int len1 = strlen(a);
	   // cout<<"a:"<<a<<" b:"<<b<<" len1:"<<len1<<endl;
	    for ( int i = 0 ; i  < len1-1 ; i++)
		a[i+len1] = a[i];
	 //   cout<<"now a:"<<a<<endl;
	    
	    if (kmp(a,b))
		puts("yes");
	    else puts("no");
	    ms(a,0); //记得清空。。。
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
