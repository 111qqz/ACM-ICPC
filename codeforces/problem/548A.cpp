/* ***********************************************
Author :111qqz
Created Time :2016年03月03日 星期四 14时09分08秒
File Name :code/cf/problem/548A.cpp
************************************************ */

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <map>

using namespace std;
const int N=1E3+5;
char st[N];
int k,len,ave;
bool ok(int l,int r)
{
    for (int i = l ; i<=(l+r)/2;i++)
        if (st[i]!=st[l+r-i])
            return false;
    return true;
}

int main()
{
    cin>>st;
    cin>>k;
    len = strlen(st);
    ave= len/k;
    if (k*ave!=len){cout<<"NO"<<endl;return 0;}
    for (int i = 1 ; i<=k;i++ )
    {
            if (!ok((i-1)*ave,i*ave-1))
                {
                    cout<<"NO"<<endl;
                    //cout<<i<<endl;
                    return 0;
                }

    }
    cout<<"YES"<<endl;



    return 0;
}
