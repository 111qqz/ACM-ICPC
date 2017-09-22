/* ***********************************************
Author :111qqz
Created Time :2016年02月19日 星期五 15时45分05秒
File Name :3278.cpp
************************************************ */

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <stack>
#include <queue>

using namespace std;
typedef long long LL;
const int inf = 8E8;
const int N=2E5+7;
int d[N];
int n,k;
void bfs()
{
    queue<int> q;
    memset(d,-1,sizeof(d));
    q.push(n);
    d[n]=0;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        if ( x==k )
        {
            break;
        }
        int next[10];
        next[1]=x-1;
        next[2]=x+1;
        next[3]=2*x;
        for ( int i = 1; i <= 3 ; i++ )
        {
            if (next[i]>=0&&next[i]<=100000&&d[next[i]]==-1)
            {
                d[next[i]]=d[x]+1;
                q.push(next[i]);
            }
        }
    }


}
int main()
{
    while (scanf("%d %d",&n,&k)!=EOF)
    {
        bfs();
        cout<<d[k]<<endl;
    }
	return 0;
}
