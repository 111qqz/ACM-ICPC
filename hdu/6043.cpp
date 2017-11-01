/* ***********************************************
Author :111qqz
Created Time :2017年11月01日 星期三 00时14分38秒
File Name :6043.cpp
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
LL n,k;
int main()
{
	#ifndef  ONLINE_JUDGE 
	//freopen("./in.txt","r",stdin);
  #endif
	int cas = 0 ;
	while (~scanf("%lld %lld",&n,&k))
	{
	    printf("Case #%d: ",++cas);
	    if (k<=n)
	    {
		printf("%lld\n",k);
		continue;
	    }
	    k-=n;
	    LL num = (k-1)/(n-1)+1;
	    LL yu = k%(n-1);
	    if (yu==0) yu+=n-1;
	    if (num%2==1)
	    {
		printf("%lld\n",yu);
	    }
	    else
	    {
		if (yu<=n-2) printf("%lld\n",yu);
		else printf("%lld\n",n);
	    }
	}



  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
