/* ***********************************************
Author :111qqz
Created Time :2016年02月19日 星期五 16时43分50秒
File Name :code/cf/problem/447B.cpp
************************************************ */

#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int k,len;
    char st[2000];
    int a[2000];
    memset(a,0,sizeof(a));
    int w[50];
    cin>>st>>k;
    int m=-1;
    for (int i=1;i<=26;i++)
    {

        cin>>w[i];
        if (w[i]>m)
            m=w[i];
    }
    len=strlen(st);
    for (int i=0;i<len;i++)
        a[i]=(int)(st[i]-96);
        long long ans=0;
        for (int i=0;i<len;i++)
        {
            ans=ans+w[a[i]]*(i+1);
           //    cout<<ans<<endl;
        }
        for (int i=len;i<len+k;i++)
            ans=ans+m*(i+1);
        cout<<ans<<endl;
    return 0;
}
