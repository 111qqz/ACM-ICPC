/* ***********************************************
Author :111qqz
Created Time :2016年01月28日 星期四 19时57分44秒
File Name :code/uva/846.cpp
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
int x,y;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	int T;
	cin>>T;
	while (T--)
	{
	    scanf("%d %d",&x,&y);
	    int step = 1;
	    int len = y-x;
	    int x = 0;
	    int ans = 0 ;
	    while (len>0)    //思路关键：从两边往中间走。
	    {
		len-=step;
		ans++;
		if (x) step++;
		x ^=1;
	    }
	    cout<<ans<<endl;

	    

	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
