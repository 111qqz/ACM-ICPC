/* ***********************************************
Author :111qqz
Created Time :2016年03月31日 星期四 21时13分18秒
File Name :code/bzoj/1599.cpp
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
int s1,s2,s3;
double a[100];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>s1>>s2>>s3;
	ms(a,0);
	for ( int i = 1 ;i  <= s1 ; i++)
	{
	    for ( int j = 1 ; j <= s2 ; j++)
	    {
		for ( int k = 1 ; k <= s3 ; k++)
		{
		    a[i+j+k] += 1.0/s1+1.0/s2+1.0/s3;
		}
	    }
	}

	double p = -1;
	int ans ;
	for ( int i = 3 ; i <= s1+s2+s3 ; i++)
	{
	    if (a[i]>p)
	    {
		p = a[i];
		ans = i ;
	    }
	}
    
	cout<<ans<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
