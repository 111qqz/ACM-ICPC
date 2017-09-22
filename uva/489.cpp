/*************************************************************************
	> File Name: code/uva/489.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年09月23日 星期三 19时34分34秒
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
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define ms(a,x) memset(a,x,sizeof(a))
#define lr dying111qqz
using namespace std;
#define For(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;
const int N=30;
int a[N];
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif
    int cas;
    while (scanf("%d",&cas)!=EOF)
    {
	if (cas==-1) break;
	ms(a,0);
	printf("Round %d\n",cas);
	
	string st1,st2;
	cin>>st1>>st2;
	int len1 = st1.length();
	for ( int i = 0 ; i < len1 ; i++)
	{
	    int tmp = st1[i]-'a';
	    a[tmp]++;
	}
	int len2 = st2.length();
	int cnt = 0 ;
	int sum = 0 ;
	int state = 0;
	for ( int i = 0 ; i < len2 ; i++)
	{
	    int tmp = st2[i]-'a';
	    if (a[tmp]==0)
	    {
		cnt++;
	    }
	    else
	    {
		sum += a[tmp];
		a[tmp] =  0;
	    }
	    if (cnt>=7) break;
	    if (sum==len1)
	    {
		state = 1;
		break;
	    }
	}
	if (state ==1)
	{
	    puts("You win.");
	    continue;
	}
//	cout<<"cnt:"<<cnt<<endl;
	if (cnt<7)
	{
	    puts("You chickened out.");
	}
	else
	{
	    puts("You lose.");
	}
    }
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
