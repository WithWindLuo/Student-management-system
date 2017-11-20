#include "stu.h"
extern char *sjt[SJTS];
void checkout(char ch[])  //查询重复之后输出重复学生信息函数
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
        if((strcmp(one.xh,ch)==0)||(strcmp(one.name,ch)==0))
        {
            flag=0;
            printf("姓名：%s\n",one.name);
            for(i=0;i<SJTS;i++)
                printf("%s:%d ",sjt[i],one.score[i]);
            putchar('\n');
            printf("总分：%d 平均分：%.2f 名次: %d\n",one.sum,one.ave,one.order);
            break;
        }
        fread(&one,sizeof(STUDENT),1,fp);
    }
    if(flag)
    {
        puts("该学号不存在！\n");
    }
    fclose(fp);
    return ;
}

}
