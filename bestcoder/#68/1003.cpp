/* ***********************************************
Author :111qqz
Created Time :2016年01月02日 星期六 18时56分31秒
File Name :code/bc/#68/1003.cpp
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

int cal( int x)
{
    return x*x-3*x+2;
}
void pre()
{
    for ( int i = 1 ; i <= 20 ; i++)
    {
	cout<<"i:"<<i<<" ans:"<<cal(i)<<endl;
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	pre();

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
