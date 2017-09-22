/*************************************************************************
	> File Name: code/poj/3320.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年09月24日 星期四 19时33分20秒
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
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define ms(a,x) memset(a,x,sizeof(a))
#define lr dying111qqz
using namespace std;
#define For(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;
const int N = 1E6+7;
int a[N];
int p;
void solve ()
{
    set<int>se;
    for ( int i = 1 ; i <= p ; i++)
    {
	scanf("%d",&a[i]);
	se.insert(a[i]);
    }
    int total = se.size();
    map<int,int> cnt;
    int ans = p ;
    int head = 1 ;
    int tail = 1 ;
    int sum = 0 ;
    while (1)
    {
	while (tail<=p&&sum<total) 
	{
	    // cout<<"ajhhh"<<endl;
	 //  if (cnt[a[tail++]]++ ==0) sum++;
	     if (cnt[a[tail]]==0)
	    {
		
		sum++;
	    }
 		cnt[a[tail]]++;
         	tail++;
		
	    
	     cout<<"total"<<total<<endl;
	}
	if (sum<total) break;
	ans = min (ans ,tail - head);
	if (--cnt[a[head++]]==0) sum--;
	
    }
    printf("%d\n",ans);
}
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif
   while (scanf("%d",&p)!=EOF)
    {
	solve();
    }
  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
