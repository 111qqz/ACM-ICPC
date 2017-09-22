/* ***********************************************
Author :111qqz
Created Time :2015年12月29日 星期二 21时37分11秒
File Name :code/cf/problem/31C.cpp
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
int n ;
int ans[N];

struct node
{
    int fst,sec;
    int id;

    bool operator <(node b)const
    {
	if (fst<b.fst) return true;
	if (fst==b.fst&&sec<b.sec) return true;
	return false;
    }
}a[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n;
	for ( int i = 1 ; i <= n ; i++) cin>>a[i].fst>>a[i].sec,a[i].id = i ;

	sort(a+1,a+n+1);

//	for ( int i = 1 ; i <= n ; i++) cout<<a[i].fst<<endl;
	a[n+1].fst = inf;
	int num = 0 ;
	bool ill=false,die=false;
	for ( int i = 1 ; i <= n ; i++)
	{
	    int j = i+1;
	    int cnt =  0;
	    while (a[j].fst<a[i].sec&&j<=n)
	    {
	//	cout<<"i:"<<i<<" j:"<<j<<endl;
		if (ill)
		{
		    die = true;
		    break;
		}
		j++;
		cnt++;
	    }
	    if (die) break;
	    
	    if (cnt==0) continue;
	    ill = true;
	    j--;
	    
	    if (cnt>=2)
	    {
		num++;
		ans[num] = a[i].id;
	    }
	    else
	    {
		if (a[j+1].fst<a[j].sec&&j+1<=n)
		{
		    num++;
		    ans[num] =  a[j].id;
		    i++;
		}
		else
		{
		    num++;
		    ans[num] =  a[i].id;
		    num++;
		    ans[num] =  a[j].id;
		}
	    }
	}
	if (die)
	{
	  //  cout<<"wwwww"<<endl;
	    puts("0");
	    return 0;
	}
	if (!ill)
	{
	    cout<<n<<endl;
	    for ( int i = 1 ; i <= n-1 ; i++) printf("%d ",i);
	    printf("%d\n",n);
	}
	else
	{
	    cout<<num<<endl;
	    sort(ans+1,ans+num+1);  //id的顺序未必是升序。所以需要再次sort下。
	    for (  int i =1 ; i <= num-1  ; i++) printf("%d ",ans[i]);
	    printf("%d\n",ans[num]);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
