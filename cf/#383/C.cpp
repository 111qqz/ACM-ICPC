#include<iostream>  
#include<cstring>  
#include<cstdlib>  
#include<queue>  
#include<cstdio>  
#include<climits>  
#include<algorithm>  
using namespace std;  
  
const int N=111;  
const int INF=0xfffffff;  
  
int min_loop;  
int num;  
int map[N][N],dist[N][N],pre[N][N];  
int path[N];  
int n,m;  
  
void dfs(int i,int j)  
{  
    int k=pre[i][j];  
    if(k==0)  
    {  
        path[num++]=j;  
        return;  
    }  
    dfs(i,k);  
    dfs(k,j);  
}  
  
void Floyd()  
{  
    min_loop=INF;  
    memset(pre,0,sizeof(pre));  
    for(int k=1; k<=n; k++)  
    {  
        for(int i=1; i<k; i++)  
        {  
            for(int j=i+1; j<k; j++)  
            {  
                if(dist[i][j]+map[i][k]+map[k][j]<min_loop)  
                {  
                    min_loop=dist[i][j]+map[i][k]+map[k][j];  
                    num=0;  
                    path[num++]=i;  
                    dfs(i,j);  
                    path[num++]=k;  
                }  
            }  
        }  
  
        for(int i=1; i<=n; i++)  
        {  
            for(int j=1; j<=n; j++)  
            {  
                if(dist[i][k]+dist[k][j]<dist[i][j])  
                {  
                    dist[i][j]=dist[i][k]+dist[k][j];  
                    pre[i][j]=k;  
                }  
            }  
        }  
    }  
}  
  
int main()  
{
	freopen("code/in.txt","r",stdin);
	cin>>n;
        for(int i=1; i<=n; i++)  
        {  
            for(int j=i+1; j<=n; j++)  
                map[i][j]=map[j][i]=dist[i][j]=dist[j][i]=INF;  
            map[i][i]=dist[i][i]=0;  
        }  
	for ( int i = 1 ; i <= n ; i++)
        {  
            int u,v;
	    u = i ;

	    scanf("%d",&v);
	    if (u==v) continue;
                map[u][v]=101;
		map[v][u]=101;  
                dist[u][v]=101;
		dist[v][u]=101;  
        }  
        Floyd();
	cout<<"num:"<<num<<endl;
        if(min_loop==INF)  
            puts("No solution.");  
        else  
        {  
            //for(int i=0; i<num-1; i++)  
            //    printf("%d ",path[i]);  
            //printf("%d\n",path[num-1]);  
	    printf("%d",num);
        }  
    return 0;  
}  
