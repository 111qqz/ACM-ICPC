/* ***********************************************
Author :111qqz
Created Time :2017年10月26日 星期四 23时03分02秒
File Name :B.cpp
************************************************ */

#include <bits/stdc++.h>
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
const int N=505;
int n;
LL k;
int a[N];
int cnt[N]={};
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	cin>>n>>k;
	int mx = 0 ;
	int mxpos = 0;
	for ( int i = 1 ; i <= n ; i++)
	{
	    cin>>a[i];
	    if (a[i]>mx)
	    {
		mx = a[i];
		mxpos = i;
	    }
	}
	if (k>=mxpos-1)
	{
	    cout<<mx<<endl;
	    return 0;
	}
	int j = 2;
	bool ok = true;
	for ( int i = 1 ; i <= n ; i++)
	{

	    if (j>n) break;
	    if (a[1]>a[j])
	    {
		cnt[a[1]]++;
		j++;
	    }
	    else
	    {
		a[1] = a[j];
		cnt[a[1]]++;
		j++;
	    }
	    if (cnt[a[1]]>=k)
	    {
		ok = true;
		break;
	    }
	}
	if (!ok) cout<<mx<<endl;
	else 
	    cout<<a[1]<<endl;
	    

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
