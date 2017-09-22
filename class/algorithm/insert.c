/* ***********************************************
Author :111qqz
Created Time :2016年03月08日 星期二 22时04分04秒
File Name :code/class/algorithm/insert.c
************************************************ */
#include <stdio.h>

int a[15];
int n;

void qingkaishicharupaixu()
{
    
    for ( int j = 1 ; j < n ; j++)
    {
        int  key = a[j];
	int i = j-1 ; 
	while (i>=0 && a[i]>key)
	{
	    a[i+1] = a[i];
	    i--;
//	    printf("aaa");
	}
    

    a[i+1] = key;
    }
}

int main()
{
    freopen("code/in.txt","r",stdin);
    scanf("%d",&n);
    for ( int i = 0 ; i < n ; i++) scanf("%d",&a[i]);
    for ( int i = 0 ; i < n ; i++) printf("%d ",a[i]);
    printf("\n");
    qingkaishicharupaixu();

    for ( int i  = 0 ; i < n ; i++) printf("%d ",a[i]);
    

    return 0;

}
