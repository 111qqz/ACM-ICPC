/*************************************************************************
	> File Name: code/cf/#323/C.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月04日 星期日 00时44分32秒
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
#include<cctype>
                 
#define yn hez111qqz
#define j1 cute111qqz
#define ms(a,x) memset(a,x,sizeof(a))
using namespace std;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;
const int N=5E2+7;
int n;
map<int,int>mp;
map<int,int>::iterator it,it2;
int ans[N];
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif
   scanf("%d",&n);
   mp.clear();
   ms(ans,0);
   for ( int i = 0 ; i < n*n ; i++)
    {
	int x;
	scanf("%d",&x);
	mp[x]++;
    }
   int cnt = 0 ;
   int sum = n*n-n;
   for ( it=mp.begin();it!=mp.end();it++)
    {
	int tmp = it->second;
//	cout<<"tmp:"<<tmp<<endl;
      if ( tmp %2==1)
	{
	    cnt++;
	    cout<<it->first;
	    if (cnt!=n) cout<<" ";
	    it->second--;
	}
    }
  //  cout<<"cnt:"<<cnt<<endl;
 //  for (it=mp.begin();it!=mp.end();it++)
 //   {
//	int tmp = it->second;
//	if (sum-tmp>=0)
//	{
//	    sum = sum - tmp;
//	    
//	}
//	else
//	{
//	    it2=it;
//	
//	    
//	    
//	}
 //   }
    map<int,int>::reverse_iterator rit;
   for (rit=mp.rbegin();rit!=mp.rend();rit++)
    {
	int tmp = rit->second;
//	cout<<"tmp:"<<tmp<<endl;
	for ( int i = 1 ; i <= (tmp+1)/2 ; i++)
	{
	    if (cnt<n)
	    {
		cnt++;
		cout<<rit->first;
		if (cnt!=n)
		    cout<<" ";
	    }
	    else
	    {
		break;
	    }
	}
	if (cnt==n) break;
    }
 //  cout<<"cnt::"<<cnt<<endl;
  // for ( it=mp.begin();it!=mp.end();it++) 
 //  for ( int i = 1 ; i < cnt ; i++)
 //   {
//	printf("%d ",ans[i]);
  //  }
//
  //  printf("%d",ans[cnt]);

  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
