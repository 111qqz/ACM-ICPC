/* ***********************************************
Author :111qqz
Created Time :2017年10月26日 星期四 22时43分14秒
File Name :A.cpp
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
const int N=1E3+7;
int n;
int s[N],d[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	cin>>n;
	for ( int i = 1 ; i <= n ; i++) cin>>s[i]>>d[i];

	int lst = 0 ;
	int cur = 0;
	for ( int i = 1 ; i <= n  ;i++)
	{
	    if (s[i]>cur) 
	    {
		cur = s[i];
	    }
	    else
	    {
		cur = (cur-s[i])/d[i] + 1;
		cur*=d[i];
		cur+=s[i];
	    }
	}	
	cout<<cur<<endl;


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
