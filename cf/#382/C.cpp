/* ***********************************************
Author :111qqz
Created Time :2016年11月29日 星期二 10时16分50秒
File Name :code/cf/#382/C.cpp
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
unsigned  long long n;
unsigned long long x,y,z;
unsigned long long solve( unsigned long long xx)
{
	if (xx<=2) return 1;
	if (xx<=4) return 2;
	x = 1;
	y = 2;
	int p;
	unsigned long long cur = 4;
	for ( int i = 3 ; ; i++)
	{
	    z = x + y;
	 //   cout<<"x:"<<x<<" y:"<<y<<" z:"<<z<<endl;
	    x = y;
	    y = z;
	    cur = cur + z;
	    if (cur>=xx)
	    {
		 p = i;
		 break;
	    }
	}
	//cout<<p<<endl;
	return p;

}
int main()
{
	#ifndef  ONLINE_JUDGE 
//	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n;
	unsigned long long ans = solve(n);
	cout<<ans<<endl;


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
