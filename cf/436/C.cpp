/* ***********************************************
Author :111qqz
Created Time :2017年10月25日 星期三 12时29分16秒
File Name :C.cpp
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
int a,b,f,k;
int solve()
{
    if (k==1)
    {
	if (b<(a-f)||b<f) return -1;
	if (b-f<a-f) return 1;
	else return 0;
    }
    if (k==2)
    {
	if (b<f||b<2*(a-f)) return -1;
	int ret = 0 ;
	if (b-f<2*(a-f)) ret++;
	if (ret==1&&b-2*(a-f)<f) ret++;
	if (ret==0&&b-f-2*(a-f)<f) ret++;
	return ret;
    }

    if (b<2*f||b<2*(a-f)) return -1;
    int ret = 0 ;
    int cur = b;
    //最后一次不用判断回来
    for ( int i = 1 ; i <= k ; i++)
    {

	if (i==k)
	{
	    if (i%2==1)
	    {
		cur-=f;
		if (cur<a-f)
		{
		    cur-=b-(a-f);
		    ret++;
		}
		else
		{
		    cur-=(a-f);
		}
	    }
	    else
	    {
		cur-=(a-f);
		if (cur<f)
		{
		    ret++;
		}
	    }
	    continue;
	}
	if (i%2==1)
	{
	    cur-=f;
	    if (cur<2*(a-f))
	    {
		cur = b-(a-f);
		ret++;
	    }
	    else
	    {
		cur-=(a-f);
	    }
	}else if (i%2==0)
	{
	    cur-=(a-f);
	    if (cur<2*f)
	    {
		cur = b-f;
		ret++;
	    }
	    else
	    {
		cur-=f;
	    }
	}
	//printf("i:%d ret:%d\n",i,ret);
    }
    return ret;
}



int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	cin>>a>>b>>f>>k;
	int ans = solve();
	printf("%d\n",ans);

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
