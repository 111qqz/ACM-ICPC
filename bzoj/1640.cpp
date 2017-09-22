/* ***********************************************
Author :111qqz
Created Time :2016年04月08日 星期五 16时16分34秒
File Name :code/bzoj/1640.cpp
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
const int N=3E4+7;
int n;
int a[N];
string ans;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	ios::sync_with_stdio(false);
	cin>>n;
	ans ="";
	for ( int i = 1 ;i <= n ; i++)
	{
	    char ch;
	    cin>>ch;
	    a[i] = ch-'A'+1;
	}

	int l = 1;
	int r = n ;

	while (l<=r)
	{
	    if (l==r)
	    {
	//	cout<<"aans:"<<ans<<endl;
		ans += char(a[l]+64);
	//	cout<<"aaans:"<<ans<<endl;
		
		break;
	    }
	    if (a[l]!=a[r])
	    {
		if (a[l]<a[r])
		{
		    ans += char(a[l]+64);
		    l++;
		}
		else
		{
		    ans += char(a[r]+64);
		    r--;
		}
	    }
	    else
	    {
		if (l==r) continue;
		int tmpl = l;
		int tmpr = r;
		while (a[tmpl]==a[tmpr]&&tmpl<tmpr)
		{
		    tmpl++;
		    tmpr--;
		}
//		cout<<"tmpl:"<<tmpl<<" tmpr:"<<tmpr<<" ans:"<<ans<<endl;	
		if (tmpl>=tmpr)
		{
		    while (l<=r)
		    {
	//		cout<<"l:"<<l<<" r:"<<r<<" ans:"<<ans<<endl;
			
			
			if (a[l]<=a[r])
			{
			    ans += char(a[l]+64);
			    l++;
			    break;
			}
			else
			{
			    ans += char(a[r]+64);
			    r--;
			    break;
			}
			//cout<<" ans:"<<ans<<endl;
		    }
		 /*   for ( int i = l ;  i <= r ; i++)
		    {
			if (tmpl==tmpr&&a[tmpl]>a[l]&&i==tmpl) continue;
			ans +=char(a[i]+64);
		    }
		    if (tmpl==tmpr&&a[tmpl]>a[l]) ans += char(a[tmpl]+64); */
		    //break;
		}
		else
		{
		    while (l<tmpl&&r>tmpr)
		    {
	//		cout<<"l:"<<l<<" r:"<<r<<" anssss:"<<ans<<endl;
    
			if (a[l]==a[r])
			{
			    if (a[tmpl]<=a[tmpr])
			    {
				ans += char(a[l]+64);
				l++;
				break;
			    }else
			    {
				ans += char(a[r]+64);
				r--;
				break;
			    }

			}
			else
			{

			    if (a[l]<a[r])
			    {
				ans+=char(a[l]+64);
				l++;
				break;
			    }
			    else 
			    {
				ans+=char(a[r]+64);
				r--;
				break;
			    }
			 //   cout<<"l:"<<l<<" r:"<<r<<" anssss:"<<ans<<endl;    
			}
		    }
			/*   if (a[tmpl]<a[tmpr])
		    {
			for ( int i = l ; i <= tmpl ; i++) ans +=char(a[i]+64);
			l = tmpl+1;
		    }
		    else
		    {
			for ( int i = r ; i >= tmpr ; i--) ans +=char(a[i]+64);
			r = tmpr-1;
		    }   */
		}
	    }
	   // cout<<"l:"<<l<<" r:"<<r<<" ans:"<<ans<<endl;
	    
	}
	int len = ans.length();
	for ( int i = 0 ; i < len ; i++)
	{
	    cout<<ans[i];
	    if ((i+1)%80==0) cout<<endl;
	}
//	cout<<ans<<endl;
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
