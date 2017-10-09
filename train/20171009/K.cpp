/* ***********************************************
Author :111qqz
Created Time :2017年10月09日 星期一 15时44分00秒
File Name :K.cpp
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
int cal ( LL x )
{
    int ret;
    int cnt = 0 ;
    while (x)
    {
	ret = x % 10;
	if (ret==1) cnt++;
	x/=10;
    }
    return cnt;
}
string st;
LL good[]={1,199981,199982,199983,199984,199985,199986,199987,199988,199989,199990,200000,200001,1599981,1599982,1599983,1599984,1599985,1599986,1599987,1599988,1599989,1599990,2600000,2600001,13199998,35000000,35000001,35199981,35199982,35199983,35199984,35199985,35199986,35199987,35199988,35199989,35199990,35200000,35200001,117463825,500000000,500000001,500199981,500199982,500199983,500199984,500199985,500199986,500199987,500199988,500199989,500199990,500200000,500200001,501599981,501599982,501599983,501599984,501599985,501599986,501599987,501599988,501599989,501599990,502600000,502600001,513199998,535000000,535000001,535199981,535199982,535199983,535199984,535199985,535199986,535199987,535199988,535199989,535199990,535200000,535200001,1111111110};
const LL MAXGOOD = 1111111110;
int main()
{
	#ifndef  ONLINE_JUDGE 
//	freopen("./in.txt","r",stdin);
//	freopen("./out.txt","w",stdout);
  #endif 
	while (cin>>st)
	{
	    int len = st.length();
	    LL up=0;
	    if (len>10) up =MAXGOOD+1;
	    else 
	    for ( int i = 0 ; i< len ; i++)
	    {
		LL val = st[i]-'0';
		up = up * 10LL + val;
	//	cout<<"val:"<<val<<endl;
	    }
	    up++;
	 //   cout<<"up:"<<up<<endl;
	    int ans = lower_bound(good,good+83,up)-good;
	    cout<<ans<<" "<<good[ans-1]<<endl;
	}

    
  return 0;
}
