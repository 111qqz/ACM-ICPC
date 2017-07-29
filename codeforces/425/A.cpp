/* ***********************************************
Author :111qqz
Created Time :Mon 24 Jul 2017 10:26:48 PM CST
File Name :A.cpp
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
#define PB push_back
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
int solve(LL n,LL k)
{
    LL tmp = n/k;
    if (tmp%2==1)
    {
	if (n%k==0) puts("YES");
	else puts("NO");
    }
    return 0;
}

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
    LL n,k;
    cin>>n>>k;
    LL tmp = n/k;
    if (tmp%2==0) puts("NO");
    else puts("YES");
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
