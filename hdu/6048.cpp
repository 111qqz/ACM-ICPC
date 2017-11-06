/* ***********************************************
Author :111qqz
Created Time :2017年11月06日 星期一 18时45分04秒
File Name :6048.cpp
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
int n,m,p;
int tot;
LL ans;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	while (T--)
	{
	    scanf("%d %d %d",&n,&m,&p);
	    int tot = n*m-1;
	    ans = 0;
	    while (tot>p)  //when tot<p,the ans is 1
	    {
		int num = (tot-1)/p+1;
		LL tmp = num*(num-1)/2*(p-1);
		ans = ans + tmp;
		tot-=num;
	    }
	    printf("%s\n",ans%2?"No":"Yes");
	}
	

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
