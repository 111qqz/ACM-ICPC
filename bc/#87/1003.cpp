/* ***********************************************
Author :111qqz
Created Time :Sat 24 Sep 2016 07:02:01 PM CST
File Name :code/bc/#87/1003.cpp
************************************************ */

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1E5+7;
int data1[maxn],data2[maxn],pos1[maxn],pos2[maxn];
int f[maxn];
int n,m;
int main()
{
    freopen("code/in.txt","r",stdin);
    int T;
    cin>>T;
    while (T--)
    {
	memset(f,0,sizeof(f));
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%d",data1+i);
	for(int i=1;i<=m;++i) scanf("%d",data2+i);
	for(int i=1;i<=n;++i)
	{
	    int maxv=0;
	    for(int j=1;j<=m;++j)
	    {
		if(data2[j]<data1[i] && maxv<f[j])
		    maxv=f[j];
		if(data1[i]==data2[j])
		    f[j]=maxv+1;
	    }
	}
	int maxv=0;
	for(int i=1;i<=n;++i)
	    if(maxv<f[i])
		maxv=f[i];
	cout<<maxv<<endl;
    }
	return 0;
    }
