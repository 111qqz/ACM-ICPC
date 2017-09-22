/* ***********************************************
Author :111qqz
Created Time :2016年02月19日 星期五 16时38分28秒
File Name :code/hdu/1009.cpp
************************************************ */

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <iomanip>
 
using namespace std;
 
int main()
{
    int  m,n,f[1500],j[1500];
    double scale[1500];
    double ans,sum;
    while(scanf("%d %d",&m,&n)!=EOF&&(m!=-1))
    {  ans=0;
      //  if (m==0)
         memset(scale,0,sizeof(scale));
         memset(f,0,sizeof(f));
         memset(j,0,sizeof(j));
       //  bool flag=false;
       for (int i=1;i<=n;i++)
        {
            scanf("%d %d",&j[i],&f[i]);
            if (f[i]!=0)
            scale[i]=(double)j[i]*1.0/f[i];
            else if (j[i]!=0)
            {
                  ans=ans+j[i];
 
            }
        }
       // if (flag) {cout<<fixed<<setprecision(3)<<ans<<endl;continue;}
        for (int i=1;i<=n-1;i++)
          for (int k=i+1;k<=n;k++)
          if (scale[i]<scale[k])
        {
            swap(scale[i],scale[k]);
            swap(j[i],j[k]);
            swap(f[i],f[k]);
        }
        sum=0;
       int i=1;
        while (m>=sum&&i<=n)
        {
          ans=ans+j[i];
          sum=sum+f[i];
          i++;
        }
        i--;
        ans=ans-j[i];
        sum=sum-f[i];
        ans=ans+(m-sum)*scale[i];
        cout<<fixed<<setprecision(3)<<ans<<endl;
 
 
    }
    return 0;
}
