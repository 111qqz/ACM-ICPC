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
    //freopen("./in.txt","r",stdin);
  #endif
	int n,k;
	cin>>n>>k;
	for ( int i = 1 ; i <= k ; i++)
	{
		if (n%10==0) n/=10;
		else n--;
	}
	cout<<n<<endl;

 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	
    return 0;
}
