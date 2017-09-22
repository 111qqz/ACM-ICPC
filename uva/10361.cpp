/* ***********************************************
Author :111qqz
Created Time :2016年01月22日 星期五 01时46分03秒
File Name :code/uva/10361.cpp
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
string a,b;
string s2,s3,s4,s5;
int p1,q1,p2,q2;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	getchar();
	while (T--)
	{
	    getline(cin,a);
	    getline(cin,b);
	    int len;
	    len = a.length();
	//    cout<<"a:"<<a<<endl;
	//    cout<<"b:"<<b<<endl;
	    for ( int i =  0; i < len ; i++ )
	    {
		if (a[i]=='<'||a[i]=='>') continue;
		cout<<a[i];
	    }
	    cout<<endl;
	    
	    p1 = a.find("<");
	    q1 = a.find('>');
	    p2 = a.find('<',p1+1);
	    q2 = a.find('>',q1+1);
	    
	  //  printf("%d %d %d %d\n",p1,q1,p2,q2);

	    s2 = a.substr(p1+1,q1-p1-1);
	    s3 = a.substr(q1+1,p2-q1-1);
	    s4 = a.substr(p2+1,q2-p2-1);
	    s5 = a.substr(q2+1);
	  //  cout<<"s2:"<<s2<<" s3:"<<s3<<endl;
	   //   cout<<"s4:"<<s4<<" s5:"<<s5<<endl;
	   
	    len = b.length();
	    int p;
	    p = b.find("...");
	    //cout<<"p:"<<p<<endl;
	    for ( int i = 0 ; i < len ; i++)
	    {
		if (i==p)
		{
		    cout<<s4<<s3<<s2<<s5<<endl;
		    i=i+2;
		}
		else
		{
		    cout<<b[i];
		}
	    }


	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
