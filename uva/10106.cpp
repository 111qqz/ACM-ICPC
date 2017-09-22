/* ***********************************************
Author :111qqz
Created Time :2016年01月30日 星期六 18时23分24秒
File Name :code/uva/10106.cpp
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
const int MAXL =512;
char sx[MAXL],sy[MAXL];
struct bigint
{
    int len;
    int ar[MAXL];
    bigint()
    {
	len = 1;
	memset(ar,0,sizeof(ar));
    }
    void in(char ss[])
    {
	//char ss[MAXL];
	
	len = strlen(ss);
	for ( int i = 0 ; i < len ; i++)
	ar[len-i+1]=ss[i]-'0';
	
//	for ( int i = 0 ; i < len ; i++) printf("hhh%d",ar[i]); printf("\n");
	
    }

    void out()
    {
	if (len==0) printf("0");

	while (len>=2&&ar[len-1]==0) len--;
	for ( int i = len-1 ; i >= 0 ; i--)
	    printf("%d",ar[i]);
	printf("\n");
    }
};

void times(bigint a,bigint b,bigint &c)
{
	int i,j;
	ms(c.ar,0);
	
	for ( i = 0 ; i <a.len ; i++)
	    for ( j = 0 ; j <b.len ;j++)
		c.ar[i+j]+=(a.ar[i]*b.ar[j]);
	i=j=0;
	while (i<=a.len+b.len-2||j)
	{
	    j+=c.ar[i];
	    c.ar[i]=j%10;
	    j=j/10;
	    ++i;
	}
	c.len=i;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

    
	while (scanf("%s %s",sx,sy)!=EOF)
	{
	    bigint x,y;
	    x.len = strlen(sx);
	    for ( int i = 0 ; i < x.len ; i++)
		x.ar[x.len-i-1]=sx[i]-'0';
	    y.len = strlen(sy);
	    for ( int i = 0 ; i < y.len ; i++)
		y.ar[y.len-i-1]=sy[i]-'0';

	  //  x.out();
	  //  y.out();
	    
	    bigint ans;
	    times(x,y,ans);
	    ans.out();
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
