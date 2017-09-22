/* ***********************************************
Author :111qqz
Created Time :2016年02月22日 星期一 23时23分41秒
File Name :code/hdu/1160.cpp
************************************************ */

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

int n,tmp,tmppre,m,index;
const int N=1E5+5;
int dp[N],ans[N],pre[N],k;

struct ST
{
    int w,s,id;
}st[N];

bool cmp(ST a,ST b)
{
    if ( a.w<b.w) return true;
    if ( a.w==b.w&&a.s>b.s ) return true;
    return false;
}
int main()
{
    n = 1;
    while(scanf("%d %d",&st[n].w,&st[n].s)!=EOF)
    {

            st[n].id = n;
            n++;
         //   if (n>9) break;

    }
    n--;
     memset(dp,0,sizeof(dp));
    memset(ans,0,sizeof(ans));
    memset(pre,-1,sizeof(pre));
    sort(st+1,st+n+1,cmp);


    dp[1] = 1;
    for ( int i = 2; i <= n; i++)
    {
       dp[i] = 1;
        for ( int j = 1 ; j <= i -1 ; j++ )
            if (st[j].w<st[i].w&&st[j].s>st[i].s&&dp[j]+1>dp[i])
            {

                dp[i] = dp[j]+1;
                pre[i] = j;
            }
    }
  //  cout<<endl;
  //  for ( int i = 1 ; i <= n ; i++ )
   //     cout<<st[i].w<<" "<<st[i].s<<endl;
   // for ( int i = 1 ;  i <= n ; i++ )
     //   cout<<"pre[i]:"<<pre[st[i].id]<<"dp[i]:"<<dp[i]<<endl;


    m = -1;
    for ( int i = 1 ; i <= n;i++ )
        if ( dp[i] > m)
        {
            m = dp[i];
            index = i;
        }
    cout<<m<<endl;
   // cout<<"index "<<index<<endl;
    k = 0;
    while (index!=-1)
    {
        k++;
        ans[k] = index;
        index=pre[index];
    }
    for ( int i = k; i >= 1; i-- )
        cout<<st[ans[i]].id<<endl;


    return 0;
}
