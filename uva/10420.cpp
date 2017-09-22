/* ***********************************************
Author :111qqz
Created Time :2016年01月20日 星期三 19时26分09秒
File Name :code/uva/10420.cpp
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
string str;
int len;
map<string,int>mp;
map<string,int>::iterator it;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	getchar();
	mp.clear();
	while (T--)
	{
	    getline(cin,str);
//	    cout<<str<<endl;
	    int pos = str.find(' ');
	    string cou = str.substr(0,pos);
	//    cout<<"country:"<<cou<<endl;
	    mp[cou]++;
	}
//	cout<<mp.size()<<endl;

	for ( it=mp.begin() ; it!=mp.end() ; it++)
	{
	    cout<<it->fst<<" "<<it->second<<endl;
	}


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
