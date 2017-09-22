/* ***********************************************
Author :111qqz
Created Time :2016年02月19日 星期五 16时30分04秒
File Name :code/hdu/5119.cpp
************************************************ */

#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
const long long C=1<<21;
long long dp[2][C];
using namespace std;

int main()
{
    int t,a[49];
    cin>>t;
    int tt;
    tt=t;
    while (t--)

    {
        int n,m,roll;
        roll=0;
         memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        cin>>n>>m;
        for(int i=0;i<n;i++)
            cin>>a[i];

        for(int i=0;i<n;i++)
        {
            roll=roll^1;
            for(int j=0;j<=(C/2);j++)
                dp[roll][j]=dp[roll^1][j]+dp[roll^1][j^a[i]];
        }
        long long ans=0;
        for(int i=m;i<=(C/2);i++)
            ans=ans+dp[roll][i];
            cout<<"Case #"<<tt-t<<": "<<ans<<endl;

    }
    return 0;
}


