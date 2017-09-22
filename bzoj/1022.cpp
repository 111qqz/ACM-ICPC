 
/* ***********************************************
Author :111qqz
Created Time :2016年07月22日 星期五 23时09分42秒
File Name :code/hdu/1907.cpp
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
const int N=5E3+7;
int n;
int sg[N];
bool vis[N];
 
void sg_init()
{
    ms(sg,0);
 
    for ( int i = 1 ; i < N ; i++)
    {
        sg[i] =  i;
    }
}
int main()
{
        #ifndef  ONLINE_JUDGE 
        freopen("code/in.txt","r",stdin);
  #endif
 
        sg_init();
 
        int T;
        cin>>T;
        while (T--)
        {
            scanf("%d",&n);
            int sum = 0;
            int cnt = 0 ;
            for ( int i = 1 ; i <= n ; i++)
            {
                int x;
                scanf("%d",&x);
                sum^=sg[x];
                if (sg[x]>1) cnt++;
            }
            if ((sum==0&&cnt==0)||(sum!=0&&cnt>0))
            {
                puts("John");
            }
            else
            {
                puts("Brother");
            }
        }
 
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
