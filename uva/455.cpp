/*************************************************************************
	> File Name: code/uva/455.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年09月17日 星期四 18时30分06秒
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
#include<cctype>
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define ms(a,x) memset(a,x,sizeof(a))
#define lr dying111qqz
using namespace std;
#define For(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;
string blank;
string st;
int len;
int main()
{
  #ifndef  ONLINE_JUDGE 
    freopen("in.txt","r",stdin);  
  #endif
    int T;
    cin>>T;
    while (T--)
    {
	
	cin>>st;
	len = st.length();
	int ans=len;
//	cout<<"len:"<<len<<endl;
	for ( int i = 1 ; i <= len ; i++)
	{
	    if (len %i!=0) continue;
	    bool flag = true;
	    string fst = st.substr(0,i);  //后面的每一个串都和第一个串判断
	    string snd;
//	    cout<<"fst:"<<fst<<endl;
	    for ( int j = i ;j < len ; j = j + i)
	    {
		snd = st.substr(j,i);
//		cout<<"snd:"<<snd<<endl;
		if (fst!=snd)
		{
	 	    flag = false;
		    break;
		}
	    }
	    if (flag)
	    {
		ans = i ;
		break;
	    }
	}
	printf("%d\n",ans);
	if (T) printf("\n");
    }
    
  
  
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
