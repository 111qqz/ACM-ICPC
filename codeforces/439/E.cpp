/* ***********************************************
Author :111qqz
Created Time :2017年10月24日 星期二 18时02分41秒
File Name :E.cpp
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
#define PB push_back
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
const int N=2503;
int n,m,q;
int px[N],py[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif

	ms(px,0);
	ms(py,0);
	cin>>n>>m>>q;
	while (q--)
	{
	    scanf("%d%d%d%d%d",&opt,&r1,&r2,&c1,&c2);
	    if (opt==1)
	    {
		px[r1] += c2;
		px[r2+1] -= -c2; //维护上边界

		py[c1] += r1;
		py[c2+1] -= r1; //维护左边界
	    }else if (opt==2)
	    {
		px[r1]-=c2;
		px[r2+1]+=c2;

		py[c1]-=r1;
		py[c2+1]+=r1;
	    }
	    else
	    {


	    }
	    prset(X);
//	    prset(Y);
	}



  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
