/* ***********************************************
Author :111qqz
Created Time :2015年12月11日 星期五 15时01分01秒
File Name :code/cf/problem/148A.cpp
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
int k,l,m,n,d;
bool v[100005];

void solve()
{
    cin>>k>>l>>m>>n>>d;
    if (k==1||l==1||m==1||n==1) 
    {
	cout<<d<<endl;
	return ;
    }
    for ( int i = 1 ; i <= d ; i++)
    {
	if (i%k==0||i%l==0||i%m==0||i%n==0) v[i]= true;
    }
    int cnt = 0 ;
    for ( int i = 1 ; i <= d ; i++)
	if (v[i]) cnt++;
    cout<<cnt<<endl;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	ms(v,false);
	solve();

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
