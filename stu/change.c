#include "stu.h"
extern char *sjt[SJTS];
void change(void)
{
    printf("正在修改学生信息:\n");
    int i,flag=1;
    STUDENT one;
    FILE *fp;
    long a;
    char ch[10];
    fp=fopen("allstudent","rb+");
    if(fp==NULL)
    {
        puts("Error.");
        return ;
    }
    printf("请输入学号或姓名：");
    scanf("%s",ch);
    a=ftell(fp);
    fread(&one,sizeof(STUDENT),1,fp);
    while(!feof(fp))
    {
        if((strcmp(one.xh,ch)==0)||(strcmp(one.name,ch)==0))
        {
            fseek(fp,a,0);
            flag=0;
            printf("已获取该学生信息，下面请重置该学生信息：\n");
            printf("请输入学生姓名:\n");
            scanf("%s",one.name);
            if(checkname2(one.name)==1)
                return ;
            printf("请输入学生学号:\n");
            if(checkxh2(one.xh)==1)
                return ;
            scanf("%s",one.xh);
            printf("请依次输入学生成绩:\n");
            for(i=0;i<SJTS;i++)
                printf("%s ",sjt[i]);
            putchar('\n');
            for(i=0;i<SJTS;i++)
                scanf("%d",&one.score[i]);
            one.sum=0;
            for(i=0;i<SJTS;i++)
                one.sum+=one.score[i];
            one.ave=(float)one.sum/SJTS;
            fwrite(&one,sizeof(STUDENT),1,fp);
            printf("修改成功.\n");
            break;
        }
        a=ftell(fp);
        fread(&one,sizeof(STUDENT),1,fp);
    }
    if(flag)
    {
        puts("该学号不存在！\n");
    }
    fclose(fp);
    ranking();
    return ;
}
