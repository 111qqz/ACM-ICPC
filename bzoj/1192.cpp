/* ***********************************************
Author :111qqz
Created Time :2016年11月28日 星期一 15时31分21秒
File Name :code/bzoj/1192.cpp
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
int two[60];
int main()
{
	#ifndef  ONLINE_JUDGE 
//	freopen("code/in.txt","r",stdin);
  #endif
	int m;	
	cin>>m;
	int cnt = 0 ;
	while (m)
	{
	    m = m >> 1;
	    cnt++;
	}
	cout<<cnt<<endl;


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
