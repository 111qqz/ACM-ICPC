/* ***********************************************
Author :111qqz
Created Time :2017年10月26日 星期四 12时23分09秒
File Name :J.cpp
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

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	cin>>n;
	int ans =  0;
	int tmp = 1<<8;
	for ( int i = 1 ; i <= n ; i++)
	{
	    int x;
	    scanf("%d",&x);
	    for ( int j = 1 ; j <= 4 ; j++)
	    {
		int r = x % tmp;
		if (r==97) ans++;
		x/=tmp;
	    }
	}
	cout<<ans<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
