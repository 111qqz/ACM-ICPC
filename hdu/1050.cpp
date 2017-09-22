/* ***********************************************
Author :111qqz
Created Time :2016年02月19日 星期五 16时35分52秒
File Name :code/hdu/1050.cpp
************************************************ */
#include <iostream>
#include <algorithm>
#include <cmath>
#include<cstdio>
#include <cstring>

using namespace std;

int main()
{
    int t,n,a[300],b[300];
    int p[300];
    int ans;
    scanf("%d",&t);
    while (t--)
    {

        scanf("%d",&n);
        memset(p,0,sizeof(p));
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for (int i=1;i<=n;i++)
        {
            scanf("%d %d",&a[i],&b[i]);
            if (a[i]>b[i])
                swap(a[i],b[i]);
            for (int j=(a[i]+1)/2;j<=(b[i]+1)/2;j++)
                p[j]++;
        }
        ans=0;
        for (int i=1;i<=200;i++)
            if (p[i]>ans)
            ans=p[i];
        printf("%d\n",ans*10);
    }
    return 0;
}
