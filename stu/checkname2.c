#include"stu.h"
extern char *sjt[SJTS];
int checkname2(char ch[])        //��ѯ����
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
            printf("�޸�ʧ�ܣ��������Ѵ���.\n");
            printf("����  ѧ��  ");
            for(i=0;i<SJTS;i++)
                printf("%-6s ",sjt[i]);
            printf("�ܷ�  ƽ����  ����\n");
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

