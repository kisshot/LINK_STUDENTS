//
// Created by LuFan on 2018/12/12.
//

#include "student.h"


void menu_Add()
{
    printf("ADD\n");
}

void InitContact(Contact *p)
{
    printf("INIT\n");
}

void AddContact(Contact *p)
{
    menu_Add();
} //定义添加函数,对应数字 1

int Find_St(Contact *p, char *pname)//对于一个联系人是否存在封装一个函数，在后面的修改、删除、查找可以用到
{
    int i = 0;
    for (i = 0; i < (p->count); i++)
    {
        if (strcmp(p->num[i].name, pname) == 0)
            return i;

    }
    return -1;
}

void FindContact(Contact *p)
{
    printf("FIND\n");

    char name[20] = { 0 };
    int result = 0;
    printf("请输入要查找联系人的姓名：\n");
    scanf("%s", name);
    result = Find_St(p, name);      //result即Find_St函数返回值i, 对应数组中的位置
    if (result != -1)
    {
        printf("姓名：%s\n", p->num[result].name);
        printf("性别：%s\n", p->num[result].sex);
        printf("年龄：%d\n", p->num[result].age);
        printf("电话：%d\n", p->num[result].number);
        printf("地址：%d\n", p->num[result].iphone);
    }
    else
    {
        printf("你要查找的联系人不存在\n");
    }

}//定义查找函数，对应数字 2


