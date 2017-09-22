/*************************************************************************
	  	> File Name: code/cf/556A.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月12日 星期日 08时27分36秒
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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int N=2E5+7;
int n;
char ch;
int sum1,sum2;
int main()
{
	cin>>n;
	sum1 = 0;
	sum2 = 0;
	for ( int i = 0 ; i < n ; i++ )
	{
		cin>>ch;
		if (ch=='1')
			sum1++;
		else sum2++;
	}
	cout<<abs(sum1-sum2)<<endl;

	  
  
  
  
	return 0;
}

