#include "stu.h"
char *sjt[SJTS]={"����","��ѧ","Ӣ��","����","��ѧ","����"};
void in(void)
{
    printf("����¼��ѧ����Ϣ:\n");
    FILE *fp;
    STUDENT One;
    int i;
    printf("������ѧ������:\n");
    scanf("%s",One.name);
    if(checkname(One.name)==1)
        return ;
    printf("������ѧ��ѧ��:\n");
    scanf("%s",One.xh);
    if(checkxh(One.xh)==1)
        return ;
    printf("����������ѧ���ɼ�:\n");
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
    printf("����ɹ�.\n");
    fclose(fp);
    ranking();
    return ;
}
