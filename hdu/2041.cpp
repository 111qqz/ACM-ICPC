/* ***********************************************
Author :111qqz
Created Time :2016年07月27日 星期三 20时39分49秒
File Name :code/hdu/2041.cpp
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
const int M=45;
LL f[M];
int m;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	f[1] = 1;
	f[2] = 1;
	for ( int i =3 ; i < M ; i++) f[i] = f[i-1] + f[i-2];

	int T;
	cin>>T;
	while (T--)
	{
	    scanf("%d",&m);
	    printf("%lld\n",f[m]);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
