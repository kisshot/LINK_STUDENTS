//
// Created by LuFan on 2018/12/12.
//

#include "student.h"


void menu_Alter()
{
    printf("ADD NAME:\n");
    printf("ADD AGE:\n");
    printf("ADD NUMBER:\n");
    printf("ADD IPHONE:\n");
    printf("ADD SEX:\n");
}

void InitContact(Contact *p)
{
    printf("INIT\n");
}

void AddContact(Contact *p)
{
    printf("输入姓名:\n");
    scanf("%s", p->num[p->count].name);
    printf("年龄：\n");
    scanf("%s", p->num[p->count].age);
    printf("学号：\n");
    scanf("%s", p->num[p->count].number);
    printf("电话：\n");
    scanf("%s", p->num[p->count].iphone);
    printf("性别：\n");
    scanf("%s", p->num[p->count].sex);

    p->count++;  //非常重要的句子，没有这个语句输入就不会被存储

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
        printf("年龄：%s\n", p->num[result].age);
        printf("学号：%s\n", p->num[result].number);
        printf("电话：%s\n", p->num[result].iphone);
    }
    else
    {
        printf("你要查找的联系人不存在\n");
    }

}//定义查找函数，对应数字 2


void DelContact(Contact *p)
{
    char name[20] = {0};
    int result = 0;
    int if_del = 0;
    printf("请输入要删除人的姓名：\n");
    scanf("%s", name);
    result = Find_St(p, name);
    if (result != -1)
    {
        printf("你是否要删除该联系人？\n");
        printf("删除请按1，不删除请按0\n");
        scanf("%d", &if_del);
        if (if_del == 1)
        {
            int i = result;
            for (; i < (p->count)-1; i++)
            {
                p->num[i] = p->num[i + 1];
            }
            p->count --;
            printf("删除成功\n");
        }
        else
        {
            printf("删除失败\n");
        }
    }
    else
    {
        printf("你要删除的联系人不存在\n");
    }
}

void AlterContact(Contact *p)
{
    char name[20] = {0};
    int result = 0;
    printf("请输入你要修改联系人的姓名：\n");
    scanf("%s", name);
    result = Find_St(p, name);
    if (result != -1)
    {
        printf("姓名：%s\n", p->num[result].name);
        printf("性别：%s\n", p->num[result].sex);
        printf("年龄：%s\n", p->num[result].age);
        printf("电话：%s\n", p->num[result].iphone);
        printf("学号：%s\n", p->num[result].number);
        int i = 0;
        do
        {
            menu_Alter();
            printf("输入你要修改的选项：\n");
            scanf("%d", &i);
            switch (i)
            {
                case 1:
                    printf("请把姓名修改成：");
                    scanf("%s", p->num[result].name);
                    break;
                case 2:
                    printf("请把性别修改成：");
                    scanf("%s", p->num[result].sex);
                    break;
                case 3:
                    printf("请把年龄修改成：");
                    scanf("%s", p->num[result].age);
                    break;
                case 4:
                    printf("请把电话修改成：");
                    scanf("%s", p->num[result].iphone);
                    break;
                case 5:
                    printf("请把学号修改成：");
                    scanf("%s", p->num[result].number);
                    break;
                case 0:
                    break;
                default:
                    printf("输入错误");
                    break;
            }
        } while (i);
    }
    else
    {
        printf("你要修改的联系人不存在\n");
    }
}

void PrintContact(Contact *p)
{
    int i = 0;
    printf("输出所有人的信息：\n");
    printf("%10s%7s%6s%8s%10s\n","名字","性别","年龄","电话","住址");
    for (i = 0; i < (p->count); i++)
    {
        printf("%11s", p->num[i].name);
        printf("%11s", p->num[i].sex);
        printf("%11s", p->num[i].age);
        printf("%11s", p->num[i].iphone);
        printf("%11s", p->num[i].number);
        printf("\n");
    }

}

void EmptyContact(Contact *p)
{
    p->count = 0;
}

void SortContact(Contact *p)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < p->count - 1; i++)
        for (j = 0; j < p->count - 1 - i; j++)
        {
            if (strcmp(p->num[j].name, p->num[j + 1].name)>0)
            {
                struct STU tmp;
                tmp = p->num[j];
                p->num[j] = p->num[j + 1];
                p->num[j + 1] = tmp;
            }
        }

}


void SaveContact(Contact *p)
{
    FILE *fp = fopen("/Users/lufan/Documents/GitHub/LINK_STUDENTS/LINK_STUDENTS/Contact.txt","w");
    char num_save[100];

    if(fp == NULL)
    {
        printf("Cannot open the file.\n");
        //perror("error");
        exit(0);  /* 正常跳出程序 */
    }
    for(int i = 0; i < (p->count); i++)
    {
//        fwrite(&p->num[i], sizeof(struct STU), 1, fp);   //以二进制将结构体内容存入文件
        if(*p->num[i].name)
        {
            sprintf(num_save, "Num.%.2d",i+1);
            fwrite(num_save, 6, 1, fp);
            fwrite("\r\n", 2, 1, fp);
            fwrite(p->num[i].name, strlen(p->num[i].name), 1, fp);
            fwrite("\r\n", 2, 1, fp);
            fwrite(p->num[i].age, strlen(p->num[i].age), 1, fp); //sizeof(p->num[i].age),

            fwrite("\r\n", 2, 1, fp);
            fwrite(p->num[i].iphone, strlen(p->num[i].iphone), 1, fp);
            fwrite("\r\n", 2, 1, fp);
            fwrite(p->num[i].number, strlen(p->num[i].number), 1, fp);
            fwrite("\r\n", 2, 1, fp);
            fwrite(p->num[i].sex, strlen(p->num[i].sex), 1, fp);
            fwrite("\r\n", 2, 1, fp);

        }
    }

    fclose(fp);
}



