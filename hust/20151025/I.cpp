/*************************************************************************
	> File Name: code/hust/20151025/I.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月25日 星期日 13时09分42秒
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
int n,k;
int cnt[111];

bool cmp( int a,int b)
{
    return a>b;
}
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif

   scanf("%d %d",&n,&k);
   ms(cnt,0);
   for ( int i = 0 ; i < n ; i++)
    {
	int x;
	scanf("%d",&x);
	cnt[x]++;
    }
    sort(cnt,cnt+105,cmp);
    int ans = 0 ;
    int ave = n/k;
    for ( int i  = 0 ;  i < 105 ; i++)
    {
	if (cnt[i]<=ave) break;
	else ans+=cnt[i]-ave;
    }
    printf("%d\n",ans);
  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
