/* ***********************************************
Author :111qqz
Created Time :2016年03月12日 星期六 18时14分27秒
File Name :code/bc/#75/1001.cpp
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
int cnt;
int n,m;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	int T;
	cin>>T;
	while (T--)
	{
	    cnt = 0 ;
	    scanf("%d %d",&n,&m);

	    while (1)
	    {
		if (n<m)
		{
		    int num = m/n;
		    m-=num*n;
		    cnt +=num;
		}
		else
		{
		    int num = n/m;
		    n-=num*m;
		    cnt+=num;
		}
		if (n==0||m==0) break;
	    }
	    printf("%d\n",cnt);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
