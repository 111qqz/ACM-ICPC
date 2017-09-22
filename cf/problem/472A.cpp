/* ***********************************************
Author :111qqz
Created Time :2015年12月11日 星期五 15时36分01秒
File Name :code/cf/problem/472A.cpp
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
const int N=1E6+7;
bool pri[N];
int n ;
bool prime ( int n)
{
    if (n<=3) return true;
    for ( int i = 2 ; i *i <= n ;i++)
    {
	if (n%i==0) return false;
    }
    return true;
}

void pre()
{
    ms(pri,false);
    for ( int i = 2; i < N ; i++)
    {
	if (prime(i))
	{
	    pri[i] = true;
	}
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	pre();
	cin>>n;
	for ( int i =4 ; i <= n ;i++)
	{
	    if (!pri[i]&&!pri[n-i])
	    {
		cout<<i<<" "<<n-i<<endl;
		break;
	    }
	}
	

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
