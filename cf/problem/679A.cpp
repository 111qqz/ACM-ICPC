/* ***********************************************
Author :111qqz
Created Time :Sun 02 Oct 2016 08:22:44 PM CST
File Name :code/cf/problem/679A.cpp
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
int prime[19]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,4,9,25,49};
string st;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int cnt = 0 ;
	for ( int i = 0 ; i < 19 ; i++)
	{
	    cout<<prime[i]<<endl;
	    fflush(stdout);
	    cin>>st;
	    if (st=="yes") cnt++;
	}
	if (cnt>=2) puts("composite");
	else puts("prime");
	fflush(stdout);
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
