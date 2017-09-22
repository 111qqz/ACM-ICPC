/* ***********************************************
Author :111qqz
Created Time :2016年02月19日 星期五 15时44分12秒
File Name :2388.cpp
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
const int N=2E4+5;
int n;
int a[N];
int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        for ( int i = 0 ; i < n ; i++ )
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        cout<<a[n/2]<<endl;
    }



	return 0;
}

