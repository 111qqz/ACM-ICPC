/* ***********************************************
Author :111qqz
Created Time :2016年02月19日 星期五 16时51分36秒
File Name :code/hdu/4882.cpp
************************************************ */

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
const int N=100005;
int n;
struct Q
{
    long long e,k;
}q[N];
bool cmp(Q a,Q b)
{
    return a.e*b.k<a.k*b.e;
}

int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
        scanf("%I64d",&q[i].e);
    for (int i=1;i<=n;i++)
        scanf("%I64d",&q[i].k);
      sort(q+1,q+1+n,cmp);
     long long ans=0,time=0;
    for (int i=1;i<=n;i++)
    {
        time=time+q[i].e;
        ans=ans+q[i].k*time;

    }
    printf("%I64d\n",ans);
    return 0;
}
