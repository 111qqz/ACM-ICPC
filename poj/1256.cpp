/* ***********************************************
Author :111qqz
Created Time :2016年02月19日 星期五 15时43分31秒
File Name :code/poj/1256.cpp
************************************************ */

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <map>

using namespace std;
bool cmp(char a,char b)
{
    char x = tolower(a);
    char y = tolower(b);
    if (x==y)
    {
        return a<b;
    }
    else return x<y;
}
int n;
string st;

int main()
{
    cin>>n;
    while (n--)
    {

        cin>>st;
        sort(st.begin(),st.end(),cmp);
        do
        {
            cout<<st<<endl;
        }while (next_permutation(st.begin(),st.end(),cmp));
    }


	return 0;
}

