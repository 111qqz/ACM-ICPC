/* ***********************************************
Author: SnowyJune
Created Time :2017年11月01日 星期三 19时53分22秒
File Name :BBB.cpp
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
#define lson(x) (x<<1)
#define rson(x) ((x<<1)|1) 
#define ms(a,x) memset(a,x,sizeof(a))
typedef long long LL;
#define pi pair < int ,int >
#define MP make_pair

using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int INF = 0x3f3f3f3f;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e5+10;
const int N=100;
int n,m,k;
int tail,head;
struct node
{
    int num;
    int id;
    bool operator < (node b)
    {
        return num>b.num;
    }
}c[N],cc[N];
int flag;
int ans[N][N];
void solve1()
{
    for ( int i = 1 ; i <= n ; i++)
    {
        for ( int j = 1 ; j <= m ; j++)
        {
            if ((i+j)%2==1) continue;
            if (flag%2==0)
            {
                ans[i][j] = c[head].id;
                c[head].num--;
                if (c[head].num==0)
                {
                    head++;
                    flag++;
                }
            }
            else
            {
                ans[i][j] = c[tail].id;
                c[tail].num--;
                if (c[tail].num==0)
                {
                    tail--;
                    flag++;
                }
            }
        }
    }
}
void solve2()
{

    for ( int i = 1 ; i <= n ; i++)
    {
        for ( int j = 1 ; j <= m ; j++)
        {
            if ((i+j)%2==0) continue;
            if (flag%2==0)
            {
                ans[i][j] = c[head].id;
                c[head].num--;
                if (c[head].num==0)
                {
                    head++;
                    flag++;
                }
            }
            else
            {
                ans[i][j] = c[tail].id;
                c[tail].num--;
                if (c[tail].num==0)
                {

                    tail--; 
                    flag++;
                }
            }

        }
    }
}
bool check()
{
    for ( int i = 1 ;i  <= n ; i++)
        for ( int j = 1 ;j  <= m ; j++)
        {
            if (ans[i][j]==ans[i-1][j]||ans[i][j]==ans[i+1][j]) return false;
            if (ans[i][j]==ans[i][j-1]||ans[i][j]==ans[i][j+1]) return false;
        }
    return true;
}
void pr()
{
    puts("YES");
    for ( int i = 1 ; i <= n ; i++)
        for ( int j = 1 ; j <= m ; j++)
            printf("%d%c",ans[i][j],j==m?'\n':' ');

}
int main(){
#ifdef SNOWYJUNE 
//	freopen("input","r",stdin);
#endif
    int T;
    cin>>T;
    int cas = 0 ;
    while (T--)
    {
        ms(ans,0);
        flag = 0;
        scanf("%d %d %d",&n,&m,&k);
        for ( int i = 1 ; i <= k ; i++)
        {
            scanf("%d",&c[i].num);
            c[i].id = i;
        }

        printf("Case #%d:\n",++cas);
        sort(c+1,c+k+1);
        for ( int i = 1 ; i <= k ; i++) cc[i] = c[i];
        if (c[1].num>(n*m+1)/2)
        {
            puts("NO");
            continue;
        }
        head = 1;
        tail = k;
        
        solve1();
        solve2();
        if (check())
        {
            pr();
            continue;
        }
        head = 1;
        tail = k;
	ms(ans,0);
        for ( int i = 1 ; i <= k ; i++) c[i] = cc[i];
        solve2();
        solve1();
        if (check())
        {
            pr();
            continue;
        }
        puts("NO");
    }

#ifdef SNOWYJUNE
	fclose(stdin);
#endif
    return 0;
}
