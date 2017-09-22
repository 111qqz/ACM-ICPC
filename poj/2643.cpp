/* ***********************************************
Author :111qqz
Created Time :2016年02月19日 星期五 15时44分55秒
File Name :2643.cpp
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
int n,m;
string ans;
map<string,string>m1;
map<string,int>m2;
string c_name,p_name;
char ch;
int main()
{
    cin>>n;
    getchar();
    for ( int i = 1 ; i <= n ; ++i )
    {
        getline(cin,c_name);

        getline(cin,p_name);
        m1[c_name]=p_name;
    }
    cin>>m;
    getchar();
    for ( int i = 1 ; i <= m ; i++ )
    {
        getline(cin,c_name);
        m2[c_name]++;
    }
    map<string,int>::iterator it;
    int mmax=-1;
    for (it=m2.begin();it!=m2.end();it++)
    {
        if (it->second>mmax)
        {
           mmax=it->second;
           ans = m1[it->first];
        }
    }
    int p = 0;
    for ( it = m2.begin();it!=m2.end();it++)
    {
        if (it->second==mmax)
        {
            p++;
        }
    }
    if (p!=1)
    {
        ans="tie";
    }

    cout<<ans<<endl;



	return 0;
}
