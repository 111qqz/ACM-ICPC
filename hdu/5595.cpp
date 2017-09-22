/* ***********************************************
Author :111qqz
Created Time :2015年12月19日 星期六 22时39分36秒
File Name :code/hdu/5595.cpp
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
int a,b,c,l,r;

int cal(int x)
{
    return a*x*x+b*x+c;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	while (T--)
	{
	    
	    int mx = -inf;
	    int  mi = inf;
	    scanf("%d%d%d%d%d",&a,&b,&c,&l,&r);
	    for ( int i = l ; i <= r ; i++)
	    {
		 mx= max(mx,cal(i));
		 mi = min(mi,cal(i));
	    }
	    cout<<mx<<" "<<mi<<endl;
	    
	
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}

