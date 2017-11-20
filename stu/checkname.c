#include"stu.h"
extern char *sjt[SJTS];
int checkname(char ch[])        //查询函数
{
    FILE *fp;
    STUDENT one;
    int i,flag=1;
    fp=fopen("allstudent","rb");
    if(fp==NULL)
    {
        puts("Error!");
        return ;
    }
    fread(&one,sizeof(STUDENT),1,fp);
    while(!feof(fp))
    {
        if(strcmp(one.name,ch)==0)
        {
            printf("输入失败，该姓名已存在.\n");
            printf("姓名  学号  ");
            for(i=0;i<SJTS;i++)
                printf("%-6s ",sjt[i]);
            printf("总分  平均分  名次\n");
            printf("%-5s %-5s ",one.name,one.xh);
            for(i=0;i<SJTS;i++)
                printf("%-6d ",one.score[i]);
            printf("%-5d %-6.2f  %d\n",one.sum,one.ave,one.order);
            return 1;
        }
        fread(&one,sizeof(STUDENT),1,fp);
    }

    fclose(fp);
    return 0;
}

