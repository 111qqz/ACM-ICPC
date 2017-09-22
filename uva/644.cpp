/* ***********************************************
Author :111qqz
Created Time :2016年01月24日 星期日 21时17分44秒
File Name :code/uva/644.cpp
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
int cnt;
string str[N];


bool judge (int l,string x)
{
    int len = x.length();
    for (  int i = l+1 ; i < cnt ; i++)
    {
	string tmp = str[i].substr(0,len);
	if (tmp==x) return false;
    }
    return true;
}
bool cmp (string a,string b)
{
    return a.length()<b.length();
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int cas = 0 ;
	while (getline(cin,str[0]))
	{
	    cnt = 0 ;
	    while (str[cnt]!="9") 
	    {
		cnt++;
		getline(cin,str[cnt]);
	    }
	    //cout<<"cnt:"<<cnt<<endl;
	    
	    sort(str,str+cnt,cmp);
//	    for ( int i = 0 ;i < cnt ; i++) cout<<str[i]<<endl;

	    
	    bool ok  = true;
	    for ( int i = 0 ; i < cnt-1 ; i++)
	    {
		if (!judge(i,str[i]))
		{
		    ok = false;	
		    break;
		}
	    }
	    if (ok)
	    {
		printf("Set %d is immediately decodable\n",++cas);
	    }
	    else
	    {
		printf("Set %d is not immediately decodable\n",++cas);
	    }
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
