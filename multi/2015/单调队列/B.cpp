/*************************************************************************
	> File Name: code/2015summer/单调队列/B.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月29日 星期三 20时18分16秒
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
#define y0 abc111qqz
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define tm crazy111qqz
#define lr dying111qqz
using namespace std;
#define REP(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef unsigned long long ULL;
const int inf = 0x7fffffff;
const int N=1E6+7;
int a[N],mxans[N],q[N],indx[N],mians[N];
int n,k;
int head,tail;

int main()
{
    cin>>n>>k;
    for ( int   i = 0 ; i < n ; i++ )
    {
	scanf("%d",&a[i]);
    }
    head = 1 ; tail = 0;
    for ( int i = 0; i < n ; i++)
    {
	if (indx[head]+k-1<i)
	{
	    head++;
	}
	while (head<=tail&&q[tail]<=a[i]) tail--;
	tail++;
	q[tail]=a[i];
	indx[tail]=i;
	if (i>=k-1)
	{
	    mxans[i-k+1]=q[head];
	}
    }
    head = 1 ; tail = 0;
    memset(q,0,sizeof(q));
    for ( int i  = 0 ; i < n ; i++)
    {
	if (indx[head]+k-1<i)
	{
	    head++;
	}
	while (head<=tail&&q[tail]>=a[i]) tail--;
	tail++;
	q[tail]=a[i];
	indx[tail]=i;
	if (i>=k-1)
	{
	    mians[i-k+1]=q[head];
	}
    }
    for ( int i = 0 ; i < n-k+1 ; i++ )
    {
	if (i==0)
	    cout<<mians[i];
	else cout<<" "<<mians[i];
    }
    cout<<endl;
    for ( int i = 0 ; i < n-k+1 ; i++ )
    {
	if (i==0)
	    cout<<mxans[i];
	else cout<<" "<<mxans[i];
    }
  
	return 0;
}
