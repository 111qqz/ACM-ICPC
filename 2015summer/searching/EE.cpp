/*************************************************************************
	> File Name: code/2015summer/searching/EE.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: Fri 24 Jul 2015 12:23:25 AM CST
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<stack>
#define y0 abc111qqz
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define tm crazy111qqz
#define lr dying111qqz
using namespace std;
bool found;
void DFS(unsigned long long  t ,int n,int k)
{
    if(found)
        return ;
    if(t%n==0)
    {
        cout<<t<<endl;
        found=true;
        return ;
    }
 //   if(k==19)//到第19层，回溯
   //     return ;
    DFS(t*10,n,k+1);    
    DFS(t*10+1,n,k+1);  
}
int main()
{
    int n;
    while(cin>>n,n)
    {
        found=false;
        DFS(1,n,0);    
    }
    return 0;
}
