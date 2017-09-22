/* ***********************************************
Author :111qqz
Created Time :2016年08月13日 星期六 02时17分45秒
File Name :code/poj/4162.cpp
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
const int N=4E5+7;
int n ;
char s[N];
int minRep(char *s)
{
    int n = strlen(s);
    int i = 0 ;
    int j = 1;
    int k = 0 ;
    while (i<n&&j<n&&k<n)
    {
	int t = s[(i+k)%n]-s[(j+k)%n];
	if (t==0) k++;
	else
	{
	    if (t>0)
		i+=k+1;
	    else j+=k+1;
	    if (i==j) j++;
	    k = 0 ;
	}
    }
    return i<j?i:j;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (~scanf("%s",s))
	{
	    int len = strlen(s);
	    char s0 = s[0];
	    int p,q;
	    for ( int i = 0 ; i < len-1 ; i++)
	    {
		p = s[i]-'0';
	        q = s[i+1]-'0';
		q-=p;
		if (q<0) q+=8;
		s[i] = char (q+'0');
	    }
	
	    s[len-1] = char(((s0-s[len-1])+8)%8+'0');
	    int k = minRep(s);
	    int cnt = 1;
	    for (int i = k ; cnt<= len ; i++,cnt++)
		printf("%c",s[i%len]);
	    printf("\n");


	    ms(s,0);

	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
