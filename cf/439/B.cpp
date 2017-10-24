/* ***********************************************
Author :111qqz
Created Time :2017年10月24日 星期二 15时33分57秒
File Name :B.cpp
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
LL a,b;
LL solve( LL x,LL y)
{
    if (x==y) return 1;
    LL tmp =y-x;
    if (tmp==1) return y%10;
    if (tmp==2) return y%10*(y-1)%10;
    if (tmp==3) return y%10*(y-1)%10*(y-2)%10;
    if (tmp==4) return y%10*(y-1)%10*(y-2)%10*(y-3)%10;
    return 0;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
//	freopen("./in.txt","r",stdin);
  #endif
	cin>>a>>b;
	LL ans = solve(a,b);
	cout<<ans<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
