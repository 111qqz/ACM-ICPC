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
const int N=2E5+7;
int n,k;
vector<int>vec;
int main()
{
  #ifndef  ONLINE_JUDGE 
    freopen("./in.txt","r",stdin);
  #endif 
	cin>>n>>k;
	for ( int i = 1 ; i <= n ; i++)
	{
		int x;
		cin>>x;
		vec.push_back(x);
	}

	sort(vec.begin(),vec.end());
	int siz = vec.size();
	if (k==0)
	{
		if (vec[0]>1) cout<<1<<endl;
		else cout<<-1<<endl;
		return 0;
	}
	if (k==n||(vec[k-1]!=vec[k]))
	{
		cout<<vec[k-1]<<endl;
	}else
	{
		cout<<-1<<endl;
	}



 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	
    return 0;
}
