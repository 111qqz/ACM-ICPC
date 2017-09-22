/* ***********************************************
Author :111qqz
Created Time :2016年01月23日 星期六 18时56分38秒
File Name :code/bc/#69/1001.cpp
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
int a,b,c;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	int T;
	cin>>T;
	while (T--)
	{
	    bool isswap = false;
	    scanf("%d %d %d",&a,&b,&c);
	    if (c%2==1)
	    {
		puts("Impossible");
		continue;
	    }
	    c/=2;
	    if (a>b)
	    {
		swap(a,b);
		isswap = true;
	    }
	    bool ok = false;
	    for ( int i =  0 ; i*a<=c ;i++)
	    {
		for ( int j = 0 ; i*a+j*b <= c ; j++)
		{
		    if (i*a+j*b==c)
		    {
			ok = true;
			if (isswap) cout<<j*2<<" "<<i*2<<endl;
			    else cout<<i*2<<" "<<j*2<<endl;
			break;
		    }
		}
		if (ok) break;
	    }
	    if (!ok)
	    {
		puts("Impossible");
	    }
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
