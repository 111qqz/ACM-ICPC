/* ***********************************************
Author :111qqz
Created Time :2016年02月22日 星期一 23时05分11秒
File Name :code/hdu/1069.cpp
************************************************ */

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;
    int n,k,a,b,c,tmp;
    const int N=1E4+5;
    int dp[N];
    long long ans;
struct Q
{
    int x,y,z;

}q[N];

bool cmp(Q a,Q b)
{
    if (a.x>b.x) return true;
    if (a.x==b.x&&a.y>b.y) return true;
    return false;
}

int main()
{
    int cas=0;
    while (scanf("%d",&n)!=EOF&&n)
    {
        cas++;
        memset(dp,0,sizeof(dp));
        k = 1;
        ans = -1;
        for ( int i = 1 ; i <= n ; i++ )
        {
            scanf("%d%d%d",&a,&b,&c);
            q[k].x = a;q[k].y = b;q[k].z=c;k++;
            q[k].x = a;q[k].y = c;q[k].z=b;k++;
            q[k].x = b;q[k].y = a;q[k].z=c;k++;
            q[k].x = b;q[k].y = c;q[k].z=a;k++;
            q[k].x = c;q[k].y = a;q[k].z=b;k++;
            q[k].x = c;q[k].y = b;q[k].z=a;k++;
        }
        k--;
        sort(q+1,q+k+1,cmp);
        dp[1]=q[1].z;

        for ( int i = 2 ; i <= k ; i++ )
        {
            tmp = 0;
            for ( int j = 1 ; j <= i-1 ; j++ )
                if (q[j].x>q[i].x&&q[j].y>q[i].y&&dp[j]>tmp)
                {
                    tmp=dp[j];
                }
            dp[i]=tmp+q[i].z;
        }
        for ( int i = 1 ; i <= k ; i++)
            if ( dp[i]>ans )
                ans = dp[i];
        printf("Case %d: maximum height = %I64d\n",cas,ans);
    }
    return 0;
}
