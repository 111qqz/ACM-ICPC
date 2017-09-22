/*************************************************************************
	> File Name: code/poj/3067.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月04日 星期二 10时49分06秒
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
const int N=1E3+5;

int n,m,k;
int t[N*N/2];
struct R
{
    int x,y;
}r[N*N/2];

bool cmp(R a,R b)
{
    if (a.x<b.x) return true;
    if (a.x==b.x&&a.y<b.y) return true;
    return false;
}
int lowbit(int x)
{
    return x&(-x);
}
void update (int x,int c)
{
    for ( int i = x ; i < N ; i = i + lowbit(i))
    {
	t[i] = t[i] + c;
    }
}
LL sum ( int x)
{
    int res = 0 ;
    for ( int i = x ; i >= 1 ; i = i - lowbit(i))  
    {
	res = res + t[i];
    }
    return res;
}
int main()
{
    int T;
    cin>>T;
    LL ans ;
    int cas = 0;
    while (T--)
    {
	memset(t,0,sizeof(t));
	memset(r,0,sizeof(r));
	ans =  0 ;
	cas++;
	scanf("%d %d %d",&n,&m,&k);
	for ( int i = 0 ; i  < k ; i ++ )
	{
	    scanf("%d %d",&r[i].x,&r[i].y);
	}
	sort(r,r+k,cmp);
	for ( int i = 0 ; i < k;  i ++ )  //起点终点相同不算crossing
	{
	  //  update(r[i].x,1);
	   // if (r[i].x==r[i-1].x||r[i].y==r[i-1].y) continue;
	    ans = ans +i- sum(r[i].y);  //求y的逆序对数，好好理解这行代码！
	//    cout<<"ans:"<<ans<<endl;
	    update(r[i].y,1);
	}
	printf("Test case %d: %lld\n",cas,ans);

    }
	return 0;
}
