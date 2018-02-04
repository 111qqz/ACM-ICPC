/*************************************************************************
	> File Name: code/cf/#314/CC.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月06日 星期四 15时00分46秒
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
LL ans  = 0;
int n,k;
map<LL,LL>m[2];
int main()
{
    cin>>n>>k;
    for ( int i  = 1 ; i <= n ; i ++ )
    {
	int a;
	scanf("%d",&a);
	if (a%k==0)                //枚举中间的数
	{
	    ans = ans + m[1][a/k];
	    m[1][a] = m[1][a]+m[0][a/k];//记录的是以a为中间数的序列的数
				        // 因为有多个a,而且对于第i+1个a,第i个a前面的a%k一样可以对序列有贡献,所以是累加.
	}
	m[0][a]++; //记录a的个数
//	cout<<i<<" "<<ans<<endl;
    }
    cout<<ans<<endl;
  
	return 0;
}
