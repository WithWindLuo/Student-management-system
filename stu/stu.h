#ifndef STU_H_INCLUDED
#define STU_H_INCLUDED
#endif // STU_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
void in(void);              //输入函数
void out(void);             //输出函数
void change(void);          //修改函数
void table(void);           //输出成绩表
void del(void);             //删除函数
void sorting(void);         //选择排序的方式函数
void sorting1(void);        //学号排序函数
void sorting2(void);        //总分排序函数
void debug(void);           //调试函数
void ranking(void);         //名次函数
int login(void);            //登录函数
int checkname(char ch[]);   //姓名重复查询函数
int checkxh(char ch[]);     //学号重复查询函数
int checkname2(char ch[]);
int checkxh2(char ch[]);
#define RECS 20             /*定义可处理的最大学生记录数20，可按实际学生数进行修改*/
#define SJTS 6              /*定义可处理的课程数6*/

typedef struct student       /*学生记录基本信息*/
    {char xh[5];             /*学生学号*/
    char name[9];            /*学生姓名*/
    int score[SJTS];         /*6门课程成绩*/
    int sum;                 /*总分*/
    float ave;               /*平均分*/
    unsigned order;          /*名次*/
    } STUDENT;

