#include <cstdio>


#define i64 long long

i64 Md[15],w[15],n;  //w[]保存余数

i64 Extended_Euclid (i64 a,i64 b,i64 &x,i64 &y)
{//扩展欧几里得算法,求ax+by=gcd(a,b)的一组解(x,y),d=gcd(a,b)
	i64 d;
	if (b==0)
	{
		x=1;y=0;
		return a;
	}
	d=Extended_Euclid(b,a%b,y,x);
	y-=a/b*x;
	return d;
}

i64 Chinese_Remainder (i64 w[],i64 Md[],int len)
{//中国剩余定理不互质
	bool flag=false;
	i64 n1=Md[0], b1=w[0],x,y;
	for (int i=1;i<len;i++)
	{
		i64 n2=Md[i], b2=w[i];
		i64 bb=b2-b1;
		i64 d=Extended_Euclid (n1,n2,x,y);
		if (bb % d)		//模线性解k1时发现无解
		{
			flag = true;
			break;
		}
		i64 k = bb/d*x;  //相当于求上面所说的k1【模线性方程】
		i64 t = n2/d;
		if (t < 0) t = -t;
		k = (k % t + t) % t;	//相当于求上面的K`
		b1 = b1 + n1*k;
		n1 = n1 / d * n2;
	}
    
	printf("b1:%lld\n",b1);
	if (flag) return 0;  //无解
    if (b1 == 0)    //如果解为0，而题目要正整数解
        b1 = n1;    //n1刚好为所有ni的最小公倍数，就是解了
    if (b1 > n)
        return 0;
    return (n-b1)/n1+1;  //形成的解：b1, b1+n1, b1+2n1,..., b1+xni...  
}  
  

int main ()
{
#ifdef ONLINE_JUDGE
#else
	freopen("code/in.txt","r",stdin);
#endif
	int T,i,m;
	scanf("%d",&T);
	while (T--)
	{
        scanf("%lld%d",&n,&m);
		for (i=0;i<m;i++)
			scanf("%lld",&Md[i]);
		for (i=0;i<m;i++)
			scanf("%lld",&w[i]);
		printf("%lld\n",Chinese_Remainder(w,Md,m));
    }
	return 0;
}
