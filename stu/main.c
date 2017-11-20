#include "stu.h"
int main(void)
{
    SetConsoleTitle("学生信息管理系统V1.4");
    int n,flag=0;
    printf("********************************************************************************\n");
	printf("***                            ◤              ◥                            ***\n");
	printf("***                             学生信息管理系统                             ***\n");
	printf("***                            ◣              ◢                            ***\n");
	printf("********************************************************************************\n");
    loop:
    printf("********************************************************************************\n");
    printf("***                         请输入指令对应数字进行操作                       ***\n");
    printf("***                1.登录系统 2.退出系统   3.输入信息 4.查询信息             ***\n");
    printf("***                5.修改信息 6.输出成绩表 7.删除信息 8.排序系统             ***\n");
    printf("***                9.清屏功能 10.关闭系统                                    ***\n");
    printf("********************************************************************************\n");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
            system("CLS");
            flag=login();
            break;
        case 2:
            flag=0;
            system("CLS");
            printf("退出成功！\n");
            break;
        case 9:
            system("CLS");
            break;
        case 10:
            return 0;
     }
    if(n>=10)
    {
        system("CLS");
        printf("指令无效，请重新输入.\n");
    }
    if(n>=3 && !flag && n<=8)
    {
        system("CLS");
        printf("请先登录管理系统.\n");
    }
    if(n>=3 && flag && n<=8)
        switch(n)
        {
            case 3:
                system("CLS");
                in();
                break;
            case 4:
                system("CLS");
                out();
                break;
            case 5:
                system("CLS");
                change();
                break;
            case 6:
                system("CLS");
                table();
                break;
            case 7:
                system("CLS");
                del();
                break;
            case 8:
                system("CLS");
                sorting();
                break;
        }
    putchar('\n');
    goto loop;
}
