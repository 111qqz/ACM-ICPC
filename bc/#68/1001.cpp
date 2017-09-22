/* ***********************************************
Author :111qqz
Created Time :2016年01月02日 星期六 18时56分10秒
File Name :code/bc/#68/1001.cpp
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
LL x,y;
LL b;
LL dis(LL a1,LL b1,LL a2,LL b2)
{
    LL res = (a1-a2)*(a1-a2)+(b1-b2)*(b1-b2);
    return res;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
//	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	while (T--)
	{
	    scanf("%lld %lld",&x,&y);
	    b = x + y;
	    LL ans;
	    ans = dis(x,y,0,b)*dis(x,y,b,0);
	    cout<<LL(sqrt(ans))<<endl;

	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
