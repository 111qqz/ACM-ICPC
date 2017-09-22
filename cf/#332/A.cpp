/* ***********************************************
Author :111qqz
Created Time :2015年12月23日 星期三 15时24分26秒
File Name :code/cf/#332/A.cpp
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
LL d1,d2,d3;
LL ans;
LL a[10];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>d1>>d2>>d3;
	a[0] = (d1+d2)*2;
	a[1] = d1+d2+d3;
	a[2] = d3*2+2*d2;
	a[3] = d1*2+d3*2;
	sort(a,a+4);
	cout<<a[0]<<endl;
	

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
