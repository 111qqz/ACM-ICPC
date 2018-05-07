/* ***********************************************
Author :111qqz
mail: hust.111qqz@gmail.com
Created Time :Sun 06 May 2018 05:51:49 PM EDT
File Name :a.cpp
************************************************ */

#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
#define ms(a,x) memset(a,x,sizeof(a))
typedef long long LL;
int main()
{
  #ifndef  ONLINE_JUDGE 
    freopen("./in.txt","r",stdin);
  #endif
	int n;
	string st;
	cin>>n;
	cin>>st;
	map<string,int>mp;
	for ( int i = 0 ; i < n-1 ; i++)
	{
		string tmp =  st.substr(i,2);
		//cout<<"tmp:"<<tmp<<endl;
		if (!mp[tmp]) mp[tmp]=1;
		else mp[tmp]++;
	}
	int mx = 0 ;
	string ans;
	for ( auto x: mp)
	{
		if (x.second > mx)
		{
			mx = x.second;
			ans = x.first;
		}
	}
	cout<<ans<<endl;




 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	
    return 0;
}
