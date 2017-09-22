/* ***********************************************
Author :111qqz
Created Time :2016年02月19日 星期五 16时20分07秒
File Name :code/hdu/5113.cpp
************************************************ */

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

    int c[100],cc[100];
    int ans[10][10];
    int colorid[100];
    int n,m,k;
    void look();
bool judge();


int main()
{
    int tt;
    int t;
    int kk;

    cin>>t;
    tt=t;


    int i,j;
    int head;
    int flag;
   while (t--)
    {  head=1;
    flag=1;
         memset(ans,0,sizeof(ans));
        cin>>n>>m>>k;
        kk=k;
        for (i=1;i<=k;i++)
            cin>>c[i];

        for (i=1;i<=k;i++)
            colorid[i]=i;
        for (i=1;i<k;i++)
            for (j=i+1;j<=k;j++)
            if (c[i]>c[j])
            {
              swap(c[i],c[j]);
              swap(colorid[i],colorid[j]);
            }
             for (i=1;i<=k;i++)
                cc[i]=c[i];



        if (c[k]>(n*m+1)/2)  { cout<<"Case #"<<tt-t<<":"<<endl;cout<<"NO"<<endl;continue;}

        for (i=1;i<=n;i++)
            for (j=1;j<=m;j++)
                if ((i%2+j%2)%2==1)
                {
                  if (flag%2==1)
                  {


                     ans[i][j]=colorid[k];
                    // cout<<"i:"<<i<<"j:"<<j<<" "<<colorid[k]<<endl;

                     c[k]--;
                     if (c[k]==0)
                        {
                            k--;
                            flag++;

                        }
                  }
                  else
                    {
                        ans[i][j]=colorid[head];

                    //    cout<<"i:"<<i<<"j:"<<j<<"  "<<colorid[head]<<endl;
                        c[head]--;
                        if (c[head]==0)
                        {
                            head++;
                            flag++;

                        }
                    }
                  //  look();
                }


                for (i=1;i<=n;i++)
            for (j=1;j<=m;j++)
                if ((i%2+j%2)%2==0)
                {


                    if (flag%2==1)
                  {


                     ans[i][j]=colorid[k];
                  //   cout<<"i:"<<i<<"j:"<<j<<" "<<colorid[k]<<endl;
                     c[k]--;
                     if (c[k]==0)
                        {
                            k--;
                              flag++;
                        }
                  }
                  else
                    {
                        ans[i][j]=colorid[head];
                      // cout<<"i:"<<i<<"j:"<<j<<"  "<<colorid[head]<<endl;
                        c[head]--;
                        if (c[head]==0)
                        {
                            head++;
                           flag++;
                        }
                    }
                 //   look();
                }
               cout<<"Case #"<<tt-t<<":"<<endl;
               cout<<"YES"<<endl;

                if (!judge())
                     look();
               else
               {


                   k=kk;
                   head=1;
                   flag=1;
                   for (i=1;i<=k;i++)
                       c[i]=cc[i];
                   memset(ans,0,sizeof(ans));

                   for (i=1;i<=n;i++)
                    for (j=1;j<=m;j++)
                        if ((i%2+j%2)%2==0)
                    {
                        if (flag%2==1)
                        {
                     ans[i][j]=colorid[k];
                   //  cout<<"i:"<<i<<"j:"<<j<<" "<<colorid[k]<<endl;

                     c[k]--;
                     if (c[k]==0)
                        {
                            k--;
                            flag++;

                        }
                  }
                  else
                    {
                        ans[i][j]=colorid[head];

                     //   cout<<"i:"<<i<<"j:"<<j<<"  "<<colorid[head]<<endl;
                        c[head]--;
                        if (c[head]==0)
                        {
                            head++;
                            flag++;

                        }
                    }
                  //  look();
                }
                for (i=1;i<=n;i++)
            for (j=1;j<=m;j++)
                if ((i%2+j%2)%2==1)
                {


                    if (flag%2==1)
                  {


                     ans[i][j]=colorid[k];
                    // cout<<"i:"<<i<<"j:"<<j<<" "<<colorid[k]<<endl;
                     c[k]--;
                     if (c[k]==0)
                        {
                            k--;
                              flag++;
                        }
                  }
                  else
                    {
                        ans[i][j]=colorid[head];
                     //  cout<<"i:"<<i<<"j:"<<j<<"  "<<colorid[head]<<endl;
                        c[head]--;
                        if (c[head]==0)
                        {
                            head++;
                           flag++;
                        }
                    }
                 //   look();
                }
                  look();

               }



    }
    return 0;
}


void look()
{
    //  cout<<"lookkkkkkkkkkkkkkkkkkkkk"<<endl;
    int i,j;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            if (j!=m)
          cout<<ans[i][j]<<" ";
         else cout<<ans[i][j]<<endl;

}
bool judge()
{
    int i,j;
    for (i=1;i<=n;i++)
        for (j=1;j<m;j++)
         if (ans[i][j]==ans[i][j+1])
           return true;
    for (i=1;i<n;i++)
        for (j=1;j<=m;j++)
        if (ans[i][j]==ans[i+1][j])
          return true;
      return false;
}

