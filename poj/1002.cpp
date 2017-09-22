/* ***********************************************
Author :111qqz
Created Time :2016年02月19日 星期五 15时44分18秒
File Name :1002.cpp
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
const int  N=2E5+7;
map<string,int>a;
int n;
string st;

string solve(string str)
{
    int len=str.length();
    int k = 0 ;
    string res="";
    for ( int i = 0 ; i < len ; i++ )
    {
        if (str[i]=='-') continue;
        int tmp = (int)str[i];
        if (tmp>=48&&tmp<=60)
        {
            res = res + str[i];
        }
        if (tmp>=65&&tmp<=67)
        {
           res = res + '2';
        }
        if (tmp>=68&&tmp<=70)
        {
            res = res + '3';
        }
        if (tmp>=71&&tmp<=73)
        {
            res = res + '4';
        }
        if (tmp>=74&&tmp<=76)
        {
            res = res + '5';
        }
        if (tmp>=77&&tmp<=79)
        {
            res = res + '6';
        }
        if (tmp>=80&&tmp<=83)
        {
            res = res + '7';
        }
        if (tmp>=84&&tmp<=86)
        {
            res = res + '8';
        }
        if (tmp>=87&&tmp<=89)
        {
            res = res + '9';
        }
        k++;
        if (k==3)
        {
            res = res + '-';
        }
    }
    return res;
}

int main()
{
    cin>>n;
    for ( int i = 1 ; i <= n ; i++ )
    {
        cin>>st;
        string s = solve(st);
      //  cout<<"here!!!   "<<s<<endl;
        a[s]++;
    }
    map<string,int>::iterator it;
    bool flag = false;
    for (it=a.begin();it!=a.end();it++)
    {
        if (it->second>1)
        {
            cout<<it->first<<" "<<it->second<<endl;
            flag = true;
        }
    }
    if (!flag)
    {
        cout<<"No duplicates."<<endl;
    }



	return 0;
}

