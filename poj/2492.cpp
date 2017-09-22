/* ***********************************************
Author :111qqz
Created Time :2016年03月03日 星期四 13时37分36秒
File Name :code/poj/2492.cpp
************************************************ */

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

const int N=2E5+7;
bool flag;
int f[N];
int T,n,m,x,y;
char ch;

int root (int x)
{
    if (f[x]!=x)
        f[x] = root(f[x]);
    return f[x];
}
void u(int a,int b)
{
    f[root(a)]=root(b);
}
int main()
{
    scanf("%d",&T);
    for ( int cas = 1 ; cas <= T ; cas++ )
    {
        for ( int i = 1 ; i < N ; i++ )
            f[i] = i;
        scanf("%d %d",&n,&m);
        flag = false;
        for ( int i = 1 ; i <= m ; i++ )
        {

            scanf("%d %d",&x,&y);
            if (flag)
                continue;

            if (root(x)==root(y)||root(x+n)==root(y+n))
            {

                flag = true;
            }
            u(x,y+n);
            u(x+n,y);
        }
        if ( !flag )
        {
            printf("Scenario #%d:\n",cas);
            printf("No suspicious bugs found!\n");

        }
        else
        {
                printf("Scenario #%d:\n",cas);
                printf("Suspicious bugs found!\n");

        }
        cout<<endl;


    }






    return 0;
}
