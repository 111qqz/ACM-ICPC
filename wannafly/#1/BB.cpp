/* ***********************************************
Author :111qqz
Created Time :2016年11月19日 星期六 20时03分25秒
File Name :code/wfly/#1/BB.cpp
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
vector<char>ans;
bool check()
{
    int siz = ans.size();
    for ( int i = 0 ; i < siz ; i++)
    {
	if (ans[i]!=ans[siz-1-i]) return false;
    }
    return true;
}
int main()
{
#ifndef  ONLINE_JUDGE 
    freopen("code/in.txt","r",stdin);
#endif
    string st;
    cin>>st;
    int len = st.length();
    for ( int i = 0 ; i < len ; i++)
    {
	for ( int j = 0;  j< 26 ; j++)
	{
	    char ch = j +'a';
	    ans.clear();
	    for ( int k = 0 ; k < len ; k++)
	    {
		if (k==i) ans.push_back(ch);
		ans.push_back(st[k]);
	    }
	 
	//    for ( int k = 0 ; k < ans.size();  k++) printf("%c   ",ans[k]);
	//    printf("\n");
	    if (check())
	    {
		int siz = ans.size();
		for ( int ii = 0 ; ii < siz; ii++)
		{
		    printf("%c",ans[ii]);
		}
		return 0;
	    }
	    ans.clear();
//	    cout<<"st:"<<st<<" ch:"<<ch<<endl;
	    for ( int k = 0 ; k < len ; k++) ans.push_back(st[k]);

	    ans.push_back(ch);
	//    for ( int k = 0 ; k < ans.size() ; k++) printf("%c ",ans[k]);
	    if (check())
	    {
		int siz = ans.size();
		for ( int ii = 0 ; ii < siz; ii++)
		{
		    printf("%c",ans[ii]);
		}
		return 0;

	    }
	}

    }
    puts("NA");

#ifndef ONLINE_JUDGE  
    fclose(stdin);
#endif
    return 0;
}
