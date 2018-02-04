
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>

using namespace std;

const int N=5E2+7;
char maze[N][N];
int n,m;
int q;
int a[N][N],b[N][N];
int sum[N][N];
int sum2[N][N];
    
int main()
{
	cin>>n>>m;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	for ( int i = 0  ; i< n ;i++ ) scanf("%s",maze[i]);
	for ( int i = 1 ;  i < n ; i++)
	{
	    for (int  j =  0 ; j< m ;j++)
	    {
		if (maze[i][j]=='.'&&maze[i-1][j]=='.')
		    a[i+1][j+1]++;
	    }
	}
	
	for ( int i = 0 ; i < n ; i++)
	{
	    for ( int j = 1 ;  j < m ; j++)
	    {
		if (maze[i][j]=='.'&&maze[i][j-1]=='.')
		    b[i+1][j+1]++;
	    }
	}
	sum[0][0] = 0;
	sum2[0][0] =  0;
	for ( int i = 1 ; i <= n ; i++)
	{
	    for ( int j = 1 ;  j<= m ; j++)
	    {
		sum[i][j] =sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
		sum2[i][j] = sum2[i-1][j]+sum2[i][j-1]-sum2[i-1][j-1] + b[i][j];
	    }
	}
	cin>>q;

	while (q--)
	{
	    int n1,n2,m1,m2;
	    scanf("%d %d %d %d",&n1,&m1,&n2,&m2);
	    int ans = 0 ;
	    ans+=sum[n2][m2]-sum[n1-1][m2]-sum[n2][m1-1]+sum[n1-1][m1-1];
	    ans+=sum2[n2][m2]-sum2[n1-1][m2]-sum2[n2][m1-1]+sum2[n1-1][m1-1];
	    for ( int j = m1 ; j <= m2 ;j++)
	    {
		if (a[n1][j]==1) ans--;
	    }
	    for ( int i = n1 ; i <= n2 ; i++)
	    {
		if (b[i][m1]==1) ans--;
	    }
	        
	    printf("%d\n",ans);
	}

    return 0;
}
