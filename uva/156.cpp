/* ***********************************************
Author :111qqz
Created Time :2016年01月25日 星期一 14时26分38秒
File Name :code/uva/156.cpp
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
const int N=9E5+7;
string str;
int a[N];
map<string,int>mp;
map<string,int>::iterator it;
map<string,string>toori;
struct node
{
    string ori;
    string nw;
}st[1005];

set<string>ans;
set<string>::iterator it2;

int main()
{
	mp.clear();
	ans.clear();
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	ms(a,0);
	int cnt = 0 ;
	while (getline(cin,str))
	{
	    if (str=="#") break;
	    int p = str.find(' ');
	    string tmp;
	    int len;
	    int num;
	    while (p!=-1)
	    {
	        tmp = str.substr(0,p);
	//	cout<<"tmp:"<<tmp<<endl;
	//	if (tmp=="") continue;
		cnt++;
		st[cnt].ori = tmp;

	        len = tmp.length();
	        num = 0;
		
		for ( int i = 0 ; i < len ; i ++)
		{
		    tmp[i]=tolower(tmp[i]);
		    int val = tmp[i]-'a'+1;  //a..z对应1..26
		    num +=val*val;
		}
	//	cout<<"tmp:"<<tmp<<endl;
		st[cnt].nw = tmp;
		toori[st[cnt].nw]=st[cnt].ori;
		mp[tmp] = num;
		a[num]++;
		str.erase(0,p+1);
		p = str.find(' ');
	    }
	    //cout<<"rstr:"<<str<<endl;
	    tmp=str.substr(0);
	    cnt++;
	    st[cnt].ori=tmp;
	     len = tmp.length();
	     num = 0 ;
	    for ( int i = 0  ; i < len ; i++)
	    {
		tmp[i]=tolower(tmp[i]);
		int val = tmp[i]-'a'+1;
		num +=val *val;
	    }
	  //  cout<<"tmp:"<<tmp<<endl;
	    st[cnt].nw = tmp;
	    toori[st[cnt].nw]=st[cnt].ori;
	    mp[tmp]=num;
	    a[num]++;
	}
//	cout<<"a[drIed]:"<<a[mp["dried"]]<<endl;	
	for ( it=mp.begin() ;it!=mp.end(); it ++)
	{
	    int tmp = it->sec;
	  //  cout<<"a[tmp]:"<<a[tmp]<<endl;
	    if (a[tmp]==1)
	    {
		//	cout<<toori[it->fst]<<endl;
//		cout<<it->fst<<" "<<it->sec<<" "<<toori[it->fst]<<endl;
		ans.insert(toori[it->fst]);
	    }
	}
	for ( it2=ans.begin() ; it2!=ans.end();it2++)
	{
	    cout<<*it2<<endl;
	}
	
    

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
