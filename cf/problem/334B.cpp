/* ***********************************************
Author :111qqz
Created Time :2016年03月31日 星期四 13时39分27秒
File Name :code/cf/problem/334B.cpp
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
pi a[N];
set< pi >se;

bool solve()
{
    if (a[1].fst==a[2].fst&&a[2].fst==a[3].fst&&a[3].fst!=a[4].fst&&a[4].fst==a[5].fst&&a[5].fst!=a[6].fst&&a[6].fst==a[7].fst&&a[7].fst==a[8].fst&&a[1].sec==a[4].sec&&a[4].sec==a[6].sec&&a[3].sec==a[5].sec&&a[5].sec==a[8].sec&&a[1].sec!=a[2].sec&&a[2].sec==a[7].sec) return true;
    return false;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	
	for ( int i = 1 ; i <= 8 ; i++)
	{
	    cin>>a[i].fst>>a[i].sec;
	    se.insert(a[i]);
	}
	sort(a+1,a+9);
	if (solve())
	{
	    puts("respectable");
	}
	else
	{
	    puts("ugly");
	}


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
