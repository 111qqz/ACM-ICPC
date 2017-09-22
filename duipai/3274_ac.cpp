#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 100005  
#define mod 1000000 //此处mod定义为99997时，运行时间1000多MS   
int hash[MAX*10];//hash表储存下标   
int sum[MAX][35];//第 1 头牛到第 i 头的对应属性的和   
int c[MAX][35];//存放每头牛属性 j与第一个属性的差   
int n,k;  
int Hash_key(int *cc)  
{  
    int j,key=0;  
    for(j=1;j<k;j++)  
        key=key%mod+cc[j]<<2;//此处用 * 乘超时   
    key=abs(key)%mod;//此处得到的key可能会是负数，所以取绝对值   
    return key;  
}  
int main()  
{  
    int i,j,x,maxlen=0;//maxlen为最大长度   
    scanf("%d%d",&n,&k);
    int l,r;
    memset(hash,-1,sizeof(hash));//初始化哈希表   
    hash[0]=0;//hash表首位初始化
    for(i=1;i<=n;i++)  
    {  
        scanf("%d",&x);  
        for(j=0;j<k;j++)  
        {  
          sum[i][j]=sum[i-1][j]+x%2;  
            c[i][j]=sum[i][j]-sum[i][0];  
            x>>=1;  
        }  
        int key=Hash_key(c[i]);  
        while(hash[key]!=-1)//处理关键字冲突   
        {  
            for(j=0;j<k;j++)//当前牛的属性与其关键字相同的进行比较   
                if( c[i][j]!=c[ hash[key] ][j] )  
                    break;  
            if(j==k && maxlen<(i-hash[key]))//若j==k，说明两头牛的属性个数相同   
            {  
                maxlen=i-hash[key];  
		l = i ;
		r = hash[key];
                break;  
            }  
            key++;//往后继续移动处理冲突   
        }  
        if(hash[key]==-1)  
            hash[key]=i; //将下标存放在hash中   
    }  
    if (l>r) swap(l,r);
    printf("%d %d\n",l,r);
    printf("%d\n",maxlen);    
    return 0;  
}  


