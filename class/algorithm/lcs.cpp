/* ***********************************************
Author :111qqz
Created Time :2016年03月21日 星期一 18时51分07秒
File Name :lcs.cpp
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

string a,b;
int dp[25][25];
int path[25];

int main()
{

   freopen("code/in.txt","r",stdin);

    cin>>a>>b;
    int la = a.length();
    int lb = b.length();
    ms(dp,0);
    for(int i=1;i<=la;i++)
    {
        for(int j=1;j<=lb;j++)
        {
            if(a[i-1]==b[j-1])
            dp[i][j]=dp[i-1][j-1]+1;
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int i=la,j=lb,k=0;
    while(dp[i][j])
    {
        if(dp[i][j]==dp[i-1][j])
        i--;
        else if(dp[i][j]==dp[i][j-1])
        j--;
        else
        {
            path[k++]=i-1;
            i--;j--;
        }
    }
    puts("输入的字符串为：");
    cout<<a<<endl<<b<<endl;
    cout<<dp[la][lb]<<endl;
    for(int i=k-1;i>=0;i--)
    cout<<a[path[i]];
    return 0;
}

