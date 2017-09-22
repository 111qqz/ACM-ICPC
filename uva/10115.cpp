/* ***********************************************
Author :111qqz
Created Time :2016年01月25日 星期一 08时57分55秒
File Name :code/uva/10115.cpp
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define fst first
#define sec second
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ms(a,x) memset(a,x,sizeof(a))
typedef long long LL;
#define pi pair < int ,int >
#define MP make_pair

using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int N=5E3+7;
struct node
{
    string fr;
    string to;
}rule[N];
int n;
string tar;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (scanf("%d",&n)!=EOF&&n)
	{
	    getchar();
	    for ( int i = 1 ; i <= n ; i++)
	    {
		getline(cin,rule[i].fr);
		getline(cin,rule[i].to);
	    }
	  //  for ( int i = 1 ; i <= n ; i++) cout<<"fr:"<<rule[i].fr<<" to:"<<rule[i].to<<endl;
	    getline(cin,tar);
	   // cout<<"tar:"<<tar<<endl;
	    for ( int i = 1 ; i <= n ; i++)
	    {
		int p = tar.find(rule[i].fr);
	//	cout<<"p:"<<p<<endl;
		while (p!=-1)
		{
		//    cout<<"tar:"<<tar<<" ";
		    tar=tar.replace(p,rule[i].fr.length(),rule[i].to);
		  // cout<<"tar2:"<<tar<<endl;
		    p = tar.find(rule[i].fr);
		 //   cout<<"p:"<<p<<endl;
		}
	//	cout<<"tar:"<<tar<<endl;
	    }
	    cout<<tar<<endl;
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
