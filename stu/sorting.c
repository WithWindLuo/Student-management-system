#include"stu.h"
void sorting(void)
{
    int n;
    printf("��������ѧ����Ϣ:\n");
    printf("��ѡ������ķ�ʽ:\n");
    printf("1.��ѧ�Ž�������       2.���ֽܷ�������\n");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
            sorting1();
            break;
        case 2:
            sorting2();
            break;
        default:
            break;
    }
    return ;
}
