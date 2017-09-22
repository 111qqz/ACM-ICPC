/*************************************************************************
	> File Name: code/poj/2352.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月04日 星期二 00时33分52秒
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
const int N=4E4+7;
int a[N];
int t[N];
int x,y;
int n;
int lowbit (int x)
{
    return x&(-x);
}
void update(int x,int c)
{
    int i;
    for ( int i = x ; i <= 32001 ; i = i + lowbit(i))
    {
	t[i] = t[i] + c;
    }
}
int sum( int x)
{
    int i;
    int res = 0;
    for ( int i = x ; i >= 1 ; i = i-lowbit(i))
    {
	res = res + t[i];
    }
  //  cout<<"x:"<<x<<" res:"<<res<<endl;
    return res;
}
int main()
{
    scanf("%d",&n);
    for ( int i = 0 ; i < n ; i ++ )
    {
	scanf("%d %d",&x,&y);
	a[sum(++x)]++;  // ++x是因为坐标是从0 开始，而树状数组的下标一定是从1开始，不然会TLE
			// sum(++x)是求 ++x 的level
			//
			//
	update(x,1);   //向上更新，对于每一个比x大的位置，由于x的存在，那些位置的点的level都会增加1
	               //比如对于星3，因为星1的读入，我向上更新了星2,星3,星4,星5，这时候他们的level都是1
		       //之后读入星2，更新了星3和星5，星3的level是2，星5的level也是2，之后由于星4，星5的level又加1，为5.
    }
    for ( int i = 0 ; i < n ; i ++ )
    {
	printf("%d\n",a[i]); //数组a存的是level 为i的点有多少个，即为题目所求。
    }
	return 0;
}
