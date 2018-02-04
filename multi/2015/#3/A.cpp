/*************************************************************************
	> File Name: code/2015summer/#3/A.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年07月28日 星期二 12时27分08秒
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
const int N=1E4+5;
char a[N];
int k;
int main()
{

    cin>>a>>k;
    int l=strlen(a);
    int m,ans;
    m=l+k;
    if (m%2==1) m--;
    if(k>=l)
    {
	cout<<m<<endl;
	return 0;
    }
    int max=0;
    for(int i = 0 ; i < l ; i++)
    {
        for(int j = 1 ; j <= l-i;j++)
        {
	    ans = 0;
            for(int o = i ; o < i+j ; o++)
            {
		
                if(o+j>=l&&o+j<l+k)
                    ans++;
                else if(a[o]==a[o+j])
                     ans++;
            }
            if(ans==j&&2*ans>max)
              max=2*ans;
        }
    }
    cout<<max<<endl;
    return 0;
}

