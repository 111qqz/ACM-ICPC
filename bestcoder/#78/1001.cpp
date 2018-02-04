/* ***********************************************
Author :111qqz
Created Time :2016年04月02日 星期六 18时55分44秒
File Name :code/bc/#78/1001.cpp
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
unsigned long long a[10];

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	ios::sync_with_stdio(false);
	cin>>T;
	while (T--)
	{
	    for ( int i = 1 ; i <= 4 ; i++) cin>>a[i];
	    sort(a+1,a+5);
	    if (a[1]==0)
	    {
		cout<<"No"<<endl;
		continue;
	    }
	    unsigned long long sum;
	    sum = a[1]+a[2];
	    if (sum>a[4]) 
	    {
		cout<<"Yes"<<endl;
		continue;
	    }
	    sum = sum + a[3];
	    if (sum>a[4])
	    {
		cout<<"Yes"<<endl;
		continue;
	    }
	    cout<<"No"<<endl;
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
