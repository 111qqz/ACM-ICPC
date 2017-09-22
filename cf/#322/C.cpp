/*************************************************************************
	> File Name: code/cf/#322/C.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年09月29日 星期二 00时40分26秒
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
const int N=1E5+7;
int n;
int k,ans;

struct Q
{
    int a,b;
}q[N];

bool cmp(Q x, Q y)
{
    if (x.b<y.b) return true;
    return false;
}
int main()
{
  #ifndef  ONLINE_JUDGE 
 //    freopen("in.txt","r",stdin);
  #endif
   
    ans = 0 ;
    scanf("%d %d",&n,&k);
    for ( int i = 0 ; i < n ; i++)
    {
	scanf("%d",&q[i].a);
	ans = ans + q[i].a / 10;
	q[i].b = q[i].a % 10 ; 
	q[i].b = 10 - q[i].b;
    }
    sort(q,q+n,cmp);
    int sum = 0 ;
    int i = 0;
    for ( int i = 0 ; i  < n ; i++)
    {
//	if (q[i].b==10) break;
	if (k-q[i].b>=0)
	{
	    k = k - q[i].b;
	    q[i].a = 100-(q[i].a/10+1)*10;
	    sum = sum + q[i].a;
	    ans++;
	}
	if (k<=0) break;
    }
    ans = ans + min(k,sum)/10 ;
    
  //  cout<<"ans:"<<ans<<endl;

    printf("%d",ans);

   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
