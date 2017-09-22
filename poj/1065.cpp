/* ***********************************************
Author :111qqz
Created Time :2016年02月19日 星期五 16时47分32秒
File Name :code/poj/1065.cpp
************************************************ */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iomanip>


using namespace std;

int main()
{
    int t;
    cin>>t;
    int n;
    int l[6666],w[6666],lk[6666],wk[6666];
    while (t--)
    {
        memset(l,0,sizeof(l));
        memset(w,0,sizeof(w));
        memset(lk,0,sizeof(lk));
        memset(wk,0,sizeof(wk));
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d %d",&l[i],&w[i]);
        for (int i=1;i<=n-1;i++)
            for (int j=i+1;j<=n;j++)
             if ((l[i]>l[j])||((l[i]==l[j])&&(w[i]>w[j])))
        {
            swap(l[i],l[j]);
            swap(w[i],w[j]);

        }

            int k;
            int sum=1;
            lk[1]=l[1];
            wk[1]=w[1];
          //  for (int i=1;i<=n;i++)
        //        cout<<"look"<<l[i]<<"  "<<w[i]<<endl;
         for (int i=1;i<=n;i++)
         {

             k=1;
             while ((l[i]<lk[k])||(w[i]<wk[k]))
             {
                 k++;
             //    cout<<"look"<<endl;
                 if (k>sum) break;
             }
             if (k>sum)
             {
                 sum++;
                 lk[k]=l[i];
                 wk[k]=w[i];
             }
             else
             {
                 lk[k]=l[i];
                 wk[k]=w[i];
             }
         //    cout<<"k:"<<k<<endl;


         }
              printf("%d\n",sum);
    }
    return 0;
}
