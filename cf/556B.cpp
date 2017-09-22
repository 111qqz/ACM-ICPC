/*************************************************************************
	> File Name: code/cf/556B.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月12日 星期日 09时42分20秒
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
const int N= 1E3+5;
int n;
int a[N];
int main()
{	
    int x;
    memset(a,0,sizeof(a));
    cin>>n;
    for ( int i = 0 ;  i < n ; i++ )
    {
	  cin>>x;
	  if (i%2==0)
	  {
		a[i]=(i+n-x)%n;
	  }
	  else
	  {
		a[i]=(x+n-i)%n;
	  }
    }
    bool flag=false;
    for (int i = 1 ; i < n ; i++)
    {
	  if (a[i]!=a[0])
	  {
		flag=true;
		break;
	  }
    }
    if (!flag)
    {
	  cout<<"Yes"<<endl;
    }
    else
    {
	  cout<<"No"<<endl;
    }
	return 0;

}
