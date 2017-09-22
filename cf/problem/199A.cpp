/* ***********************************************
Author :111qqz
Created Time :Sun 02 Oct 2016 09:43:28 PM CST
File Name :code/cf/problem/199A.cpp
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
int n;
int f[100000];
map<int,int>mp;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	f[0] = 0LL;
	f[1] = 1LL;
	cin>>n;
	for ( int i = 2 ; f[i]<= n ; i++)
	{
	    if (f[i-2]>500000000) break;
	    f[i] = f[i-1] + f[i-2];
	    
	    mp[f[i]] = i;
	}

	if (n==0)
	    puts("0 0 0");
	else if (n==1) puts("0 0 1");
	else if (n==2) puts("0 1 1");
	else if (n==3) puts("1 1 1");
	else
	{
	    int k = mp[n];
	    printf("%d %d %d\n",f[k-2],f[k-2],f[k-3]);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
