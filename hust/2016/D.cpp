/* ***********************************************
Author :111qqz
Created Time :2016年05月28日 星期六 13时22分19秒
File Name :code/hust/2016/D.cpp
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
const int N=7E4+7;
int l,r;
int solve ( int x)
{
    int res  = 0;
    if (x>=1) res--;
 //   cout<<res<<endl;
    if (x>=3) res--;
//    cout<<res<<endl;
    if (x>=4) res--;
//    cout<<res<<endl;
    if (x>=6) res--;
 //   cout<<res<<endl;  //傻逼了。。。wori....
    res += x;

    return res;

}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	while (~scanf("%d %d",&l,&r))
	{
	 //   int a1 = solve(r);
	 //   int b1 = solve(l-1);
	 //   cout<<"a1:"<<a1<<" b1:"<<b1<<endl;
	    int ans = solve(r)-solve(l-1);

	    printf("%d\n",ans);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
