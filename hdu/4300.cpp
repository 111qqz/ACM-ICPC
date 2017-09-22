/* ***********************************************
Author :111qqz
Created Time :2016年08月12日 星期五 13时55分42秒
File Name :code/hdu/4300.cpp
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
map<char,char>mp;
char table[30];
int nxt[N];
void getnxt( char *s)
{
    int n = strlen(s);
    int i = 0 ;
    int j = -1;
    nxt[0] = -1;
    while (i<n)
	if (j==-1||s[i]==s[j]) nxt[++i] = ++ j;
	else j = nxt[j];
}
int kmp(char *a,char *b)
{
    int n = strlen(a);
    getnxt(b);
    int i = 0;
    int j = 0;
    if (n%2==0) i = n/2;
    else i = n/2+1;
    while (i<n)
    {
	if (j==-1||a[i]==b[j]) i++,j++;
	else j = nxt[j];
    }
    if (i==n) return j;
    return 0;
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
	    mp.clear();
	    scanf("%s",table);
	    for ( int i = 0 ; i < 26 ; i++)  mp[table[i]]=char(i+97);
	    scanf("%s",a);
	    int len = strlen(a);
	    for ( int i = 0 ; i < len ; i++)
		b[i] = mp[a[i]];
	    int k = kmp(a,b);
	   cout<<"k:"<<k<<endl; 
	    for ( int i = 0 ; i < len ; i++)
		printf("%c",a[i]);
	    for ( int i = k ; i < len-k ; i++)
		printf("%c",mp[a[i]]);
	    printf("\n");
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
