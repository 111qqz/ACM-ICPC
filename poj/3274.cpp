/* ***********************************************
Author :111qqz
Created Time :2016年11月30日 星期三 14时44分41秒
File Name :code/poj/3274.cpp
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
const int N=1E5+7;
const int inf = 0x3f3f3f3f;
int n,k;
int mod;
int a[N];
int sum[N];
map<int,int>mp;
int main()
{
#ifndef  ONLINE_JUDGE 
    freopen("code/in.txt","r",stdin);
#endif
    scanf("%d%d",&n,&k);
    mod = (1<<k)-1;
    //    cout<<"mod:"<<mod<<endl;
    sum[0] = 0;
    for ( int i = 1 ; i <= n ; i++)
    {
	scanf("%d",&a[i]);
	sum[i] = (sum[i-1] + a[i] ) % mod;
    }

    //  for ( int  i = 1; i <= n ; i++) printf("%d:%d \n",i,sum[i]);
    int p = -1;
    for ( int i =  n ; i >= 1 ; i--) 
    {
	if (sum[i]==0)
	{
	    p = i ;
	    break;
	}
    }
    int ans = 0 ;
    if (p!=-1)
    {
	ans = max(ans,p);
    }
    for ( int i = n ; i >= 1 ; i--)
    {
	if (mp[sum[i]])
	{
	    ans = max(ans,abs(mp[sum[i]]-i));
	}else mp[sum[i]] = i;
    } 

    /*
       for ( int i = n ; i  >= 1 ; i--)
       if (!mp[sum[i]]) mp[sum[i]] = i ;
       for  ( int i = 1; i  <= n ; i++)
       {
       if (mp[sum[i]]!=i)
       {
       int x = mp[sum[i]];
       int y =  i;
       if (x<y) x++;
       else y++;
    // cout<<"x:"<<x<<" y:"<<y<<endl;
    ans = max(ans,abs(x-y)+1);
    }
    }
    */
    printf("%d\n",ans);

#ifndef ONLINE_JUDGE  
    fclose(stdin);
#endif
    return 0;
}
