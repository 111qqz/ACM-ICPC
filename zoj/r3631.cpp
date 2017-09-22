/*************************************************************************
	> File Name: code/zoj/r3631.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月19日 星期一 19时36分20秒
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<stack>
#include<cctype>
                 
#define yn hez111qqz
#define j1 cute111qqz
#define ms(a,x) memset(a,x,sizeof(a))
using namespace std;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;
int n;
int a[3][35];
int m;
const int N=1<<16;
int b[N],c[N];

int solve ( int x,int k)
{
    int res = 0 ;
    int posi = 0 ;
    while (x)
    {
	if (x%2==1) res = res + a[k][posi];
	posi++;
	if (res>m) return -1;
	x = x/2;
    }
    return res;
}
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif

   while (scanf("%d %d",&n,&m)!=EOF)
   {
       int half = n/2;
       for ( int i =  0; i < half ; i++) scanf("%d",&a[0][i]);
       for ( int i = half ; i < n ; i++) scanf("%d",&a[1][i-half]);

       int MAXN = 1<<half;
       int cnt1 =0,cnt2 = 0 ;
       ms(b,0);
       ms(c,0);

       for ( int i = 0 ; i < MAXN ; i++)
       {
	    int tmp = solve(i,0);
	    if (tmp!=-1)
	    {
		b[cnt1] = tmp;
		cnt1++;
	    }
       }

       int MAXN2 = 1<<(n-half);
       for ( int i = 0 ; i <MAXN2  ; i++)
	{
	   int tmp = solve(i,1);
	   if (tmp!=-1)
	    {
		c[cnt2] = tmp;
		cnt2++;
	    }

	}
       sort(b,b+cnt1);
       sort(c,c+cnt2);
	
       int ans = -1;
       for ( int i = 0 ; i < cnt1 ; i ++)
	{
	    for ( int j =  0 ; j < cnt2 ; j++)
	    {

		if (b[i] + c[j] > m) break;
		ans = max(ans,b[i]+c[j]);
	    }
	    if (ans==m) break;
	}
       printf("%d\n",ans);
   }
  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
