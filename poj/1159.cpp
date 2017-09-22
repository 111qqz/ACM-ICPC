/* ***********************************************
Author :111qqz
Created Time :2016年04月18日 星期一 15时59分39秒
File Name :code/poj/1159.cpp
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
const int N=1E4+111;
int n;
char st[N];
int p[N];
int manacher(char *s)
{
    int len = strlen(s);

    for ( int i = len ; i >= 0 ; i--)
    {
	s[i+i+2]=s[i];
	s[i+i+1]='#';
    }
    s[0]='*';
    int maxlen = 0 ;
    int id = 0 ;

    for ( int i = 2 ; i < 2*len + 1 ; i++)
    {
	if (p[id]+id>i) p[i] = min(p[2*id-i],p[id]+id-i);
	else p[i] = 1;
	while (s[i-p[i]]==s[i+p[i]]) p[i]++;
	if (p[i]+i>p[id]+id) id =  i;
	if (p[i]>maxlen) maxlen = p[i];
    }

    return maxlen-1;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	scanf("%d",&n);
	scanf("%s",st);
	printf("%d\n",n-manacher(st));

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
