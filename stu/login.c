#include "stu.h"
int login(void)
{
    printf("���ڵ�¼ѧ����Ϣ����ϵͳ:\n");
    char key[10]="666";
    char ch[10];
    printf("���������Ա�����Ե�¼��___\b\b\b");
    scanf("%s",ch);
    if(strcmp(key,ch)==0)
    {
        printf("��¼�ɹ���\n");
        return 1;
    }
    else
    {
        printf("��¼ʧ�ܣ�\n");
        return 0;
    }
}
