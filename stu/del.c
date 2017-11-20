#include "stu.h"
extern char *sjt[SJTS];
void del(void)
{
    printf("正在删除学生成绩:\n");
    FILE *fp1,*fp2;
    char ch[10],chara;
    STUDENT one;
    int flag=1,i;
    if((fp1=fopen("allstudent","rb+"))==NULL)
    {
        puts("ERROR.");
        return ;
    }

    if((fp2=fopen("temp","wb+"))==NULL)
    {
        puts("ERROR.");
        return ;
    }
    printf("请输入要删除的学生的学号或姓名：");
    scanf("%s",ch);
    fread(&one,sizeof(STUDENT),1,fp1);
    while(!feof(fp1))
    {
        if((strcmp(one.xh,ch)==0)||(strcmp(one.name,ch)==0))
        {
            flag=0;
        }
        else
            fwrite(&one,sizeof(STUDENT),1,fp2);
        fread(&one,sizeof(STUDENT),1,fp1);
    }
    fclose(fp1);
    fclose(fp2);
    getchar();
        if(flag)
            printf("该学号或姓名不不存在.\n");
        else
        {
            printf("您要删除的学生信息为：\n");
            printf("姓名  学号  ");
            for(i=0;i<SJTS;i++)
                printf("%-6s ",sjt[i]);
            printf("总分  平均分  名次\n");
            printf("%-5s %-5s ",one.name,one.xh);
            for(i=0;i<SJTS;i++)
                printf("%-6d ",one.score[i]);
            printf("%-5d %-6.2f  %d\n",one.sum,one.ave,one.order);
            printf("是否确定(Y or N):_\b");
            scanf("%c",&chara);
            if(chara=='Y')
            {
                if((remove("allstudent")==0) && (rename("temp","allstudent")==0))
                {
                    printf("删除成功.\n");
                    ranking();
                }
                else
                    printf("删除失败.\n");
            }
            else
                printf("已取消删除.\n");
        }
    return ;
}
