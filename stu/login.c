#include "stu.h"
int login(void)
{
    printf("正在登录学生信息管理系统:\n");
    char key[10]="666";
    char ch[10];
    printf("请输入管理员密码以登录：___\b\b\b");
    scanf("%s",ch);
    if(strcmp(key,ch)==0)
    {
        printf("登录成功！\n");
        return 1;
    }
    else
    {
        printf("登录失败！\n");
        return 0;
    }
}
