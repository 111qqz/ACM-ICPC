#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n , m ;
struct Mat {//矩阵
    int mat[30][30];
    void init(  )
    {//初始化
        int i ;
        memset ( mat, 0 ,sizeof ( mat ) ) ;
        for ( i = 0 ; i < 30 ; i ++ )
            mat[i][i] = 1 ;
    }

    void out()
    {
	for ( int i = 0 ; i < n ; i++)
	{
	    for ( int j = 0 ; j < n-1 ; j++)
	    {
		printf("%d ",mat[i][j]);
	    }
	    printf("%d\n",mat[i][n-1]);
	}
    }
}s;
Mat operator + ( Mat a ,Mat b)
{
    Mat c;
    for ( int i = 0 ; i < n ; i++)
	for ( int j = 0 ; j < n ; j++)
	    c.mat[i][j] = (a.mat[i][j] + b.mat[i][j]) % m;
    return c;
}
Mat operator * ( Mat a , Mat b )
{//矩阵乘法，计算时记得要取模，避免超int
    int i , j , k ;
    Mat c ;
    for ( i = 0 ; i < n ; i ++ )
    {
        for ( j = 0 ; j < n ; j ++ )
        {
            c.mat[i][j]=0;
            for ( k = 0 ; k < n ; k ++ )
                c.mat[i][j] +=((a.mat[i][k]*b.mat[k][j])%m) ;
            c.mat[i][j] %= m ;
        }
    }
    return c ;
}
Mat operator ^ ( Mat s , int k  )
{//矩阵的k次方，快速幂
    Mat ans ;
    ans .init () ;
    while ( k >= 1 )
    {
        if ( k & 1 )
            ans = ans * s;
        k = k >> 1 ;
        s = s * s;
    }
    return ans ;
}
Mat sum ( int k)
{
    if (k==1) return s;
    Mat res;
    res.init();
    res = res + (s^(k>>1));
    res = res * sum(k>>1);
    if (k&1) res = res + (s^k);
    return res;
}
/*
Mat sum ( Mat s , int k )
{//举证前k项求和
    if ( k == 1 )
        return s ;
    Mat tmp ;//用来保存答案
    tmp.init();//初始化
    tmp = Matadd ( tmp , mul ( s , k >> 1 ) );    //计算1+A^(k/2)
    tmp = Matmul ( tmp , sum ( s , k >> 1 ) ) ;    //计算(1+A^(k/2))*(A + A^2 + A^3 + … + A^(k/2)  )
    if ( k&1 )//考虑是否要+A^k
        tmp = Matadd ( tmp , mul ( s , k ) ) ;
    return tmp ;//返回前n项的值
}
*/
int main()
{
    int k ;
    //freopen("./in.txt","r",stdin);
	scanf("%d%d%d",&n,&k,&m);
        int i , j ;
        for ( i = 0 ; i < n ; i ++ )
            for ( j = 0 ; j < n ; j ++ )
                cin >> s.mat[i][j] ;
        s = sum ( k ) ;
	s.out();
        //print(s);    
    return 0;
}
