/* ***********************************************
Author :111qqz
Created Time :2016年02月19日 星期五 15时44分06秒
File Name :3481.cpp
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



int cmd;
map<int,int>a;
int p,k;

int main()
{

    while (scanf("%d",&cmd)!=EOF&&cmd)
    {
       if (cmd==1)
       {
           scanf("%d %d",&k,&p);
           a[p]=k;
       }
       if (cmd==2)
       {
           if (a.empty())
           {
               cout<<"0"<<endl;
           }
           else
           {
               cout<<a.rbegin()->second<<endl;
               a.erase(a.find(a.rbegin()->first));
           }
       }
       if ( cmd==3 )
       {
           if (a.empty())
           {
               cout<<"0"<<endl;
           }
           else
           {
               cout<<a.begin()->second<<endl;
               a.erase(a.begin());
           }
       }
    }

	return 0;
}
