/*************************************************************************
	> File Name: code/0919/1010.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年09月19日 星期六 13时19分35秒
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
const int N=1E5+7;
string str[N];
int main()
{
  #ifndef  ONLINE_JUDGE 
   // freopen("in.txt","r",stdin);  
  #endif
  //  freopen("out.txt","w",stdout );    
    str[1] = "c";
    str[2] = "ff";
  cout<<"yeah"<<endl;
  for ( int i = 3 ; i <= 30 ; i++)
    {
	str[i] = str[i-2]+ str[i-1];
	
    }
  for ( int i = 1; i <= 10 ; i++)
    {
	cout<<i<<": "<<str[i]<<endl;
    }
  LL ans = 0 ;
  for ( int i = 7 ; i <=7 ; i ++)
    {
	int len = str[i].length();
	int sum = 0 ;
	int cnt =  0;
	int p = -1;
	for ( int j = 0 ; j < len  ;j++)
	{
	    if (str[i][j]=='c')
	    {
		cnt++;
	    }
	}
	cnt--;
	for ( int j = 0 ; j < len ; j++)
	{
	    if (str[i][j]=='c')
	    {
		if (p==-1)
		{
		    p = j;
		}
		else
		{
		    
		    sum = sum + (j-p)*cnt;
	//	    cout<<"sum:"<<sum<<endl;
		    p = j;
		}
	    }
	}
	cout<<"sum:"<<sum<<endl;
    }
  

  
  
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
