/* ***********************************************
Author :111qqz
Created Time :2016年02月29日 星期一 20时40分00秒
File Name :code/hdu/1205.cpp
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
int n;
LL a[N];
LL total;

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
	    cin>>n;
	    total =  0;
	    for ( int i = 1 ; i <= n ; i++)
	    {
		cin>>a[i];
		total +=a[i];
	    }



	    bool ok = true;
	    for ( int i = 1 ; i <= n ;  i++)
	    {
		LL x;
		x= total-a[i];
		if (x<a[i]-1)
		{
		    ok = false;
		    break;
		}
	    }

	    if (ok)
	    {
		puts("Yes");
	    }
	    else
	    {
		puts("No");
	    }

	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
