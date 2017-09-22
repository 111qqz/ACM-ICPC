/* ***********************************************
Author :111qqz
Created Time :2016年03月31日 星期四 18时23分16秒
File Name :code/bzoj/1600.cpp
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
const int N = 2600;
LL n;

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n;
	LL ans = (n-1)*(n-2)*(n-3)/6;
	LL sad = 0LL;
	for ( LL i =n/2  ; i >= 3 ; i--)
	{
	    sad = sad + ((i-1)*(i-2)/2)*4;  //C(i-1,2) ，*4是因为每个点都有可能作为最大点。
	}
//	cout<<"ans:"<<ans<<endl;
//	cout<<"sad:"<<sad<<endl;
	ans -=sad;
	cout<<ans<<endl;
	

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
