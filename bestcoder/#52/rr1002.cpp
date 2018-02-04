#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

const int maxn=12;
const int maxm=1<<11|1;

int n,m;
int map[maxn][maxn];
int dp[maxm][maxn];

void floyd()
{
    for (int k=0 ; k<=n ; ++k)
        for (int i=0 ; i<=n ; ++i)
            for (int j=0 ; j<=n ; ++j)
                if(map [i][j]>map[i][k]+map[k][j])
                    map[i][j]=map[i][k]+map[k][j];
}

int main ()
{
    int T;
    cin>>T;
    while (T--)
    {
	scanf("%d%d",&n,&m);
	memset(map,0x3f,sizeof(map));
	int x,y,w;
	for ( int i =0 ; i < m ; i++ ){
	    scanf("%d %d %d",&x,&y,&w);
	    if (map[x-1][y-1]>w){
		map[x-1][y-1] = w;
		map[y-1][x-1] = w;
	    }
	}
        floyd();
        memset (dp , 63 , sizeof(dp));
        for (int i=0 ; i<(2<<n) ; ++i)
        {

            for (int j=0 ; j<=n ; ++j)
            {
                 dp[1<<j][j]=map[0][j];
                //if(i==1<<j)dp[i][j]=map[0][j];这个和上面的语句都能AC
                if(i&(1<<j))
                     for (int k=0 ; k<=n ; ++k)
                    {
                        if((i-(1<<j)) & (1<<k))//第k位为1，第j位不为1的状态
                        dp[i][j]=min(dp[i-(1<<j)][k]+map[k][j],dp[i][j]);
                    }
                    //printf("%d %d %d\n",i,j,dp[i][j]);
            }

        }
        int ans=dp[(2<<n)-1][0];
        for (int i=1 ; i<=n ; ++i)
        {
            ans=min(dp[(2<<n)-1][i]+map[i][0],ans);
        }
        printf("%d\n",ans);
    }
    return 0;
}

