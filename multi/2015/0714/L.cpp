/*************************************************************************
	> File Name: code/2015summer/0714/L.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月17日 星期五 15时28分38秒
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
#define REP(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef unsigned long long ULL;
const int N=200;
int sum;
int s,n;
int a[N];
int cnt[N];

bool cmp(int x,int y)
{
    if (x>y) return true;
    return false;
}
int main()
{

    int cas;
    scanf("%d",&cas);
    while (cas--)
    {	
	  memset(a,0,sizeof(a));
	  memset(cnt,0,sizeof(cnt));
	  sum = 0;
	  scanf("%d",&s);
	  scanf("%d",&n);
	  for ( int i = 0 ; i  < n ; i ++ )
	  {
		scanf("%d",&a[i]);
		sum = sum + a[i]*a[i];
		cnt[a[i]]++;
	  }
	  if (sum!=s*s)
	  {
		printf("HUTUTU!\n");
		continue;
	  }
	//  cout<<"what's wrong?"<<endl;
	  sort(a,a+n,cmp);
	  if (a[0]+a[1]>s)
	  {
		printf("HUTUTU!\n");
			  continue;
	  }
	//    cout<<"what's wrong?"<<endl;
	  bool flag = false;
	  //for ( int i = 1 ; i <= 10 ;i++)
	//	cout<<cnt[i]<<endl;
	  for ( int i = 1 ; i <= 10; i++ )
	  {
	//	cout<<i<<" "<<cnt[i]<<endl;
		if (cnt[i]==0) continue;
		int tmp = n/i;
		if (2*tmp-1<cnt[i])
		{
		    flag = ,m m,true;
		    printf("HUTUTU!\n");
		    break;
		}
	  }
	  if (flag) continue;
	  
	  printf("KHOOOOB!\n");
    }
	return 0;
}
