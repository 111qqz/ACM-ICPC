/*************************************************************************
	> File Name: code/2015summer/#2/K.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: Fri 24 Jul 2015 01:08:16 PM CST
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
const int N=1E2+5;
char st[N],str[N];
int main()
{
    int n;
    cin>>n;
    int p = 0;
    for ( int i = 1 ; i <= n ; i++)
    {
	  cin>>st[i];
    }
    int fst,alast;
    LL ans1=0,ans2=0;
    LL ans = 0;
    for ( int i =1 ; i <= n ; i++ )
    {
	  if (st[i]=='F'&&st[i+1]=='A')
	  {
		swap(st[i],st[i+1]);
		ans++;
	  }
    }   
    for ( int i = n ; i >= 1 ; i--)
    {
	  if (st[i]=='A'&&st[i-1]=='F')
	  {
		swap(st[i],st[i-1]);
		ans++;
	  }
     }
    for ( int i = 1 ; i<= n ; i++)
    {
	  if (st[i]=='F')
	  {
		fst = i;
		break;
	  }
    }
    for  ( int i = n ; i >= 1 ; i-- )
    {
	  if (st[i]=='A')
	  {
		alast = i ;
		break;
	  }
    }
    //for ( int i =1 ; i <= n ; i ++)
//	  cout<<st[i];
    memcpy(str,st,sizeof(st));
    for ( int i = alast-1 ; i >= 1 ; i-- )
    {
	//  if (i>alast) break;  ///最后一个A后面的f对答案没贡献
	  if (st[i]=='F')
	  {
		ans1 = ans1 + (alast-i);
		alast--;
	  }
    }
    for ( int i = fst+1 ; i <=n ; i++)
    {
	  if (st[i]=='A')
	  {
		ans2 = ans2+ (i-fst);
		//cout<<"ans2:"<<ans2<<endl;
		fst++;
	  }
    }
    cout<<ans+min(ans1,ans2)<<endl;
    return 0;
}

