/*************************************************************************
	> File Name: code/2015summer/#2/G.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: Fri 24 Jul 2015 01:37:57 PM CST
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
const int N=1E4+5;
char ans[N];
int c[N];
int main()
{
    int n,k;
    cin>>n>>k;
    for ( int i = 1 ; i<=  n ; i++ )
    {
	  cin>>c[i];
    }
    c[n+1]=0;
    int cur=0;
    int sum = 0;
    for ( int i = 1 ; i <= n ; i++)
    {
	  bool flag1=false;
	  bool flag2=false;
	  if (cur==0)
	  {
		sum++;
		ans[sum]='+';
		cur = cur+c[i];
		continue;
	  }
	  if (cur==k)
	  {
		sum++;
		ans[sum]='-';
		cur = cur-c[i];
		continue;
	  }
	  int lowb=cur-c[i];
	  int upb=cur+c[i];
	  if (lowb<0&&upb>k) break;
	  if (lowb>=0)
	  {
		    flag1=true;
	  }
	  if (upb<=k)
	  {
		flag2=true;
	  }
	  if (!flag1&&!flag2)
	  {
		break;
	  }
	  if (flag1&&!flag2)
	  {
		sum++;
		ans[sum]='-';
		cur = lowb;
	  }
	  if (!flag1&&flag2)
	  {
		sum++;
		ans[sum]='+';
		cur = upb;
	  }
	  if (flag1&&flag2)
	  {
		int tmp[10];
		tmp[1]=upb+c[i+1];
		tmp[2]=upb-c[i+1];
		tmp[3]=lowb+c[i+1];
		tmp[4]=lowb-c[i+1];
		int mi = 9999999;
		int posi=-1;
		for ( int j = 1 ; j <= 4 ; j++ )
		{
		    if (tmp[j]<0||tmp[j]>k) continue;
		    if (j%2==0)
		    {
			  if (tmp[j]<mi)
			  {
				mi = tmp[j];
				posi = j;
			  }
		    }
		    else
		    {
			  if (k-tmp[j]<mi)
			  {
				mi = k-tmp[i];
				posi  = j;
			  }
		    }
		}
		if (posi<=2)
		{
		    sum++;
		    ans[sum]='+';
		    cur=upb;
		}
		else  //包含了-1的情况,那样选哪个都无所谓
		{
		    sum++;
		    ans[sum]='-';
		    cur = lowb;
		}

		
	  }
    }
    cout<<sum<<endl;
    for ( int i =1 ; i <= sum ; i++ )
    {
	  cout<<ans[i];
    }
	return 0;
}
