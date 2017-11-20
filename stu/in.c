#include "stu.h"
char *sjt[SJTS]={"语文","数学","英语","物理","化学","政治"};
void in(void)
{
    printf("正在录入学生信息:\n");
    FILE *fp;
    STUDENT One;
    int i;
    printf("请输入学生姓名:\n");
    scanf("%s",One.name);
    if(checkname(One.name)==1)
        return ;
    printf("请输入学生学号:\n");
    scanf("%s",One.xh);
    if(checkxh(One.xh)==1)
        return ;
    printf("请依次输入学生成绩:\n");
    for(i=0;i<SJTS;i++)
        printf("%s ",sjt[i]);
    putchar('\n');
    for(i=0;i<SJTS;i++)
        scanf("%d",&One.score[i]);
    One.sum=0;
    for(i=0;i<SJTS;i++)
        One.sum+=One.score[i];
    One.ave=(float)One.sum/SJTS;
    fp=fopen("allstudent","ab");
    if(fp==NULL)
    {
        puts("Error!");
        return ;
    }
    fwrite(&One,sizeof(STUDENT),1,fp);
    printf("输入成功.\n");
    fclose(fp);
    ranking();
    return ;
}
