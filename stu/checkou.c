#include "stu.h"
extern char *sjt[SJTS];
void checkout(char ch[])  //��ѯ�ظ�֮������ظ�ѧ����Ϣ����
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
            printf("������%s\n",one.name);
            for(i=0;i<SJTS;i++)
                printf("%s:%d ",sjt[i],one.score[i]);
            putchar('\n');
            printf("�ܷ֣�%d ƽ���֣�%.2f ����: %d\n",one.sum,one.ave,one.order);
            break;
        }
        fread(&one,sizeof(STUDENT),1,fp);
    }
    if(flag)
    {
        puts("��ѧ�Ų����ڣ�\n");
    }
    fclose(fp);
    return ;
}

}