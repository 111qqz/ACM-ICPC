#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,top,zhan[500001];
long long ans;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		while (top>1 && zhan[top-1]>=zhan[top]&& zhan[top]<=x) 
		{
			ans+=min(zhan[top-1],x);
			cout<<ans<<endl;
			top--;
		}
		zhan[++top]=x;
	}
	sort(zhan+1,zhan+top+1);
	for (int i=1;i<=top-2;i++)
	{
		ans+=zhan[i];
		cout<<ans<<endl;
	}
	printf("%lld",ans);
}
