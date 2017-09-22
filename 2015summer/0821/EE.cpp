/*************************************************************************
	> File Name: code/2015summer/0821/EE.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月21日 星期五 02时58分49秒
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<stack>
#define y0 abc111qqz
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define tm crazy111qqz
#define lr dying111qqz
using namespace std;
#define REP(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef unsigned long long ULL;
const int inf = 0x7fffffff;
const int N=2E2+7;
using namespace std;
char s[10];
struct node
{
    int tim,d;
}a[N],b[N];
int dp[N][N][2],INF=1e9;
int main()
{
    int T,t,n,i,j,k,l,r,tim,d,st,en;
//    cout<<"inf:"<<inf<<endl;
  //  cout<<"INF:"<<INF<<endl;
    int cntA,cntB;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d",&n);
        l=0;r=0;
	cntA = cntB = 0 ;
        for(i=1;i<=n;i++)
        {
            scanf("%s%d%d",s,&tim,&d);
            if(s[0]=='A')
            {
                cntA++;
                a[cntA].tim=tim;
		a[cntA].d=d;
            }
            else
            {
                cntB++;
                b[cntB].tim=tim;
		b[cntB].d=d;
	    }
        }
        for(i=0;i<=cntA;i++)
           for(j=0;j<=cntB;j++)
            for (k = 0 ; k <= 1 ; k++)
		dp[i][j][k]=inf/2;
        dp[0][0][0]=dp[0][0][1]=0;
        for(i=0;i<=cntA;i++)
           for(j=0;j<=cntB;j++)
           {
               st=dp[i][j][1]-10;
               en=dp[i][j][1]-10;
               for(k=i+1;k<=cntA;k++)
               {
                   st=max(st+10,a[k].tim);
                   en=max(en+10,st+a[k].d);
                   dp[k][j][0]=min (dp[k][j][0],en);
               }
               st=dp[i][j][0]-10;
               en=dp[i][j][0]-10;
               for(k=j+1;k<=cntB;k++)
               {
                   st=max(st+10,b[k].tim);
                   en=max(en+10,st+b[k].d);
                   dp[i][k][1]=min(dp[i][k][1],en);
               }
           }
        printf("%d\n",min(dp[cntA][cntB][0],dp[cntA][cntB][1]));
    }
    return 0;
}
