/* ***********************************************
Author :111qqz
Created Time :2017年11月17日 星期五 22时42分04秒
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
const int N=1E6+7;
int p[N];
int L[N];
int n;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	cin>>n;
	ms(p,0);
	for ( int i = 1 ; i <= n ; i++) scanf("%d",&L[i]);
	for ( int i = 2 ; i <= n ; i++)
	{
	    int l = max(1,i-L[i]);
	    int r =  i - 1;
	    p[l]+=1;
	    p[r+1]-=1;
	}
	for ( int i = 1 ; i <= n ; i++) p[i]+=p[i-1];

	int ans = 0;
	for ( int i = 1 ; i <= n ; i++) if (p[i]==0) ans++;
	cout<<ans<<endl;


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
