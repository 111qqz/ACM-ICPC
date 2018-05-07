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
int n;
int a[N];
unordered_map<int ,int>mp;
int ANS[N];
int main()
{
  #ifndef  ONLINE_JUDGE 
    freopen("./in.txt","r",stdin);
  #endif
	cin>>n;
	for ( int i = 1 ; i <= n ; i++) scanf("%d",&a[i]);
	for ( int i = 1 ; i <= n ; i++)
	{
		if (!mp[a[i]-1])  mp[a[i]] = 1;
		else mp[a[i]] = max(mp[a[i]-1]+1,mp[a[i]]);
	}
	int ans = 0;
	for ( auto x : mp)
	{
		ans = max(ans,x.second);
//		cout<<x.first<<" "<<x.second<<endl;
	}
	cout<<ans<<endl;
	int down = ans;
	int X;
	for ( int i = n  ; i >= 1 ; i--) 
	{
		
		if (mp[a[i]]==ans)
		{
			X = a[i];
			ANS[down] = i;
			break;
		}
	}
	int Y = ANS[down];
	for ( int i = Y ; i >= 1 ; i--)
	{
		//puts("miao");
		if (a[i]==X-1)
		{
			X = a[i];
			down--;
			ANS[down] = i;
		}
		if (down==1) break;
	}
	for ( int i = 1 ; i <= ans ; i++) printf("%d%c",ANS[i],i==ans?'\n':' ');





		

 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	
    return 0;
}
