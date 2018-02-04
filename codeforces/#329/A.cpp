/*************************************************************************
	> File Name: code/cf/#329/A.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年11月05日 星期四 15时02分04秒
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
                 
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ms(a,x) memset(a,x,sizeof(a))
using namespace std;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;
const int N=105;
string st[N];
int n;
int cnt1[30],cnt2[30][30];
int num[30];
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif

   ms(cnt1,0);
   ms(cnt2,0);
   ms(num,0);

   scanf("%d",&n);
   for ( int i = 0  ; i < n ; i++)
    {
	cin>>st[i];
	int len = st[i].length();
	ms(num,0);
	for ( int j =  0 ;  j < len ; j++ )
	{
	    int tmp =st[i][j]-'a';
	    num[tmp]++;
	}
	int sum=0;
	for ( int j = 0 ; j < 26 ; j++)
	{
	    if (num[j]) sum++;
	}
	if (sum>2) continue;
	if (sum==1)
	{
	    int x1 = st[i][0]-'a';
	    cnt1[x1] +=len;
	}
	if (sum==2)
	{
	    int x1 = st[i][0]-'a';
	    int x2;
	    for ( int j = 1 ; j < len ; j++)
	    {
		int tmp = st[i][j]-'a';
		if (tmp!=x1)
		{
		    x2 = tmp;
		    break;
		}
	    }
	    if (x1>x2) swap(x1,x2);
	    cnt2[x1][x2]+=len;
	}
    }
    int ans = -1;
    int cur = 0 ;
    for ( int i = 0 ; i < 25 ; i++)
	for ( int j = i+1 ; j <26 ; j++ )
	{
	    cur = cnt1[i]+cnt1[j] + cnt2[i][j];
	    ans = max(ans,cur);
	}
    printf("%d\n",ans);
  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
