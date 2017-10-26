/* ***********************************************
Author :111qqz
Created Time :2017年10月25日 星期三 19时02分12秒
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
int n;
string st;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	cin>>n;
	cin>>st;
	int cnt1=0,cnt2=0;
	for ( int i = 1 ; i < n ; i++)
	{
	    if (st[i-1]=='F'&&st[i]=='S') cnt2++;
	    if (st[i-1]=='S'&&st[i]=='F') cnt1++;
	}
//	cout<<cnt1<<" "<<cnt2<<endl;
	if (cnt1>cnt2) puts("YES");
	else puts("NO");

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
