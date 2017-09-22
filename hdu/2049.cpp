/* ***********************************************
Author :111qqz
Created Time :2016年07月27日 星期三 16时39分21秒
File Name :code/hdu/2049.cpp
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
const int inf = 0x3f3f3f3f;
const int N=22;
LL d[N];
LL c[N][N];
int n,m;

void cal_c()
{
    c[1][0] = 1;
    c[1][1] = 1;
    c[2][0] = 1;
    c[2][1] = 2;
    c[2][2] = 1;
    for ( int i = 1 ; i < N;  i++) c[i][0] = 1;
    for ( int i = 3 ; i < N ; i++)
    for ( int j = 1 ; j <= i ;j++)
        c[i][j] = c[i-1][j]+c[i-1][j-1];
}
int main()
{
    #ifndef  ONLINE_JUDGE 
    freopen("code/in.txt","r",stdin);
  #endif

    cal_c();
    d[1] = 0 ;
    d[2] = 1;
    for ( int i = 3 ; i < N ; i++) d[i] = (i*1LL-1)*(d[i-1]+d[i-2]);
    int T;
    cin>>T;
    while (T--)
    {
        scanf("%d%d",&n,&m);
        LL ans = d[m];
        ans*=c[n][m];
     //   cout<<"m:"<<m<<" d[m]:"<<d[m]<<endl;
//        for ( int j = 1 ; j <= n-m ; j++)
//        ans = ans*(n+1-j;//cout<<"ans:"<<ans<<endl;

        printf("%lld\n",ans);
    }


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
