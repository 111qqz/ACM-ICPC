 /*************************************************************************
	> File Name: code/bc/#ann/1002.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com
	> Created Time: 2015年07月25日 星期六 18时54分35秒
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
int d[N];
int len;
int cnt;
string st,tar,s1[N],s2[N],s3[N];
bool flag;

void solve (string x,string y,string z)
{
  //  cout<<x<<"+"<<y<<"+"<<z<<endl;
    int lx = x.length();
    int ly = y.length();
    int lz = z.length();
    int p;
    int k = 0;
    for ( int i = 0 ; i  <= len-11 ; i++ )
    {
	string tmps = st.substr(i,lx);

	if (tmps==x)
	{
	    p = i;
	    k++;
	    break;
	}
    }
    if (k==0) return;

    for ( int i =  p+lx ;  i <= len - 11 + lx ;i++)
    {
	string tmps = st.substr(i,ly);

	if (tmps==y)
	{
	    p = i ;
	    k++;
	    break;
	}
    }
    if (k==1) return ;
    for ( int i = p+ly;  i <=len - 11+lx+ly ; i ++)
    {
	string tmps = st.substr(i,lz);
	if (tmps==z)
	{
	    k++;
	    break;
	}
    }
    if (k==3)
    {
	flag = true;
	return;
    }

}
int main()
{
    int T;
    tar = "anniversary";
    cnt =0;
    for ( int i = 1 ; i <= 9 ; i++ )
    {
	for ( int j = i +1 ; j<= 10 ; j++ )
	{
	    cnt++;
	    s1[cnt] = tar.substr(0,i);
	    s2[cnt] = tar.substr(i,j-i);
	    s3[cnt] = tar.substr(j);
	    
	}
    }
    cin>>T;
    while (T--)
    {
	  flag = false;
	  cin>>st;
	  len = st.length();
	  int k = 0;
	  int num = 0;
	  
	  for ( int i = 1;  i <= cnt  ; i++ )
	  {

	      solve(s1[i],s2[i],s3[i]);
	  } 
	  if (flag)
	    {
		cout<<"YES"<<endl;
	    }
	  else
	    {
		cout<<"NO"<<endl;
	    }

    }

	return 0;
}
