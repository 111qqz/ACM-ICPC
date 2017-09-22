/*************************************************************************
	> File Name: code/class/2.c
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年11月11日 星期三 17时17分04秒
 ************************************************************************/

#include<stdio.h>
#include <ctype.h>
#include <string.h>

char st[1005];
int main()
{
    gets(st);
    int len = strlen(st);
    int cnt_dig=0,cnt_alp=0,cnt_oth=0;
    for ( int i = 0 ; i < len ; i++)
    {
	if (isdigit(st[i]))
	    cnt_dig++;
	else if (isalpha(st[i]))
	    cnt_alp++;
	else cnt_oth++;
    }
    printf("字母个数：%d\n",cnt_alp);
    printf("数字个数：%d\n",cnt_dig);
    printf("其他字符个数: %d\n",cnt_oth);
}

