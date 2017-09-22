/*************************************************************************
	> File Name: code/2015summer/0821/A.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月20日 星期四 22时17分14秒
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
#define y0 abc111qqz
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define tm crazy111qqz
#define lr dying111qqz
using namespace std;
#define REP(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef unsigned long long ULL;
const int inf = 0x7fffffff;
const int N=1E7+7;
using namespace std;

bool not_prime[N];
int prime[N],pri_num;
map<int,bool> mp;
int a[N];
int ans;
map<int,bool>::iterator it;
char st[15];
int len;
void init()
{

    not_prime[0] =true;
    not_prime[1] = true;

    for(int i = 2;i < N; ++i) 
    {
	if(!not_prime[i])
	    prime[++pri_num] = i;
	for(int j = 1;j <= pri_num && i * prime[j] < N; j++) 
	{

	    not_prime[i * prime[j]] = true;
	    if(i % prime[j] == 0)   break;  
	}
    }
}
    
void solve()
{
    
    int res = 0;
    for(int i = 1;i <= len; ++i) 
    {

	res = res * 10 + a[i];
//	cout<<"res:"<<res<<endl;
	if(!not_prime[res] && !mp[res])
	{
	    mp[res] = true;
	    ans++;
	}
    }
}

int main()
{
	init();
//	for ( int i =2 ; i <= 1000 ; i++)
//	{
//	    if (!not_prime[i])
//	    {
//		cout<<i<<endl;
//	    }
//	}
	int T;
	cin>>T;
	while (T--)
	{
		
		ans = 0 ;
		mp.clear();
		scanf("%s",st+1);
		len = strlen(st + 1);
		for(int i = 1;i <= len; i++)
		{
			a[i] = st[i] - '0';
		}
		sort(a+1,a+len+1);
		  do
		    {
			solve();
		    }while (next_permutation(a+1,a+len+1));
		

		printf("%d\n",ans);
	}
	return 0;
}


