#include "stu.h"
int main(void)
{
    SetConsoleTitle("ѧ����Ϣ����ϵͳV1.4");
    int n,flag=0;
    printf("********************************************************************************\n");
	printf("***                            ��              ��                            ***\n");
	printf("***                             ѧ����Ϣ����ϵͳ                             ***\n");
	printf("***                            ��              ��                            ***\n");
	printf("********************************************************************************\n");
    loop:
    printf("********************************************************************************\n");
    printf("***                         ������ָ���Ӧ���ֽ��в���                       ***\n");
    printf("***                1.��¼ϵͳ 2.�˳�ϵͳ   3.������Ϣ 4.��ѯ��Ϣ             ***\n");
    printf("***                5.�޸���Ϣ 6.����ɼ��� 7.ɾ����Ϣ 8.����ϵͳ             ***\n");
    printf("***                9.�������� 10.�ر�ϵͳ                                    ***\n");
    printf("********************************************************************************\n");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
            system("CLS");
            flag=login();
            break;
        case 2:
            flag=0;
            system("CLS");
            printf("�˳��ɹ���\n");
            break;
        case 9:
            system("CLS");
            break;
        case 10:
            return 0;
     }
    if(n>=10)
    {
        system("CLS");
        printf("ָ����Ч������������.\n");
    }
    if(n>=3 && !flag && n<=8)
    {
        system("CLS");
        printf("���ȵ�¼����ϵͳ.\n");
    }
    if(n>=3 && flag && n<=8)
        switch(n)
        {
            case 3:
                system("CLS");
                in();
                break;
            case 4:
                system("CLS");
                out();
                break;
            case 5:
                system("CLS");
                change();
                break;
            case 6:
                system("CLS");
                table();
                break;
            case 7:
                system("CLS");
                del();
                break;
            case 8:
                system("CLS");
                sorting();
                break;
        }
    putchar('\n');
    goto loop;
}
