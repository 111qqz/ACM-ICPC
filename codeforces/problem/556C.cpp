/*************************************************************************
	> File Name: code/cf/556C.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月12日 星期日 10时24分54秒
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
const int N=1E5+7;
int a[N],m[N];
LL n,k,ans	;
int main()
{
    
    cin>>n>>k;
    ans = 2*n-k+1;
    for (int i = 0 ; i < k ; i++ )
    {
	  scanf("%d",&m[i]);
	  for (int j = 0 ; j < m[i];j++)
	  {
		scanf("%d",&a[j]);
		if (a[j]==j+1)
		    ans = ans -2;

	  }
    }
    cout<<ans<<endl;
	return 0;
}

