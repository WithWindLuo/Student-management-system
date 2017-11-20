#include"stu.h"
void sorting(void)
{
    int n;
    printf("正在排序学生信息:\n");
    printf("请选择排序的方式:\n");
    printf("1.按学号进行排序       2.按总分进行排序\n");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
            sorting1();
            break;
        case 2:
            sorting2();
            break;
        default:
            break;
    }
    return ;
}
