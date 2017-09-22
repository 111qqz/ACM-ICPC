/*************************************************************************
	> File Name: code/class/20151125/7.c
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年11月25日 星期三 18时57分31秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>

int n;
char st[10005];
int len;
int main()
{

  //  scanf("%s",st);
    gets(st);

    len = strlen(st);
    int cnt  = 0;
    for ( int i = 0 ; i < len ; i ++)
    {
	if (st[i]==' '&&st[i+1]!=' ') cnt++;
    }
    cnt++;
   printf("%d\n",cnt);

    return 0;

}
