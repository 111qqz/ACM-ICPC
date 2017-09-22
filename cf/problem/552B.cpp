/* ***********************************************
Author :111qqz
Created Time :2015年12月14日 星期一 13时46分32秒
File Name :code/cf/problem/552B.cpp
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
LL nine[30];
LL ten[30];
LL n;
void pre()
{
    nine[1] =  9;
    ten[1] = 9;
    for ( int i = 2 ; i <= 10 ; i++)
    {
	nine[i] = nine[i-1]*10+9;
	ten[i] = ten[i-1]*10;
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	pre();
	cin>>n;
	int cnt = 1;
	LL ans = 0 ;
	while (n>nine[cnt]) cnt++;
	for ( int i = 1 ; i <= cnt-1 ; i ++)
	{
	    ans+= i*ten[i];
	}
//	cout<<"cnt:"<<cnt<<endl;
	ans+=(n-nine[cnt-1])*cnt;
	
	cout<<ans<<endl;


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
