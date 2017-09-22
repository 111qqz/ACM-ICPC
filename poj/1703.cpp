/* ***********************************************
Author :111qqz
Created Time :2016年03月03日 星期四 13时43分16秒
File Name :code/poj/1703.cpp
************************************************ */

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

const int N=2E5+7;
bool v[N];
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
void ask(int a,int b)
{
    //if (!v[a]||!v[b])
   // {
        
     //   return;
  //  }
    if (root(a)==root(b)||root(a+n)==root(b+n))
    {
        cout<<"In the same gang."<<endl;
    }
    else if (root(a)==root(b+n)||root(a+n)==root(b))
    {
        cout<<"In different gangs."<<endl;
    }
    else
    {
        cout<<"Not sure yet."<<endl;
    }
}


int main()
{
    cin>>T;
    while (T--)
    {
        memset(v,false,sizeof(v));
        for ( int i = 0 ; i < N ; i++ )
            f[i] = i;
        scanf("%d %d",&n,&m);
        for ( int i = 1 ; i <= m ; i++ )
        {

            scanf("%s %d %d",&ch,&x,&y);
            if (ch=='A')
            {
                ask(x,y);
            }
            else
            {
                v[x] = true;
                v[y] = true;
                u(x,y+n);
                u(x+n,y);
            }
        }
    }
    return 0;
}

