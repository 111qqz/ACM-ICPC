/* ***********************************************
Author :111qqz
Created Time :2016年02月22日 星期一 23时21分34秒
File Name :code/hdu/1260.cpp
************************************************ */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int n,k;
const  int inf=99999999;
const int N=2E3+5;
bool am;
int a[N],b[N],dp[N],hour,mini,sec;

int main()
{

    scanf("%d",&n);
    while ( n-- )
    {
        am = true;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        hour = 8;
        mini = 0;
      //  cout<<"hour1:"<<hour<<endl;
        for ( int i = 0 ; i < N ; i++ )
            dp[i] = 0;
     //   cout<<"hour2:"<<hour<<endl;

        scanf("%d",&k);
        for ( int i = 1; i <= k ; i++ )
            scanf("%d",&a[i]);
        for ( int i = 2 ; i <= k ; i++ )
            scanf("%d",&b[i]);
        dp[1] = a[1];
        for ( int i = 2; i <= k ; i++ )
            dp[i] = min(dp[i-1]+a[i],dp[i-2]+b[i]);
    //    printf("%d\n",dp[k]);
        sec = dp[k];
     //   hour = 8;
   //  cout<<"hour:"<<hour<<endl;
        while (sec>=3600)
        {
            sec = sec - 3600 ;
            hour++;
        }
        while (sec>=60)
        {
            sec = sec - 60 ;
            mini++;
        }
        if ( hour>12 )
        {
            am = false;
            hour = hour - 12;
        }
        if ( hour<10 )
            cout<<"0";
        cout<<hour<<":";
        if ( mini<10 )
            cout<<"0";
        cout<<mini<<":";
        if ( sec<10 )
            cout<<"0";
        if ( am )
            cout<<sec<<" am"<<endl;
        else cout<<sec<<" pm"<<endl;
    }
    return 0;
}
