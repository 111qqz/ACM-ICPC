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
using namespace std;
#define REP(i, n) for (int i=0;i<int(n);++i)
typedef long long LL;
typedef unsigned long long ULL;
const int N= 1E5+7;
const int inf = 0x7fffffff;
int a[N];
int  vis[N],step[N];
bool cmp (int a,int b)
{
    if (a>b) return true;
    return false;
}
int main()
{
                    int n;
                    cin>>n;
                    int mx = -1;
                    memset(vis,0,sizeof(vis));
                    memset(step,0,sizeof(step));
                    for ( int i = 1 ;  i <= n ; i++ )
                    {
                          cin>>a[i];
                          if (a[i]>mx)
                                mx = a[i];
                    }
                    for ( int i = 1 ; i <= n ; i++ )
                    {
                          int tmp = a[i];
                          int num = 0;
                          while (tmp<=mx)
                          {
                                step[tmp]+=num;   
                                vis[tmp]++;     
                                num++;
                                tmp = tmp << 1;
                          }
                          num = 0;
                          int tmpa = a[i];
                          while (tmpa)
                          {
                                if (tmpa&1&&tmpa!=1)    
                                {           
                                    int tmp = (tmpa>>1)<<1;
                                    int sum = num + 2;  //奇数a[i]变为偶数a[i]-1的需要两步。
                                    while (tmp<=mx) 
                                    {
                                          step[tmp]=step[tmp]+sum;
                                          vis[tmp]++;
                                          sum++;
                                          tmp = tmp << 1;
                                    }
                                }
                                num++;
                                tmpa = tmpa>>1;     
                                step[tmpa]+=num;
                                vis[tmpa]++;
                          }
                    }
                    int ans = inf;
                    for ( int i = 1 ; i <= mx ; i++ )
                    {
                   //     cout<<"i:"<<i<<" vis[i]:"<<vis[i]<<"  step[i]:"<<step[i]<<endl;
                          if (vis[i]==n) 
                          {
                                ans = min(ans,step[i]);
                          }
                    }
                    cout<<ans<<endl;
                        return 0;
}
