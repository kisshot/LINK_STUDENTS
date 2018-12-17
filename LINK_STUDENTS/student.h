//
// Created by LuFan on 2018/12/12.
//

#ifndef LINK_STUDENTS_STUDENT_H
#define LINK_STUDENTS_STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

//typedef struct
//{
//    char name[20];
//    int age;
//    int number;
//    int iphone;
//    char sex[20];
//} Student; //定义每个学生的结构体

struct STU
{
    char name[20];
    //int age;
    char age[20];
    //int number;
    char number[20];
    //int iphone;
    char iphone[20];
    char sex[20];
};

typedef struct CONTACT
{
    struct STU num[MAX];
    int count;
}Contact;

//typedef struct
//{
//    Student num[MAX];
//    int count;
//} Contact; //这个通讯录可以包含1000个学生

void InitContact(Contact *p); //定义初始化函数，操作对象为Contact/即该通讯录，使用指针来对通讯录中的对象进行修改
void AddContact(Contact *p); //定义添加函数,对应数字 1
void FindContact(Contact *p); //定义查找函数，对应数字 2
void DelContact(Contact *p); //定义删除函数，对应数字 3
void AlterContact(Contact *p); //定义修改函数，对应数字 4
void PrintContact(Contact *p); //定义打印函数，对应数字 5
void EmptyContact(Contact *p); //定义清空函数，对应数字 6
void SortContact(Contact *p); //定义排序函数，对应数字 7
void SaveContact(Contact *p); //定义保存函数，对应数字 8

#endif //LINK_STUDENTS_STUDENT_H
