/* ***********************************************
Author :111qqz
Created Time :2016年02月27日 星期六 15时56分31秒
File Name :code/hdu/2082.cpp
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
const int N=1E4;
LL a[N],tmp[N];
int x[N];
int n;
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
	    for ( int i = 1; i <= 26 ; i ++) cin>>x[i];

	    ms(tmp,0);
	    ms(a,0);
	    for ( int i = 0 ; i <= x[1]; i++)
	    {
		a[i]  = 1;
	    }
	 //   cout<<"aaa"<<endl;
	    int cur = x[1]*1;
	    for ( int i = 2 ; i <= 26 ; i++)
	    {
		for ( int j =  0 ; j<= cur ; j++)
		{
		    for ( int k =  0 ; k <= x[i] ; k++)
		    {
			tmp[j+i*k]+=a[j];
		    }
		}

		cur += x[i]*i;

	//	cout<<"bbb:"<<endl;

		for ( int j = 0 ;  j <= cur ; j++)
		{
		    a[j] = tmp[j];
		    tmp[j] = 0 ;
		}
	    }
	  //  cout<<"asdsad"<<endl;
	    LL ans = 0LL ;
	    for ( int j = 1 ; j <= 50 ; j++)
	    {
		ans += a[j];
	    }
	    cout<<ans<<endl;
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
