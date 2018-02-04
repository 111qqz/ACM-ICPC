/*************************************************************************
	> File Name: code/cf/#314/D.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月16日 星期日 00时27分54秒
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
set<int> se;
int n,k,a,m,b;
set<int>::iterator it;
int cal (int x,int y)  //cal 函数计算出当射了b之后，因此减少的能放船的个数．
{
    int res;
    res = (y-x)/(a+1)-(y-b)/(a+1)-(b-x)/(a+1);//由于射了b点，相当于之前连续的区间(x,y)被分成了（x,b）和（b,y)
						  //(x,y)区间能放的船的数量由之前变成了被分成的两个小区间能放的船的数量的和．					
    return res;
}
int main()
{
	scanf("%d %d %d",&n,&k,&a);
	scanf("%d",&m);
	se.clear();
	int sum=(n+1)/(a+1); //sum表示的是当前能放的船的个数
			    //容易知道，对于长度为l的点，最多能放的船的数量为（l+1）/(a+1);
	se.insert(0);
	se.insert(n+1);//由于要找要被射的点两遍最近的被射的点，我们不妨认为0点和n+1点也是被射的，这样处理断点容易些．
	int ans = -1;
	bool flag = false;
	for (int i=1;i<=m;i++)
	{
	    scanf("%d",&b);
	    if (flag) continue;
	    it=se.upper_bound(b);
	    int y=*it;
	    int x=*(--it);   //y和x分别是离b点最近且已经被射的点
	    sum = sum - cal(x,y);
	    if (sum<k)
	    {
		ans =  i;
		flag = true;
	    }
	    se.insert(b);
	}
	cout<<ans<<endl;
	return 0;
}
