/* ***********************************************
Author :111qqz
Created Time :2016年05月06日 星期五 18时05分33秒
File Name :code/cf/#350/B.cpp
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
int id[N];
LL n,k;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n>>k;
	for ( int i = 1 ; i <= n ; i++) cin>>id[i];

	LL p=0;
	for ( int i = 1  ; i <= n ; i++)
	{
	    if (i*(i+1)/2<k)
	    {
		p = i*(i+1)/2;
//		cout<<"pp:"<<p<<endl;
	    }
	    else break;
	}
	cout<<"k:"<<k<<" p:"<<p<<endl;
	k-=p;
//	if (k<=0) k = 1;
	cout<<id[k]<<endl;
	

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
