/* ***********************************************
Author :111qqz
Created Time :2016年03月27日 星期日 12时34分56秒
File Name :code/hust/20160327/A.cpp
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define fst first
#define sec second
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ms(a,x) memset(a,x,sizeof(a))
typedef long long LL;
#define pi pair < int ,int >
#define MP make_pair

using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
int n ;
int gcd ( int a, int b)
{
    if (a<b) return gcd(b,a);
    if (a%b==0) return b;
    return gcd(b,a%b);
}
string s1,s2;
int len1,len2;

bool draw( char a,char b)
{
    return a==b;
}
bool fwin( char a,char b)
{
    if (a=='R'&&b=='S') return true;
    if (a=='S'&&b=='P') return true;
    if (a=='P'&&b=='R') return true;
    return false;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	cin>>n;
	cin>>s1;
	cin>>s2;
	len1 = s1.length();
	len2 = s2.length();
	int GCD =gcd (len1,len2);
	int LCM = len1/GCD*len2;

	int cnt1=0,cnt2=0;
	for ( int i = 0 ;  i < LCM ; i++)
	{
	    char x = s1[i%len1];
	    char y = s2[i%len2];
	    if (!draw(x,y))
	    {
		if (fwin(x,y))
		{
		    cnt1++;
		}
		else
		{
		    cnt2++;
		}
	    }
	}

	int num = n / LCM;
	int ans1 = num*cnt1;
	int ans2 = num*cnt2;

	n = n % LCM;

	for ( int i = 0 ; i < n ; i++)
	{
	    char x= s1[i%len1];
	    char y= s2[i%len2];

	    if (draw(x,y)) continue;
	    if (fwin(x,y))
		ans1++;
	    else ans2++;

	}

	cout<<ans2<<" "<<ans1<<endl;
	
 


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
