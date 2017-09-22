/*************************************************************************
	> File Name: code/uva/10340.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年09月17日 星期四 10时58分11秒
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
string a,b;
int main()
{
  #ifndef  ONLINE_JUDGE 
    freopen("in.txt","r",stdin);  
  #endif
    while (cin>>a>>b)
    {
	int lena = a.length();
	int lenb = b.length();
	cout<<a<<endl;
	cout<<b<<endl;
	int posi = 0 ;
	cout<<"lenb:"<<lenb<<endl;
	for (int i = 0 ; i < lenb ; i++)
	{
	    cout<<"fuck"<<endl;  
	    if (a[posi]==b[i])
	    {
		cout<<a[posi]<<"  "<<b[i]<<endl;
		posi++;
	    }
	    if (posi = lena-1)
	    {
	//	break;
	    }
	    cout<<"posi"<<posi<<endl;

	}
	if (posi==lena-1)
	{
	    puts("Yes");
	}
	else
	{
	    puts("No");
	}
    }
  
  
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
