#include "stu.h"
extern char *sjt[SJTS];
void change(void)
{
    printf("�����޸�ѧ����Ϣ:\n");
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
    printf("������ѧ�Ż�������");
    scanf("%s",ch);
    a=ftell(fp);
    fread(&one,sizeof(STUDENT),1,fp);
    while(!feof(fp))
    {
        if((strcmp(one.xh,ch)==0)||(strcmp(one.name,ch)==0))
        {
            fseek(fp,a,0);
            flag=0;
            printf("�ѻ�ȡ��ѧ����Ϣ�����������ø�ѧ����Ϣ��\n");
            printf("������ѧ������:\n");
            scanf("%s",one.name);
            if(checkname2(one.name)==1)
                return ;
            printf("������ѧ��ѧ��:\n");
            if(checkxh2(one.xh)==1)
                return ;
            scanf("%s",one.xh);
            printf("����������ѧ���ɼ�:\n");
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
            printf("�޸ĳɹ�.\n");
            break;
        }
        a=ftell(fp);
        fread(&one,sizeof(STUDENT),1,fp);
    }
    if(flag)
    {
        puts("��ѧ�Ų����ڣ�\n");
    }
    fclose(fp);
    ranking();
    return ;
}
