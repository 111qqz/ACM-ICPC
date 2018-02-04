/* ***********************************************
Author :111qqz
Created Time :2016年03月31日 星期四 14时23分39秒
File Name :code/cf/problem/484B.cpp
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
int b[2*N];
int n ;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n;
	ms(b,-1);//b[i]表示比小于等于a[i]的元素里最大的。
	for ( int i = 1 ; i <= n ; i++)
	{
	    int x;
	    cin>>x;
	    b[x] = x;
	}
	for ( int i = 1 ; i <2*N ; i++) if (b[i]==-1) b[i] = b[i-1];
//	for ( int i = 1 ; i <= 20 ;  i++) cout<<b[i]<<" ";
	int ans = 0 ;
	for ( int j = 1 ; j < N ; j++)
	    if (b[j]==j)
		for ( int i = j-1 ; i < 2*N ; i+=j)
		    if (j<=b[i]&&ans<b[i]%j) ans = b[i] % j ;

	cout<<ans<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
