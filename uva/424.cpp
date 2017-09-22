/* ***********************************************
Author :111qqz
Created Time :2016年01月30日 星期六 18时09分28秒
File Name :code/uva/424.cpp
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
const int MAXL=1E3+7;
const int modo = 10;
const int N=105;
int cnt ;
struct bigint
{
    int len;
    int ar[MAXL];
    bigint()
    {
	len = 1;
	ms(ar,0);
    }
    void in()
    {
	char ss[MAXL];
	scanf("%s",ss);
	if (strcmp(ss,"0")==0) 
	{
	    len = 0 ;
	    return;
	}
	len = strlen(ss);
	for ( int i = 0 ; i < len ; i++)
	    ar[len-i-1]=ss[i]-'0';
    }

    void out()
    {
	if (len==0) printf("0");
	    for ( int i = len-1 ; i >= 0 ; i--)
		printf("%d",ar[i]);
	    printf("\n");
    }
}bign[N];
void Plus(bigint &a,bigint b)
{
    int u,v,w;
    u=v=0;
    while (u<b.len||v)
    {
	w = a.ar[u]+b.ar[u]+v;
	a.ar[u]=w%modo;
	v=w/modo;
	++u;
    }
    if (a.len<u) a.len = u;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	 cnt = 0  ;
	while (1)
	{
	    cnt++;
	    bign[cnt].in();
	    if (bign[cnt].len==0)
	    {
		cnt--;
		break;
	    }
	}
	bigint ans;
	for ( int i = 1 ; i <= cnt ;i++)
	{
	    Plus(ans,bign[i]);
	}
	ans.out();


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
