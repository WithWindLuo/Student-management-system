#include "stu.h"
extern char *sjt[SJTS];
void del(void)
{
    printf("����ɾ��ѧ���ɼ�:\n");
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
    printf("������Ҫɾ����ѧ����ѧ�Ż�������");
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
            printf("��ѧ�Ż�������������.\n");
        else
        {
            printf("��Ҫɾ����ѧ����ϢΪ��\n");
            printf("����  ѧ��  ");
            for(i=0;i<SJTS;i++)
                printf("%-6s ",sjt[i]);
            printf("�ܷ�  ƽ����  ����\n");
            printf("%-5s %-5s ",one.name,one.xh);
            for(i=0;i<SJTS;i++)
                printf("%-6d ",one.score[i]);
            printf("%-5d %-6.2f  %d\n",one.sum,one.ave,one.order);
            printf("�Ƿ�ȷ��(Y or N):_\b");
            scanf("%c",&chara);
            if(chara=='Y')
            {
                if((remove("allstudent")==0) && (rename("temp","allstudent")==0))
                {
                    printf("ɾ���ɹ�.\n");
                    ranking();
                }
                else
                    printf("ɾ��ʧ��.\n");
            }
            else
                printf("��ȡ��ɾ��.\n");
        }
    return ;
}
