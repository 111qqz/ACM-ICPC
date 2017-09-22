/* ***********************************************
Author :111qqz
Created Time :2016年04月22日 星期五 19时00分08秒
File Name :code/hdu/#81/1001.cpp
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
int m;
 long long n;
int col[35];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	int T;
	cin>>T;
	while (T--)
	{
	    cin>>m>>n;
	    ms(col,0);
	     long long p = 1;
	    for ( int i = 1 ; i <= m ; i++) p=p*3;
	    n = n % p;
	    int cnt = 0 ;
	    while (n>0)
	    {
		col[++cnt]=n%3;
		n/=3;
	    }

	    for ( int i = m ; i >=1  ;i--)
	    {
		if (col[i]==0) cout<<"R";
		if (col[i]==1) cout<<"G";
		if (col[i]==2) cout<<"B";
	    }
	    cout<<endl;


	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
