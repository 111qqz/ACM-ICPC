/* ***********************************************
Author :111qqz
Created Time :2017年11月17日 星期五 22时30分56秒
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
const int N=1E5+7;
int n;
int a[N],b[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	cin>>n;
	LL sum = 0 ;
	for ( int i = 1 ; i <= n ; i++) {cin>>a[i];sum = sum + a[i];}
	for ( int i = 1 ; i <= n ; i++) cin>>b[i];
	sort(b+1,b+n+1);
	if (b[n]+b[n-1]>=sum)
	{
	    puts("YES");
	}
	else
	{
	    puts("NO");
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
