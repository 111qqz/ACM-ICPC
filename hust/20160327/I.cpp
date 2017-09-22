#include <string.h>
#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <queue>
#define  LL long long
#define MOD 1000000007

using namespace std;

const int MAXN = 100005;
const int MAXM = 105;

long long dp[MAXN][2];

string a,b;
int k;

int main()
{
//    freopen("code/in.txt","r",stdin);
    int i;
    cin>>a>>b>>k;
    string s1,s2;
    memset(dp,0,sizeof(dp));
    if(a==b) dp[0][0]=1;
    else dp[0][1]=1;

    LL cnt=0;
    int len=a.length();

    for(i=1;i<len;i++)
        {
            s1=a.substr(0,i);
            s2=a.substr(i,len);
            if(s2+s1==a) cnt++;
        }
//    cout<<" cnt :"<<cnt<<endl;

    for(i=1;i<=k;i++)
        {
            dp[i][0]=((dp[i-1][0]*cnt)%MOD+dp[i-1][1]*(cnt+1)%MOD)%MOD;
            dp[i][1]=((dp[i-1][0]*(len-1-cnt))%MOD+(dp[i-1][1]*(len-cnt-2))%MOD)%MOD;
            dp[i][0]%=MOD;
            dp[i][1]%=MOD;

//	    cout<<"ans:"<<dp[k][0]<<endl;
        }
        cout<<dp[k][0]%MOD<<endl;

    return 0;
}

