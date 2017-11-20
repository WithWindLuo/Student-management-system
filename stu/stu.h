#ifndef STU_H_INCLUDED
#define STU_H_INCLUDED
#endif // STU_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
void in(void);              //���뺯��
void out(void);             //�������
void change(void);          //�޸ĺ���
void table(void);           //����ɼ���
void del(void);             //ɾ������
void sorting(void);         //ѡ������ķ�ʽ����
void sorting1(void);        //ѧ��������
void sorting2(void);        //�ܷ�������
void debug(void);           //���Ժ���
void ranking(void);         //���κ���
int login(void);            //��¼����
int checkname(char ch[]);   //�����ظ���ѯ����
int checkxh(char ch[]);     //ѧ���ظ���ѯ����
int checkname2(char ch[]);
int checkxh2(char ch[]);
#define RECS 20             /*����ɴ�������ѧ����¼��20���ɰ�ʵ��ѧ���������޸�*/
#define SJTS 6              /*����ɴ���Ŀγ���6*/

typedef struct student       /*ѧ����¼������Ϣ*/
    {char xh[5];             /*ѧ��ѧ��*/
    char name[9];            /*ѧ������*/
    int score[SJTS];         /*6�ſγ̳ɼ�*/
    int sum;                 /*�ܷ�*/
    float ave;               /*ƽ����*/
    unsigned order;          /*����*/
    } STUDENT;

