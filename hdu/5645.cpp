/* ***********************************************
Author :111qqz
Created Time :2016年03月22日 星期二 19时27分40秒
File Name :code/hdu/5645.cpp
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
const int N=305;
int n;
int a[N];
int cnt[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
//	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
	    ms(cnt,0);
	    cin>>n;
	    for ( int i = 0 ; i < n ; i++)
	    {
		cin>>a[i];
		cnt[a[i]]++;
	    }
	    int cur = 0 ;
	    int fz = 0 ;
	    for ( int i = 1 ; i <= 300 ; i++)
	    {
		if (cnt[i]==0) continue;
		fz +=cnt[i]*cur;
		cur +=cnt[i];
		//cout<<"fz:"<<fz<<endl;
	    }
	    
	    int fm = n*(n-1)/2;
	    double ans = fz*0.5/(1.0*fm);
	    printf("%.6f\n",ans);
    	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
