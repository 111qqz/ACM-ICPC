/* ***********************************************
Author :111qqz
Created Time :2016年02月19日 星期五 17时01分58秒
File Name :code/cf/problem/548B.cpp
************************************************ */

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <map>

using namespace std;
const int N=5E2+5;
int a[N][N];
int fans;
int n,m,q,x,y,cur,ans[N];
int main()
{
    cin>>n>>m>>q;
    for (int i = 1 ; i <= n;i++ )
    {
        for (int j = 1; j <= m ; j++ )
                scanf("%d",&a[i][j]);
        cur = 0;
        for (int j = 1; j <=m ;j++ )
            if (a[i][j]==1)
            {
                cur++;
                ans[i]=max(cur,ans[i]);
            }
            else
            {
               cur = 0;
            }
    }
    for ( int i = 1 ; i <= q; i++ )
    {
        scanf("%d %d",&x,&y);
        a[x][y]=a[x][y]^1;
       // if (i==3) cout<<a[x][y]<<"sadsadasd"<<endl;
        cur = 0;
        ans[x]=0;
        for (int j = 1; j <=m ;j++ )
            if (a[x][j]==1)
            {
                cur++;
                ans[x]=max(cur,ans[x]);
            }
            else
            {
               cur = 0;
            }
        fans=-1;
        for (int j = 1;j <= n ; j++ )
            if (ans[j]>fans)
            {
                fans=ans[j];
            }
        cout<<fans<<endl;
    }


    return 0;
}

