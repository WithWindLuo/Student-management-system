#include "stu.h"
extern char*sjt[SJTS];
void table(void)
{
    FILE *fp;
    STUDENT one;
    int i;
    if((fp=fopen("allstudent","rb"))==NULL)
    {
        puts("ERROR.");
        return ;
    }
    printf("����  ѧ��  ");
    for(i=0;i<SJTS;i++)
        printf("%-6s ",sjt[i]);
    printf("�ܷ�  ƽ����  ����\n");
    fread(&one,sizeof(STUDENT),1,fp);
    while(!feof(fp))
    {
        printf("%-5s %-5s ",one.name,one.xh);
        for(i=0;i<SJTS;i++)
            printf("%-6d ",one.score[i]);
        printf("%-5d %-6.2f  %d\n",one.sum,one.ave,one.order);
        fread(&one,sizeof(STUDENT),1,fp);
    }
    fclose(fp);
    printf("�ɼ���������.\n");
    return ;

}
