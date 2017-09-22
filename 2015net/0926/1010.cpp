/*************************************************************************
	> File Name: code/0926/1010.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年09月26日 星期六 12时09分09秒
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
int n,A,B,L;
bool swa[N]; 
struct Q
{
    int l,r;
}q[N];

bool cmp(Q a,Q b)
{
    if (a.l<b.l) return true;
    if (a.l==b.l&&a.r<b.r) return true;
    return false;
}
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif
    int T;
    cin>>T;
    int cas = 0;
    while (T--)
    {
	cas++;
	scanf("%d %d %d %d",&n,&A,&B,&L);
	for ( int i = 1 ; i <= n ; i++)
	{
	    scanf("%d %d",&q[i].l,&q[i].r);
	}
	sort(q+1,q+n+1,cmp);
	memset(swa,false,sizeof(swa));
	q[0].r = -1;
	q[0].l = -1;

	for ( int i = 1 ; i <= n ; i++)
	{
	    
	    int a = max(q[i-1].r,q[i].l);
	    int b = max(q[i-1].r,q[i].r);
	    
	    for ( int j = a ; j <= b-1 ; j++)
	    {
		swa[j] = true;
	    }
	}
	int strength = 0 ;
	int ans = 0;
	for ( int i = 0 ; i < L ; i++)
	{
	    if (swa[i])
	    {
		strength -= A;
	//	cout<<"i:"<<i<<endl;
	    }
	    else
	    {
		strength += B;
	    }
	 //   cout<<"i:"<<i<<" strength:"<<strength <<endl;
	    ans = max(ans,-strength);
	}
	printf("Case #%d: %d\n",cas,ans);
    }
   
 #ifndef ONLINE_JUDGE  
//  fclose(stdin);
  #endif
	return 0;
}
