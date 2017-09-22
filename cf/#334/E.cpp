/* ***********************************************
Author :111qqz
Created Time :2015年12月22日 星期二 14时29分05秒
File Name :code/cf/#334/E.cpp
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
int n,k,res;
int pre[5]={0,1,0,1,2};

int grundy( int a)
{
    if (k%2==0)
    {
	if (a==1) return 1;
	if (a==2) return 2;
	return (a%2)^1;
    }
    else
    {
	if (a<5) return pre[a];
	if (a%2==1) return 0;
	return (grundy(a/2)==1?2:1);
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	cin>>n>>k;
	for ( int i = 0 ; i < n; i++)
	{
	    int x;
	    cin>>x;
	    res ^= grundy(x);
	}
	if (res!=0)
	{
	    puts("Kevin");
	}
	else
	{
	    puts("Nicky");
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
