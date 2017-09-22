/* ***********************************************
Author :111qqz
Created Time :2016年03月31日 星期四 21时04分09秒
File Name :code/bzoj/1603.cpp
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
const int N=1005;
int n;

struct node
{
    int s,d,c;
    
    bool operator < (node b)const
    {
	return s<b.s;
    }
}a[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n;
	for  ( int i = 1 ; i <= n-1 ; i ++) cin>>a[i].s>>a[i].d>>a[i].c;

	sort(a+1,a+n);
	int flag = 0;
	for ( int i = 1 ;i  <= n-1 ; i++)
	{
	    if (a[i].c==1) flag^=1;
	}
	cout<<flag<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
